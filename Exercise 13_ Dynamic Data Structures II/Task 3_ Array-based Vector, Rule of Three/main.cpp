#include <iostream>
#include "our_vector.h"

void test_destructor() {
  our_vector a = our_vector(42);
}

void test_copy_constructor() {
  our_vector a = our_vector(3);
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  our_vector b(a);
  a[0] = -1;
  a[1] = -2;
  a[2] = -3;
  std::cout << a << b;
}

void test_assignment_operator() {
  our_vector a = our_vector(3);
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  our_vector b = our_vector(4);
  b[0] = 4;
  b[1] = 5;
  b[2] = 6;
  b[3] = 7;
  b = a;
  a[0] = 8;
  a[1] = 9;
  a[2] = 10;
  std::cout << a << b;
}

void test_assignment_operator_2() {
  our_vector a = our_vector(4);
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  a[3] = 4;
  our_vector b = our_vector(3);
  b[0] = 5;
  b[1] = 6;
  b[2] = 7;
  b = a;
  a[0] = 8;
  a[1] = 9;
  a[2] = 10;
  a[3] = 11;
  std::cout << a << b;
}

int main () {
  int test_id;
  std::cin >> test_id;
  switch(test_id) {
  case 0:
    test_destructor();
    break;
  case 1:
    test_copy_constructor();
    break;
  case 2:
    test_assignment_operator();
    break;
  case 3:
    test_assignment_operator_2();
    break;
  default:
    your_own_tests();
  }
  std::cout << "Remaining tracked elements: " << count_tracked() << '\n';
  return 0;
}

