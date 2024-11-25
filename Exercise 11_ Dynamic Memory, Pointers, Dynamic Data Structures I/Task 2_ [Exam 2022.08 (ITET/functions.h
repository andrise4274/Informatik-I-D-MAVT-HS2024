#pragma once

#include <vector>
using iterator = std::vector<int>::const_iterator;

// PRE:   iterator pair [begin,end) specifies a valid range
//        within a vector (begin is included, end is not) containing numbers 
//        in [0, 2147483647]. The range in the vector comprises at least two elements.
// POST:  returns the largest absolute difference between two neighbouring numbers in the vector. 
//
// Example:
//  * [1, 5, 2, 5, 7, 6] ~~> 4
//  * [2, 9, 1] ~~> 8
int largest_difference(iterator begin, iterator end) {
  int max_diff = 0;
  for (iterator it = begin; it != end - 1; it++) {
    if (std::abs(*it - *(it + 1)) > max_diff) {
      max_diff = std::abs(*it - *(it + 1));
    }
  }
  return max_diff;
}