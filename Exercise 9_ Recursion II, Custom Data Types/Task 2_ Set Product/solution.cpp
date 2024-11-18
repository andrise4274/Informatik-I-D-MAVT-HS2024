#include <string>
#include <vector>

#include "set.h"
#include "solution.h"

// recursive function
StringSet cart_product(const std::vector<CharSet>& prev_sets, int index);


StringSet set_product(const std::vector<CharSet>& sets) {
  // check if set is empty
  if (int(sets.size()) == 0) {
    return StringSet("");
  }
  // recursively add combinations
  // index goes from 0 to sets.size() - 1
  return cart_product(sets, 0);
}


StringSet cart_product(const std::vector<CharSet>& sets, int index) {
  // Convert to vector
  std::vector<char> elements(sets[index].elements().begin(), sets[index].elements().end());
  
  // index goes from 0 to sets.size() - 1
  // terminal condition: if only one set left
  if (index == int(sets.size()) - 1) {
    // initialize output set
    StringSet out;
    // add the last set
    for (int i = 0; i < sets[index].size(); i++) {
      // convert to string of length 1
      std::string str = std::string(1, elements[i]);
      out.insert(str);
    }
    return out;
  }
  
  // if not base case: add all combinations with existing set
  // initialize output set
  StringSet out;
  // get all combis before, recursively
  StringSet temp = cart_product(sets, index + 1);
  // loop through all the possibilities
  for (int i = 0; i < temp.size(); i++) {
    for (int j = 0; j < sets[index].size(); j++) {
      
      // create new string to append, concatenate new_element with old string
      std::string newCombi = std::string(1, elements[j]) + temp[i];
      out.insert(newCombi);
    }
  }
  return out;
}