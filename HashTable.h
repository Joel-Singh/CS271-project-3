//========================================================
// CS 271
// Fall 2025
// HashTable.h
// This file contains the HashTable class declaration.  
//========================================================

#include <iostream>
#include <string>
#include "Element.h"
#include <list>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

template<class T>
class HashTable{
    public:
                            HashTable           ( void );
                            HashTable           ( int size );
                            ~HashTable          ( void );
        void                insert              (T data, int k);
        void                insert              (T data, string digest);
        void                remove              (T data, int k);
        bool                member              (T data, int k);
        bool                member              (T data, string password);
        std::string         to_string           ( void ); 
    private:
        int m; //size of hash table

        list<Element<T>> *arr; //hash table built on an array

        int             default_hash_func        ( int key );

};

#include "HashTable.cpp"

#endif
