#include <iostream>

int main() {
  double x, y;
  //std::cout << "Give x: ";
  std::cin >> x;
  //std::cout << "Give y";
  std::cin >> y;
  
  double epsilon = 0.00001;
  
  if (std::abs(x * x * 0.9 + 1.3 * x - 0.7 - y) < epsilon) {
    std::cout << "yes\n";
  }
  else {
    std::cout << "no\n";
  }
  
  return 0;
}