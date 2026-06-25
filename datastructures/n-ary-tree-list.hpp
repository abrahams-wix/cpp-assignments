//Eliyahu Masinter - 663168114
//Avi Soclof - 674098915
//HW 1 - Lists
//Data Structures 2

#ifndef TreeList_hpp
#define TreeList_hpp

#include <stdio.h>

#include "tree.hpp"
#include <list>
using namespace std;

class TreeList {
private:
    list<Tree> trees;

public:
    TreeList() {}
    ~TreeList() { trees.clear(); }
    void addNewTree(string val);
    bool addResponse(string root, string respond, string content); //returns false if fail to add response
    bool delResponse(string title, string val);
    void printAllTrees();
    void printSubTree(string root, string val);
    void searchAndPrint(string val); //For every occurrence found, print the path from the root of the tree to the located node, and the complete subtree of the sub-discussion starting from the located node (if in a given tree the string occurs more than once, the method does this only for the first node that occurs in every tree)


};


#endif /* TreeList_hpp */