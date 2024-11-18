#pragma once

#include <vector>


// PRE:   The vector "weights" at position i contains the weight of element i.
//        The vector "values" at position i contains the value of element i.
//        The vectors have the same size and always contain at least two items.
//        The value and weight of every item is > 0.
//
// POST:  Returns the sum of the value of the two items that have the most value, 
//        while the sum of their weight is at most `weight_limit`.
//        It is not allowed to pick only one item.
//        It is also not allowed to pick an item twice, but two different items must be chosen.
//        If there are no two items that can be chosen (due to exceeding weight), return 0.
//      
// Example:
//  * weights: [1, 2, 2], values: [3, 1, 9], weight_limit: 3  ~~> 12;
int best_two_elements(const std::vector<int>& values,
                      const std::vector<int>& weights,
                      int weight_limit) {
  
  int max_value = 0;
  // try all combinations
  for (int i = 0; i < int(values.size()); i++) {
    for (int j = 0; j < int(values.size()); j++) {
      if (i != j) {
        if (weights[i] + weights[j] <= weight_limit && values[i] + values[j] > max_value) {
          max_value = values[i] + values[j];
        }
      }
    }
  }
  
  return max_value;
}
