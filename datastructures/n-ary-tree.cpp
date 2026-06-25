//Eliyahu Masinter - 663168114
//Avi Soclof - 674098915
//HW 1 - Lists
//Data Structures 2


#include <iostream>
#include <string>
#include <stack>
#include "tree.hpp"
using namespace std;


//Constructors
Tree::Tree() {
	root = nullptr;
}

Tree::Tree(string val) {
	Tree::Node* node = new Tree::Node(val);
	root = node;
}



//functinos
void Tree::setRoot(string content) {
	Tree::Node* node = new Tree::Node(content);
	if (root == nullptr) {
		root = node;
	}
	else {
		deleteSubTree(root); //if the root has already been set, delete that root and set the new root
		root = node;
	}
}

//wrapper function for find
Tree::Node* Tree::find(string query) { 
	return find(*root, query);
}

Tree::Node* Tree::find(Tree::Node& node, string query) {

	Node* res = NULL;
	if (node.content == query) {
		return &node; //return the actual node
	}
	for (list<Node>::iterator it = node.responses.begin(); it != node.responses.end(); ++it) { //if there are multiple nodes of same value, it will return the first
		res = find(*it, query);
		if (res)
			return res;
	}
	return res;
}

bool Tree::addNode(string fatherString, string childString) { //bool function to tell us whether function was able to add node properly
	Tree::Node* fatherNode = find(fatherString);
	if (fatherNode) {
		Tree::Node childNode(childString);
		fatherNode->responses.push_back(childNode);
		return true;
	}
	return false;

}

bool Tree::deleteSubTree(string content) {//wrapper function
	Node* node = find(content);
	if (node && node!=root) //if the node is the root, we delete the whole tree. This is called from the TreeList class though.
		return deleteSubTree(node);
	return true; 
}

bool Tree::deleteSubTree(Tree::Node* node) { //bool to tell us whether it was deleted successfully 
	Tree::Node* father = findFather(node, root);
	for (list<Tree::Node>::iterator it = father->responses.begin(); it != father->responses.end(); ++it)
		if ((*it).content == node->content) {
			father->responses.erase(it);
			return true;
		}
	return false;
}

void Tree::print() {//wrapper for print
	print(*root, 0);
}
void Tree::print(Tree::Node node, int counter) {
	for (int i = 0; i < counter; ++i)//print 3*counter spaces
		cout << "   "; //three spaces
	cout << node.content << endl;
	if (node.responses.size() > 0) { // if the node has children
		for (list<Tree::Node>::iterator it = node.responses.begin(); it != node.responses.end(); ++it) //for each node child
			print(*it, counter+1);
	}
}

//Tree::Node* Tree::findFather(Tree::Node* child) {
//	if (child == root) { //root has no father
//		return nullptr;
//	}
//	if (root->responses.size() > 0)
//		return findFather(val, *root);
//}

Tree::Node* Tree::findFather(Tree::Node* child, Tree::Node* father) {

	Tree::Node* parent = nullptr;

	if (child == root) { //root has no father
		return parent;
	}

	if (find(child->content)) {
		if (father->responses.size() > 0) {
			for (list<Node>::iterator it = father->responses.begin(); it != father->responses.end(); ++it) {
				if ((*it).content == child->content) {
					return father;
				}
				if ((*it).responses.size() > 0) //recursively search through all nodes until we find the father
					parent = findFather(child, &(*it));
			}
		}
	}
	return parent;
}

void Tree::printPath(string val) {
	Node* node = find(val); //get a pointer to the node with content val
	Node* father = findFather(node, root); //get the father
	cout << node->content;
	if (!father){
	    return; 
	}
	else {//father will be NULL if val is the root
	    cout << "=>" << father->content; 

	while (father != root) { //move up the tree by calling the findFather function on the node until that node is the root
		father = findFather(father, root);
		cout << "=>" << father->content; 
}
}
cout << endl; 
}