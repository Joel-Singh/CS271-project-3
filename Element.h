#ifndef ELEMENT_H
#define ELEMENT_H

template <typename T> class Element {
public:
  Element();
  Element(T data, int key);
  int get_key();
  T get_data();
};

#include "Element.cpp"
#endif
