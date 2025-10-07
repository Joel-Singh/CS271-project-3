//========================================================
// CS 271
// Fall 2025
// HashTable.h
// This file contains the HashTable class declaration.  
//========================================================

#include <iostream>
#include <string>
#include "Element.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

template<class T>
class HashTable{
    public:
                            HashTable           ( void );
                            HashTable           ( int size );
                            ~HashTable          ( void );
        void                insert              (T data, int k);
        void                remove              (T data, int k);
        bool                member              (T data, int k);
        std::string         to_string           ( void ); 
    private:
        int m; //size of hash table

        T *arr; //hash table built on an array

        int             default_HashFunc        ( int key );
        bool            verifyIndex             (int index);

};

#include "HashTable.cpp"

#endif
