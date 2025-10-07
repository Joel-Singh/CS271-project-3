#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
using namespace std;

template <typename T> class HashTable {
public:
  // Not sure what the constructor parameter is actually supposed to be
  HashTable<T>(int size);
  void insert(T data, int key);
  void remove(T data, int key);
  bool member(T data, int key);
  string to_string();
};

#include "HashTable.cpp"
#endif
