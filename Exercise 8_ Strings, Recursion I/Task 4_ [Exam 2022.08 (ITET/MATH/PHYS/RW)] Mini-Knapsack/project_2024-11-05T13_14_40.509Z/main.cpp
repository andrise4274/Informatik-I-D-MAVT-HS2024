#include <iostream>
#include <istream>
#include <vector>
#include <cassert>
#include "functions.h"

// ----------------------------------------------------------------------
// NOTE: You most likely don't need to read and understand
// the content of this file
// ----------------------------------------------------------------------

int main() {
  std::cout << "Enter the amount of items to choose from:" << std::endl;
  int n;
  std::cin >> n;

  std::cout << "Enter the maximum weight of the backpack content:" << std::endl;
  int max_weight;
  std::cin >> max_weight;
  
  std::cout << "Enter " << n << " weights of items:" << std::endl;
  std::vector<int> weights = {};
  
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    assert (x > 0);
    weights.push_back(x);
  }
  
  std::cout << "Enter " << n << " values of items:" << std::endl;
  std::vector<int> values = {};
  
    for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    assert (x > 0);
    values.push_back(x);
  }
  
  assert(int(values.size()) == n);
  assert(values.size() == weights.size());
  assert(int(values.size()) >= 2);

  const char marker = '|';
  
  int max_value = best_two_elements(values, weights, max_weight); 

  std::cout << "best_two_elements = "
            << marker
            << max_value
            << marker
            << std::endl;
            
  return 0;
}
