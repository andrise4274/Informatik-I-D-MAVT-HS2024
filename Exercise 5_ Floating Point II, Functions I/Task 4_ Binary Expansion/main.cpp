#include <iostream>


int calc_b(double input) {
  if (input >= 1) {
    return 1;
  } else {
    return 0;
  }
}


int main() {
  // ensure input between 0 and 2
  double input;
  do {
    std::cout << "Give a Number between 0  and 2 (not included): ";
    std::cin >> input;
  } while (input < 0.0 || input >= 2.0);
  
  int b = calc_b(input);
  std::cout << b << ".";
  
  for (int i = 1; i < 16; i++) {
    input -= b;
    input *= 2;
    b = calc_b(input);
    std::cout << b;
  }
  
  std::cout << "\n";
  return 0;
}