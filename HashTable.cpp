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

#include "HashTable.h"
#include "Element.h"
#include "choose_hash_method.cpp"
#include "encryption.cpp"
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

//=================================================
// Default Constructor
// Creates a hash table object with a default size
// of 10.
//=================================================
template <typename T> HashTable<T>::HashTable(void) : HashTable(10) {}

//=================================================
// Constructor
// Creates a hash table object using the passed-in
// size
//
// PARAMETERS:
//  size: Size of the hashtable
//=================================================
template <typename T> HashTable<T>::HashTable(int size) {
  p = floor(log2(m)) + 1;
  if (size < 0) {
    throw runtime_error("");
  }
  m = size;
  arr = new list<Element<T>>[m];
}

//=================================================
// Destructor
// Cleans up allocated member array.
//=================================================
template <typename T> HashTable<T>::~HashTable(void) { delete[] arr; }

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
//=================================================
// default_hash_func
// Function to transform a key into a index of the member array. Uses a hash
// method dependent on defined macro variables in `./choose_hash_method.cpp`
//
// PARAMETERS:
//  key: The key to input into the hash function
//
// RETURN VALUE:
//  The corresponding index for that key using the hash function.
//=================================================
template <typename T> int HashTable<T>::default_hash_func(int key) {
  assert(m != 0);

#ifdef USE_K_MOD_M
  return (key % m);
#endif

#ifdef USE_CORMEN
  double A = (sqrt(5.0) - 1.0) / 2.0;
  double kA = A * key;
  double fractional_part = kA - floor(kA);
  return floor((double)m * fractional_part);
#endif

#ifdef USE_MSBM
  assert(sizeof(int) == 4);
  return (key >> (32 - p)) % m;
#endif
}

//=================================================
// remove
// Removes the element at key k if it exists, otherwise leaves the hashmap
// unmodified
//
// PARAMETERS:
//  data: The data of the element
//  k: The key of the element
//=================================================
template <typename T> void HashTable<T>::remove(T data, int k) {
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

//=================================================
// insert
// Adds a new data node to the HashMap.
//     If the size of the HashMap is zero, the structure
//     is left unmodified.
//     Otherwise:
//     1. It creates an element object using the received values
//     2. Computes the index using the key
//     3. Appends the object to the linked at that index
//
// PARAMETERS:
//  data: The data of the element
//  k: The key of the element
//=================================================
template <typename T> void HashTable<T>::insert(T data, int k) {
  if (m == 0) {
    return;
  } else if (k < 0) {
    throw runtime_error("");
  }
  Element<T> new_element(data, k);
  int hashed_index = default_hash_func(k);

  arr[hashed_index].push_front(new_element);
}

//=================================================
// insert
// Alternative insert function that also attaches a digest to the element with
// its key being the truncated int of the digest
//
// PARAMETERS:
//  data: The data for the new element
//  digest: The digest to attach
//=================================================
template <typename T> void HashTable<T>::insert(T data, string digest) {
  if (m == 0) {
    return;
  }

  int k = truncate_digest_to_int(digest);

  Element<T> new_element(data, k, digest);
  int hashed_index = default_hash_func(k);

  arr[hashed_index].push_front(new_element);
}

/*
=========================================================
member
This function determines whether a given data value
and key are present within a HashTable.
    If the table is empty, false is returned.
    Otherwise, the function iterates through the structure,
    beginning at the computed index and aims to match the
    received data with the contents of the HashTable.
    If found, returns True. Else, false.
Pre: Function is used with HashTable object
Post: Returns T/F depending on if data and key
are found in the HashTable.
=========================================================
*/

//=================================================
// member
// This function determines whether a given data value
// and key are present within a HashTable.
//     If the table is empty, false is returned.
//     Otherwise, the function iterates through the structure,
//     beginning at the computed index and aims to match the
//     received data with the contents of the HashTable.
//     If found, returns True. Else, false.
//
// PARAMETERS:
//  data: The data of the element
//  k: The key of the element
//
// RETURN VALUE:
//  Bool indicating whether the data and key pair is in the hashtable.
//=================================================
template <typename T> bool HashTable<T>::member(T data, int k) {
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

//=================================================
// member
// Determines if the hashtable has a member with data and the password
//
// PARAMETERS:
//  data: Data of the member to find
//  password: Password of the member
//
// RETURN VALUE:
//  Bool indicating whether the hashed password and key pair is in the
//  hashtable.
//=================================================
template <typename T> bool HashTable<T>::member(T data, string password) {
  if (m == 0) {
    return false;
  }

  string digest = encrypt(password);

  int index = truncate_digest_to_int(digest);
  index = default_hash_func(index);

  for (auto node = arr[index].begin(); node != arr[index].end(); ++node) {
    if ((*node).get_digest() == digest) {
      return true;
    }
  }

  return false;
}

//=================================================
// to_string
// This function returns a string of the contents
// of a HashTable object. Ideally used when a user
// wants to print the object onto a console.
//
// RETURN VALUE:
//  A string representation of the hashtable.
//=================================================
template <typename T> string HashTable<T>::to_string() {
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

//=================================================
// get_highest_load
// Gets the list with the highest number of elements in it. Used for testing the
// load for the analysis.
//
// RETURN VALUE:
//  The length of the biggest list in the member array
//=================================================
template <typename T> int HashTable<T>::get_highest_load() {
  int highest = arr[0].size();
  for (int i = 1; i < m; i++) {
    int size = arr[i].size();
    if (size > highest) {
      highest = size;
    }
  }

  return highest - 1;
}
