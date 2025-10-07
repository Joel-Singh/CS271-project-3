/*
====================================================
Project 3: Smushed Universes (Hash Table Implementaion)
Written by: Nana K. Amo-Mensah and Joel Singh
Date Updated: 10.07.2025
Description: Implementation of a templated
Hash Table Class
Program functionality: In Progress
=====================================================
*/

#include <iostream>
#include <sstream>
#include "Element.h"
#include "HashTable.h"
#include <cassert>

using namespace std;

/*
================================================
Default Constructor
Creates a hash table object with a default size
of 10.
Call: HashTable<T> ht;
Return: none. hash table object is constructed 
================================================
*/
template<typename T>
    HashTable<T>::HashTable ( void ) : HashTable(10) {
}

/*
================================================
Constructor
Creates a hash table object using the passed-in
size
Call: HashTable<T> ht(int size);
Return: none. hash table object is constructed 
================================================
*/
template<typename T>
    HashTable<T>::HashTable (int size){
        m = size;
        arr = new list<Element<T>>[m];

        for (int i = 0; i < m; i++) {
            arr[i] = {};
        }
}

/*
================================================
Destructor
Destroys object when it goes out of scope or at
the end of the program.
Call: done automatically
Return: deallocates memory
================================================
*/
template<typename T>
    HashTable<T>::~HashTable ( void ){
}

/*
================================================
default_HashFunc
Function to transform a key into a valid index. 
    Divides the key by the number of hash table 
    slots and takes the remainder.
Pre: A numeric key (int) is received
Post: A valid index within the structure is 
returned
================================================
*/
template<typename T>
    int HashTable<T>:: default_hash_func ( int key ){
        assert(m != 0);
        return (key % m);
}


/*
================================================
remove
Removes the data at key k if it exists, otherwise leave the hashmap unmodified
Call: remove (T data, int k )
Return: None
================================================
*/
template<typename T>
void HashTable<T>:: remove (T data, int k ){
    if (m == 0) {
        return;
    }
    int index = default_hash_func(k);
    bool found = false;
    int i = 0; 

    for (auto node = arr[index].begin(); node != arr[index].end(); ++node) {
        if ((*node).get_data() == data) {
            arr[index].erase(node);
            break;
        }
    }
}


template<typename T>
void HashTable<T>::insert(T data, int k) {
    if (m == 0) {
        return;
    }
    Element<T> new_element(data, k);
    int hashed_index = default_hash_func(k);

    arr[hashed_index].push_front(new_element);
}

template<typename T>
bool HashTable<T>::member(T data, int k) {
    if (m == 0) {
        return false;
    }
    int index = default_hash_func(k);
    for (auto node = arr[index].begin(); node != arr[index].end(); ++node) {
        if ((*node).get_data() == data) {
            return true;
        }
    }

    return false;
}

template<typename T>
string HashTable<T>::to_string() {
    string ret;
    for (int i = 0; i < m; i++) {
        ret += std::to_string(i) + ": ";

        if (arr[i].size() > 0) {
            for (Element<T> elem : arr[i]) {
                ret += elem.to_string() + " ";
            }
        }

        ret += "\n";
    }

    return ret;
}
