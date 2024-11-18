#include <iostream>
#include <limits>
#include "rounding.h"

int main() {
  double x;
  std::cin >> x;
  
  // Check whether input is closest to an integer which can be rounded
  if (x + 0.5 <= std::numeric_limits<int>::min()
          || x - 0.5 >= std::numeric_limits<int>::max()) {
      std::cout << "Input out of bounds\n";
      return 1;
  }
  
  // The roudned number is printed surrounded by *
  std::cout << "***" << round_number(x) << "***\n";
  return 0;
}