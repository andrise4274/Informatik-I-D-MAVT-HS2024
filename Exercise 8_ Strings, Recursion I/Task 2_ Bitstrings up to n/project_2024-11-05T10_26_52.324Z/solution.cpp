#include "solution.h"
#include <string>
#include <cassert>

/*
// PRE: positive integer n
// POST: 2^n
int to_pow_n(int n) {
  return 2 << n;
}
*/

// PRE: positive integer n
// POST: 2^n
int to_pow_n(int n) {
  int res = 1;
  for (int i = 0; i <= n; i++) {
    res *= 2;
  }
  return res;
}


// PRE: string vector, int k - number of digits of current bitstring, int max - maximum digits of bitstring
// POST: fills up vector with all bitstrings with n digits
// recursively add all bitstrings of digits k until digits max
void add_digit(std::vector<std::string>& vec, int k, int max) {
  // terminal condition, for recursion
  if (k < max) {
    // get last index
    int last_index = int(vec.size()) - 1;
    // loop over all possible indicies of bitstrings of previous length
    for (int j = to_pow_n(k - 1) - 1; j >= 0 ; j--) {
      // add a new bitstring, by adding a 0 or 1 to previous bitstring
      vec.push_back(vec[last_index - j] + '0');
      vec.push_back(vec[last_index - j] + '1');
    }
    // recursive call
    add_digit(vec, k + 1, max);
  }
  return;
}


// PRE: positive integer n
// POST: initiates recursion and returns obtained bitstrings vector
std::vector<std::string> all_bitstrings_up_to_n(int n) {
  assert(n >= 0);
  if (n == 0) {
    return {""};
  }
  std::vector<std::string> bitstrings = {"0", "1"};
  add_digit(bitstrings, 1, n);
  
  return bitstrings;
}
