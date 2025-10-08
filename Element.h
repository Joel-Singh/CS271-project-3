//========================================================
// CS 271
// Fall 2025
// Element.h
// This file contains the Element class declaration.  
//========================================================

#include <iostream>
#include <string>

#ifndef ELEMENT_H
#define ELEMENT_H

using namespace std;

template<class T>
class Element{
    public:
                                Element         ( void );
                                Element         (T d, int k);
                                Element         (T d, int k, string digest);
                                ~Element        ( void );
        Element<T>              operator=       ( const Element<T> &e);
        int                     get_key         ( void ) const;
        T                       get_data        ( void ) const;
        string                  get_digest      ( void ) const;
        void                    set_data         ( T d);
        std::string             to_string       ( void ) const; 
    private:
        int key;
        T data;
        string digest;
};


#include "Element.cpp"

#endif
