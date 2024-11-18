#include <iostream>

int main() {
  int n;
  int digit;
  int highest_divisor = 1;
  // ensure positive input
  do {
    std::cin >> n;
  } while (n < 0);
  
  
  // find highest divisor
  while (highest_divisor <= n/2) {
    highest_divisor *= 2;
  }
  
  // print all digits
  while (highest_divisor > 0) {
    // integer divison to receive either 0 or 1 digit
    digit = n / highest_divisor;
    // output digit
    std::cout << digit;
    // n <- new_n
    n %= highest_divisor;
    //new highest divisor
    highest_divisor /= 2;
  }
  
  return 0;
}

