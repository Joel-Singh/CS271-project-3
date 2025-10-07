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

template<class T>
class Element{
    public:
                                Element         ( void );
                                Element         (T d, int k);
                                ~Element        ( void );
        Element<T>              operator=       ( const Element<T> &e);
        int                     get_key         ( void ) const;
        T                       get_data        ( void ) const;
        void                    set_data         ( T d);
        std::string             to_string       ( void ) const; 
    private:
        int key;
        T data;
};


#include "Element.cpp"

#endif
