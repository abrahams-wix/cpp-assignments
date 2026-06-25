//
//  HSubject.hpp
//  DS_HW_TWO
//
//  Created by Avi Soclof on 11/19/22.
//

#ifndef HSubject_hpp
#define HSubject_hpp


#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "HashTable.hpp"
using namespace std;


const int MAX = 1000;

class HSubject :public HashTable<list<string>, string>
{
    //private:
    int key(string s) { return (int)s[0] + (int)s[1] + (int)s[s.length() - 1]; }

public:

    HSubject(int n) :HashTable <list<string>, string>(n) {}
    int h1(string s) { return key(s) % size; }
    int h2(string s) { return (key(s) % (size - 1) + 1) % size; }
    void printS(string key) {
        int address = search(key);
        if (address == -1) {
            cout << "ERROR" << endl;
            return;
        }
        list<string> List = arr[address].data;
        cout << "Subject " << key << " " << List.size() << " topics" << endl;
        for (auto const& item : List) {
            cout << item << " ";
        }


    }
    void printN(string key, int N) {
        int address = search(key);
        if (address == -1) {
            cout << "ERROR" << endl;
            return;
        }
        list<string> List = arr[address].data;
        int counter = 0;
        for (auto const& item : List) {
            if (counter >= N)
                return;
            cout << item << endl;
            counter++;
        }

    }
    void print() {
        vector<string> keys;
        for (int i = 0; i < size; i++) {
            if (arr[i].flag == full) {
                keys.push_back(arr[i].key);
            }
        }
        sort(keys.begin(), keys.end(), [](string& a, string& b) {
            return a < b;
            }
        );

        cout << "All subjects and titles:" << endl;
        for (auto const& i : keys) {
            cout << i << ": ";
            int address = search(i);
            if (address == -1) {
                cout << "ERROR" << endl;
                return;
            }
            list<string> List = arr[address].data;
            for (auto const& item : List) {
                cout << item << " ";
            }
            cout << endl;
        }
    }
    void startNewTable() {
        for (int i = 0; i < size;i++) {
            if (arr[i].flag != empty) {
                arr[i].data.clear();
                arr[i].flag = empty;
            }
        }
    }
    void addSubjectAndTitle(string key, string discussion) {
        int address = search(key);

        if (address == -1) {
            list<string> l;
            l.push_back(discussion);
            insert(key, l);
            return;
        }
        arr[address].data.push_front(discussion);
    }
};

#endif /* HSubject_hpp */
