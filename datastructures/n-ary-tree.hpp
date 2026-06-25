//Eliyahu Masinter - 663168114
//Avi Soclof - 674098915
//HW 1 - Lists
//Data Structures 2

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
#include <string>
#include <list>
using namespace std;

class Tree {
    
protected:
    class Node {
    public:
        string content;
        list<Node> responses;
        Node(string _content) {
            content = _content;
        }
        ~Node() {
            responses.clear(); //since it's a list, the list has it's own destructor which will call the destructor for each node
        }
    };

    Tree::Node* root;
public:
	Tree();
	Tree(string val);
	void setRoot(string content);
	Tree::Node* getRoot() { return root; }
	Tree::Node* find(Tree::Node &node, string query);
	Tree::Node* find(string query);
	bool addNode(string father, string child);
	bool deleteSubTree(string query);
	bool deleteSubTree(Tree::Node* node);
	void print(); //this will print the whole tree, starting from root (basically calls the other print function with paramters (root,0)
	void print(Tree::Node node, int counter); // the counter is to determine how many spaces it prints, this is a recursive function where each next call is to counter+1
	void printPath(string query);
	Tree::Node* findFather(Tree::Node* child, Tree::Node* father);
	friend class TreeList; //gives TreeList access to Node
};





#endif /* tree_hpp */