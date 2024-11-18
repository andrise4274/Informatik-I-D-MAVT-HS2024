#include <iostream>
#include <string>
#include <vector>

#include "solution.h"

int main() {
  std::cerr << "Bitstring length: ";
  int n;
  std::cin >> n;
  
  std::vector<std::string> bitstrings = all_bitstrings_up_to_n(n);
  
  std::cerr << "Bitstrings up to length " << n << std::endl;
  for (int i = 0; i < int(bitstrings.size()); ++i) {
    std::cout << bitstrings[i] << std::endl;
  }

  return 0;
}