#include "lookup.h"

// PRE:  0 <= i < vec.size()
// POST: Returns the address of the i-th element of vec.
const int* lookup(const std::vector<int>& vec, const int i) {
  // go to address vec[i] (pointer) and return the address of this element
  return &vec[i];
}