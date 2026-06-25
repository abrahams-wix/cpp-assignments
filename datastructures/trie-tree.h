//Eliyahu Masinter - 663168114
//Avi Soclof - 674098915
//HW 3
//Data Structures 2

#pragma once
// C++ program to demonstrate auto-complete feature 
// using Trie data ure. 
#include <iostream>
#include <string>
using namespace std;

// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 

// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
#define INDEX_TO_CHAR(i) (char)((int)i + (int)'a') 



class Trie
{
private:
    class TrieNode {
    public:
        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < ALPHABET_SIZE; i++)
                children[i] = NULL;
        }
        TrieNode* children[ALPHABET_SIZE];
        bool isEndOfWord;
    };
    Trie::TrieNode* root;

public:
    Trie() { root = new TrieNode(); }
    bool foundSuggestion = false;
    bool deleted = false;
	bool insert(string wrd) { return insert(root, wrd); }
    bool insert(Trie::TrieNode* node, string wrd);

    bool remove(string wrd) { 
        remove(root, wrd); 
        if (!foundSuggestion) {
            return false; 
        }
        else {
            foundSuggestion = false;
            return true; 
        }
    }
    TrieNode* remove(Trie::TrieNode* node, string wrd, int index=0);

	int printAutoSuggestions(string wrd) { return printAutoSuggestions(root, wrd); }
    int printAutoSuggestions(Trie::TrieNode* node, string wrd);

	bool search(string key) { return search(root, key); }
    bool search(Trie::TrieNode* node, string wrd);

	void print() { print(root, 0); }
    void print(Trie::TrieNode*, int);

    bool isEmpty(Trie::TrieNode* root);
    void getEndings(Trie::TrieNode*, string);

};
