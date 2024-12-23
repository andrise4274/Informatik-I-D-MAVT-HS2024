#include "our_vector.h"
#include <unordered_set>

our_vector::our_vector(const our_vector& vec) : count(vec.count) {
  
  elements = new tracked[count];
  // copy all elements into the new allocated memory block, one by one
  for (int i = 0; i < count; i++) {
    elements[i] = vec.elements[i];
  }
}

our_vector& our_vector::operator=(const our_vector& t) {
  if (this != &t) { // no self assignment
    our_vector copy = t;
    // swap the elements and the count between copy of t and this
    // this ensures vector t, stays as it is and only copy and this is changed
    std::swap(elements, copy.elements);
    std::swap(count, copy.count);
  }
  return *this;
}

our_vector::~our_vector() {
  // deallocate the array stored within our_vector
  delete[] elements;
}

void your_own_tests() {
  our_vector v1(5); // Create a vector with 5 elements
    our_vector v2(v1); // Use the copy constructor

    // Example test: Assignment operator
    our_vector v3(3); // Create a vector with 3 elements
    v3 = v1; // Use the assignment operator
}
