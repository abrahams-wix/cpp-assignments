//Eliyahu Masinter - 663168114
//Avi Soclof - 674098915
//HW 1 - Lists
//Data Structures 2

#include "TreeList.hpp"
#include <iostream>
using namespace std;




void TreeList::addNewTree(string val) {
    Tree tree(val); //create a new tree with root content = val
    trees.push_front(tree); //add the tree to our list of trees
}

bool TreeList::addResponse(string root, string respond, string content) {
    Tree tree;
    for (list<Tree>::iterator it = trees.begin(); it != trees.end(); ++it) {
        if ((*it).getRoot()->content == root) {
            tree = *it;
            break;
        }
    } // find the correct tree

    if (tree.getRoot()) { //if the tree exists
        return tree.addNode(respond, content); //bool function that will return true if the node was added correctly
    }
    return false;
}

bool TreeList::delResponse(string root, string val) {
    Tree tree;
    for (list<Tree>::iterator it = trees.begin(); it != trees.end(); ++it) {
        if ((*it).getRoot()->content == root) {
            tree = *it;
            break;
        }
    } //find the correct tree
    if (tree.root == NULL)
		return false;
    if (tree.getRoot()->content == val) {//if the val corresponds to a root
        for (list<Tree>::iterator it = trees.begin(); it != trees.end(); ++it) {
            if ((*it).getRoot() == tree.getRoot()) {
                trees.erase(it); //we've idetntified the correct tree
                break;
            }
        }
    }
    if (tree.getRoot()) { //if val is not a root then call the deleteSubTree on that tree
        return tree.deleteSubTree(val);
    }
    return false;
}

void TreeList::printAllTrees() {
    int count = 1;
    for (list<Tree>::iterator it = trees.begin(); it != trees.end(); ++it) { //iterate over all trees and call the print function on it
        cout << "Tree #" << count << endl;
        ++count; 
        (*it).print();
    }
}

void TreeList::printSubTree(string root, string val) {
    Tree tree;
    for (list<Tree>::iterator it = trees.begin(); it != trees.end(); ++it) {
        if ((*it).getRoot()->content == root) { //find the tree
            tree = *it;
            break;
        }
    }
    
    if (!tree.getRoot()){
        return; 
    }
    Tree::Node* node = tree.find(val); //find the node in that tree
    if (!node){
        return; 
    }
    tree.print(*node, 0); //print the subtree of that node
    tree.printPath(val);
}


void TreeList::searchAndPrint(string val) {
    Tree tree;
    for (list<Tree>::iterator it = trees.begin(); it != trees.end(); ++it) {
        tree = *it;
        Tree::Node* node = (*it).find(val); //try and find the node in each tree
        if (node) { //if we find it, we print the path to it and print the subtree from that node
            
            tree.print(*node, 0);
            tree.printPath(val);
        }
    }
}