#include <string>
#include <vector>

#include "set.h"
#include "solution.h"

// recursive function
StringSet cart_product(const std::vector<CharSet>& sets, int max_index);
// convert charset to stringset
StringSet convert(CharSet set);


// PRE: takes a vector of CharSets
// POST: returns the Stringset with all cartesian combinations
StringSet set_product(const std::vector<CharSet>& sets) {
  // check if set is empty
  if (int(sets.size()) == 0) {
    return StringSet("");
  }
  // recursively add combinations
  return cart_product(sets, int(sets.size() - 1));
}

// PRE: takes a vector of CharSets and a maximum index < sets.length()
// POST: returns the Stringset with all cartesian combinations
StringSet cart_product(const std::vector<CharSet>& sets, int max_index) {
  // terminal condtion/base case
  if (max_index == 0) {
    // return sets[0] (first set) as a StringSet
    return convert(sets[0]);
  }
  
  StringSet out = cart_product(sets, max_index - 1);
  
  // go through all combinations and insert them into new StringSet new_combs
  StringSet new_combs;
  // convert next CharSet to StringSet
  StringSet next = convert(sets[max_index]);
  for (int i = 0; i < out.size(); i++) {
    for (int j = 0; j < next.size(); j++) {
      new_combs.insert(out[i] + next[j]);
    }
  }
  return new_combs;
}

// PRE: takes a CharSet of chars
// POST: returns it as StringSet
StringSet convert(CharSet set) {
  StringSet out;
  for (int i = 0; i < set.size(); i++) {
    out.insert(std::string(1, set[i]));
  }
  return out;
}