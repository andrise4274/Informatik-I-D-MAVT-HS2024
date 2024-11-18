#include <iostream>

#include "solution.h"
#include "redirector.cpp"

int main() {
  std::cerr << "Choose mode" << std::endl
            << "0 -> trapezoid" << std::endl
            << "1 -> diamond" << std::endl
            << "2 -> hourglass" << std::endl;
  std::cerr << "Mode: ";
  
  // Note: Please ignore the following line, it is only needed for internal 
  //       reasons
  const Redirector redirector;
  
  int mode;
  std::cin >> mode;

  if (mode == 0) {
    int base_width;
    int height;
    bool upsidedown;

    std::cerr << "Base width: ";
    std::cin >> base_width;

    std::cerr << "Height: ";
    std::cin >> height;

    std::cerr << "Upsidedown? ";
    std::cin >> std::boolalpha >> upsidedown;

    print_trapezoid(base_width, height, 0, upsidedown);
  } else if (mode == 1) {
    int center_width;

    std::cerr << "Center width: ";
    std::cin >> center_width;

    print_diamond(center_width);
  } else if (mode == 2) {
    int base_width;

    std::cerr << "Base width: ";
    std::cin >> base_width;

    print_hourglass(base_width);
  }

  return 0;
}