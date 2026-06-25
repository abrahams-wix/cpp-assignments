//
//  HashTable.hpp
//  DS_HW_TWO
//
//  Created by Avi Soclof on 11/19/22.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <iostream>
#include <string>
using namespace std;


template <typename T, typename K>
class HashTable
{
protected:

    enum state { empty, full, deleted };
    template <typename U, typename V>
    class Item
    {
    public:
        U data;
        V key;
        state flag;
        Item() { flag = empty;  }
        Item(U d, V  k, state f) { data = d; key = k; flag = f; }
    };


    int size;
    Item<T, K>* arr;
    bool prime(int n);
    int nextPrime(int n);
    int hash(K key, int i);
    virtual int h1(K key) = 0;
    virtual int h2(K key) = 0;

public:

    HashTable(int m = 10);
    ~HashTable();
    void insert(K key, T dat);
    void remove(K key);
    int search(K key);
    T* entryData(K i)
    {
        int ind = search(i);
        if (ind == -1)
            return NULL;
        else
            return &(arr[ind].data);
    }
    void print();
};

//Evaluates if number is prime
template <typename T, typename K>
bool HashTable<T, K>::prime(int n) {

    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

//Returns the next prime value
template <typename T, typename K>
int HashTable<T, K>::nextPrime(int n) {
    bool found = false;
    if (!(prime(n))) {
        do {
            if (prime(n + 1)) {
                found = true;
            }
            n += 1;
        } while (!found);
    }
    return n;
}

template <typename T, typename K>
HashTable<T, K>::HashTable(int n) {
    int prime = nextPrime(n);
    size = prime;
    arr = new Item<T, K>[size];
    for (int i = 0; i < size; i++) {
        arr[i].flag = empty;
    }
    

}

template <typename T, typename K>
HashTable<T, K>::~HashTable() {
    delete[] arr;
}

template <typename T, typename K>
int HashTable<T, K>::hash(K key, int i) {

    int k = h1(key);
    int step = h2(key);
    int address = (k + (step * i)) % size;
    return address;
}

template <typename T, typename K>
int HashTable<T, K>::search(K key) {
    int i = 0;
    int address = hash(key, i);
    if (arr[address].flag != full)
        return -1;

    if (arr[address].key == key) {
        return address;
    }

    while (arr[address].flag != empty && i < size) {
        if (arr[address].key == key) {
            if (arr[address].flag == deleted) {
                return -1;
            }
            return address;
        }
        i += 1;
        address = hash(key, i);
    }


    return -1;
}


template <typename T, typename K>
void HashTable<T, K>::insert(K key, T dat) {
    int i = 0;
    int address = hash(key, i);
    if (arr[address].flag != full) {
        arr[address].key = key;
        arr[address].data = dat;
        arr[address].flag = full;
    }
    else {
        while ((arr[address].flag == full) && i < size) {
            i += 1;
            address = hash(key, i);
        }
        if (arr[address].flag == empty || arr[address].flag == deleted) {
            arr[address].key = key;
            arr[address].data = dat;
            arr[address].flag = full;
        }
    }
}


template <typename T, typename K>
void HashTable<T, K>::remove(K key) {

    int address = search(key);

    if (address == -1) {
        //cout << "NOT FOUND" << endl;
        return;
    }

    arr[address].flag = deleted;
   

}
#endif /* HashTable_hpp */
