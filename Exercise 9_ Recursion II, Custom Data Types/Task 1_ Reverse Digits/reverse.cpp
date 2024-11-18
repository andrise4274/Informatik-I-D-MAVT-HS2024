#include "reverse.h"
#include <iostream>



// PRE: n >= 0
// POST: print the digits of the input in reverse order to std::cout
void reverse(int n)
{
  if (n > 0) {
    int digit = n % 10;
    std::cout << digit;
    n = n / 10;
    if (n != 0) {
      reverse(n);
    }
  } else {
    std::cout << 0;
    return;
  }
}

