#include "pair_sum.h"
#include <climits>

// PRE:  for any two indices i and j, v[i] + v[j] ≤ INT_MAX
// POST: returns the number of indices (i,j), i<j of a vector v
//       that corresponds to the given iterator range such that
//       v[i] + v[j] == sum.
int pairs_with_sum(int sum, iterator begin, iterator end){
  // initialize count
  int count = 0;
  // loop two times over the vector to test all possibilities
  // if index i is not bigger than j, ignore it
  for(std::vector<int>::const_iterator i = begin; i < end; i++) {
    for(std::vector<int>::const_iterator j = begin; j < end; j++) {
      // *i -> pointer access the variables v as with v[i]
      if ((i > j) && (*i + *j == sum)) {
        count++;
      }
    }
  }
  
  return count;
}