//========================================================
// CS 271
// Fall 2025
// HashTable.h
// This file contains the HashTable class declaration.
//========================================================

#include "Element.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

template <class T> class HashTable {
public:
  HashTable(void);
  HashTable(int size);
  ~HashTable(void);
  void insert(T data, int k);
  void insert(T data, string digest);
  void remove(T data, int k);
  bool member(T data, int k);
  bool member(T data, string password);
  std::string to_string(void);
  int get_highest_load(void);

private:
  int m; // size of hash table

  list<Element<T>> *arr; // hash table built on an array

  int default_hash_func(int key);
  int p; // The count of significant bits to take for the MSBM
};

#include "HashTable.cpp"

#endif
