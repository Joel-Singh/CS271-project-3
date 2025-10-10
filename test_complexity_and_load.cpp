/*
====================================================
Project 3: Smushed Universes (Hash Table Implementaion)
Written by: Nana K. Amo-Mensah and Joel Singh
Date Updated: 10.07.2025
Description: Testing the time complexity of these
three hash functions:
    1. Default --> k mod m
    2. Cormen --> floor( m (kA mod 1))
    3. MSBP --> (ka mod 2^w) >>= (w - l)
=====================================================
*/

#include "Element.h"
#include "HashTable.h"
#include "choose_hash_method.cpp"
#include <iostream>

#include <chrono>

using namespace std;

HashTable<int> create_randomized_hashtable(int size, int element_count);

//=================================================
// Macro: TIME_TEST
// Prints the amount of time it takes to do `call`
//
// PARAMETERS:
//  call: The code to test
//  description: Description to print out with the time
//=================================================
#define TIME_TEST(call, description)                                           \
  auto begin = chrono::high_resolution_clock::now();                           \
                                                                               \
  call;                                                                        \
                                                                               \
  auto end = chrono::high_resolution_clock::now();                             \
  auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);      \
  cout << description << " took " << elapsed.count() << " nanoseconds" << endl;

int test_complexity() {
  cout << "===================" << endl;
  cout << "Starting Time Tests" << endl;
#ifdef USE_CORMEN
  cout << "For Cormen's Method" << endl;
#endif

#ifdef USE_MSBM
  cout << "For Most Significant Bits Method" << endl;
#endif

#ifdef USE_K_MOD_M
  cout << "For k mod m Method" << endl;
#endif

  cout << "===================" << endl;
  int sizes[5] = {1, 10, 100, 1000, 10000};

  for (int size : sizes) {
    int element_count = size * 2;
    HashTable<int> ht = create_randomized_hashtable(size, element_count);
    TIME_TEST(ht.insert(rand(), rand()),
              "Randomized Hashtable insert with " + to_string(element_count) +
                  " elements " + "of size " + to_string(size));

    cout << "The highest load is "
         << (float)ht.get_highest_load() / ((float)element_count / (float)size)
         << " times the ideal load" << endl
         << endl;
  }

  return 0;
}

//=================================================
// create_randomized_hashtable
// Creates a randomized integer hashtable with size `size` and `element_count`
// count of elements.
//
// PARAMETERS:
//  size: The size of the hashtable
//  element_count: The counts of element in hashtable
//
// RETURN VALUE:
//  Returns a int hashtable with randomized elements of key and data being any
//  possible int.
//=================================================
HashTable<int> create_randomized_hashtable(int size, int element_count) {
  HashTable<int> ht = HashTable<int>(size);
  for (int i = 0; i < element_count; i++) {
    ht.insert(rand(), rand());
  }

  return ht;
}
