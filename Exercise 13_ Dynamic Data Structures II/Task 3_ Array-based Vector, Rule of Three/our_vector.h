#pragma once

#include <iostream>
#include "tracker.h"

class our_vector {
  int count; // Size of the vector
  tracked* elements; // Vector elements (actually, a pointer to the first element)

public:
  // POST: Instantiated a new our_vector with 'size' elements
  our_vector(int size); // Constructor

  // POST: Instantiated a copy of vec.
  our_vector(const our_vector& vec);
  
  // POST: Assign to content of vec, return reference to the this-object.
  our_vector& operator=(const our_vector& vec);
  
  // POST: Deallocate the content.
  ~our_vector();
  
  // POST: Returns the size of the vector
  int size() const;

  // PRE:  i < size()
  // POST: Returns a reference to the ith element
  int& operator[](int i);

  // PRE:  i < size()
  // POST: Returns a reference to the ith element, or aborts the program
  //       if i is not a valid index
  int& at(int i);

  // POST: All vector elements were output to 'sink' 
  void print(std::ostream& sink) const;
};

// POST: All elements of 'vec' were output to 'sink' 
std::ostream& operator<<(std::ostream& sink, const our_vector& vec);

// Debugging utility.
void your_own_tests();
