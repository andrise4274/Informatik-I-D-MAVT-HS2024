#include <iostream>
#include <cassert>
#include "our_vector.h"

our_vector::our_vector(int size): count(size) {
  elements = new tracked[size]();
}

int our_vector::size() const {
  return count;
}

int& our_vector::operator[](int i) {
  return *elements[i];
}

int& our_vector::at(int i) {
  assert(i < count);
  return *elements[i];
}

void our_vector::print(std::ostream& sink) const {
  tracked* end = elements + count;

  for (tracked* p = elements; p != end; ++p) {
    sink << *(*p) << ' ';
  }

  sink << '\n';
}

std::ostream& operator<<(std::ostream& sink, const our_vector& vec) {
  vec.print(sink);

  return sink;
}
