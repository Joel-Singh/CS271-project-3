/*
====================================================
Project 3: Smushed Universes (Hash Table Implementaion)
Written by: Nana K. Amo-Mensah and Joel Singh
Date Updated: 10.07.2025
Description: Implementation of a templated
Element Class
Program functionality: Passes all test cases
=====================================================
*/

#include <iostream>
#include <sstream>
#include "Element.h"


/*
================================================
Default Constructor
Creates an empty element. 
    Data value is set equal to zero
    Key becomes -1.
Call: Element<T> e;
Return: none. element object is constructed 
================================================
*/
template<typename T>
    Element<T>:: Element ( void ){
        key = -1;
}

/*
=====================================================
Constructor
Creates an element using the passed in data values.
    The key is always going to be a numeric value. 
    The actual data can be of any type.
Pre: Element<T> e(T data, int key);
Post: Element is constructed.
======================================================
*/
template<typename T>
    Element<T>:: Element ( T d, int k ){
        key = k;
        data = d; 
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
    Element<T>:: ~Element ( void ){
}

/*
================================================
operator=
Copies the values of the passed-in object 
and returns a reference to the modified element/
Call: elemObjt1 = elemObjct2
Return: type(*this) --> Element<T>
================================================
*/
template<typename T>
    Element<T> Element<T>:: operator= ( const Element<T> &e){
        data = e.data;
        key = e.key;
        return (*this);
}


/*
================================================
get_key()
Returns the key of the element object.
Call: elemObject.get_key().
Return: type(key) --> it
================================================
*/
template<typename T>
    int Element<T>:: get_key ( void ) const {
        return key;
}


/*
================================================
get_data()
Returns the data of the element object.
Call: elemObject.get_data().
Return: type(key) --> any
================================================
*/
template<typename T>
    T Element<T>:: get_data ( void ) const {
        return data;
}

/*
================================================
set_data()
Modifies the data of an element object.
Call: elemObject.set_data( T d ).
Return: none.
================================================
*/
template<typename T>
    void Element<T>:: set_data ( T d ){
        data = d;
}

/*
================================================
to_string()
Returns a string representation of the element 
object
Call: elemObject.to_string().
Return: type(retVal) --> String
================================================
*/
template<typename T>
    std::string Element<T>:: to_string (  void ) const {
        std::stringstream retVal;
        retVal << "("<< get_data()<< ","<<get_key()<<")"; 
        return retVal.str();
}
