//Eliyahu Masinter - 663168114
//Avi Soclof - 674098915
//HW 3
//Data Structures 2

#include "Trie.h"

bool Trie::insert(Trie::TrieNode* root, string key)
{
    Trie::TrieNode* tempNode = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = CHAR_TO_INDEX(key[i]);
        if (!tempNode->children[index])
            tempNode->children[index] = new Trie::TrieNode();

        tempNode = tempNode->children[index];
    }

    tempNode->isEndOfWord = true;
    return true;
}

bool Trie::search(Trie::TrieNode* root, string key)
{
    TrieNode* tempNode = root;
    for (int i = 0; i < key.length(); i++) {
        int index = CHAR_TO_INDEX(key[i]);
        if (!tempNode->children[index])
            return false;

        tempNode = tempNode->children[index];
    }

    return (tempNode->isEndOfWord);
}

Trie::TrieNode* Trie::remove(Trie::TrieNode* root, string key, int counter) {
    if (!root) {
        return NULL;
    }

    if (counter == key.size()) {
        if (root->isEndOfWord) {
            foundSuggestion = true;
            root->isEndOfWord = false;
        }


        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }

        return root;
    }


    int index = CHAR_TO_INDEX(key[counter]);
    root->children[index] = remove(root->children[index], key, counter + 1);


    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = NULL;
    }

    return root;
}

void Trie::print(Trie::TrieNode* root, int index) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            for (int i = 0; i < index; i++)
                cout << "   ";
            cout << INDEX_TO_CHAR(i) << ":" << endl;
            print(root->children[i], index + 1);
        }
    }
}



void Trie::getEndings(Trie::TrieNode* root, string currPrefix)
{

    if (root->isEndOfWord) {
        cout << currPrefix << endl;
        foundSuggestion = true;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) {
            char child = 'a' + i;
            getEndings(root->children[i],
                currPrefix + child);
        }
}

int Trie::printAutoSuggestions(Trie::TrieNode* node, string wrd) {
    int counter = 0;
    Trie::TrieNode* tempNode = node;
    for (int i = 0; i < wrd.length(); i++) {
        int index = CHAR_TO_INDEX(wrd[i]);
        if (!tempNode->children[index])
            return 0;
        tempNode = tempNode->children[index];
    }
    //at this point tempNode should be up to the correct character
    getEndings(tempNode, wrd);

    if (foundSuggestion) {
        foundSuggestion = false;
        return 1;
    }
    return 0;

}


bool Trie::isEmpty(Trie::TrieNode* root)
{

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

