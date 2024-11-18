#include "solution.h"

StringSet new_combinations(const std::string& s, int index);
StringSet all_combinations(std::string s, char ch);

StringSet all_permutations(const std::string& s) {
  // check if set is empty
  if (int(s.size()) == 0) {
    return StringSet("");
  }
  
  // recursively add combinations
  // index goes from 0 to sets.size() - 1
  return new_combinations(s, 0);
}


// PRE: takes a String by reference and an index
// POST: recursively adds combinations of strings
// to a stringSet, until all possible Strings are in there
StringSet new_combinations(const std::string& s, int index) {
  // terminal condition
  if (index == int(s.size())) {
    return StringSet("");
  }
  
  // recursive call
  StringSet combinations = new_combinations(s, index + 1);
  
  // updated_stringset
  StringSet updated;
  
  for (int j = 0; j < combinations.size(); j++) {
    // get a Stringset of all combinations
    StringSet partial_combinations = all_combinations(combinations[j], s[index]);
    // add this stringset to updated
    updated =  updated + partial_combinations;
  }
  return updated;
}


// PRE: takes a char and string
// POST: outputs a Stringset, with all possible string combinations
// using substr method
StringSet all_combinations(std::string s, char ch) {
  StringSet combinations;
  for(int i = 0; i <= int(s.size()); i++) {
    std::string newone = "";
    newone += s.substr(0, i) + ch + s.substr(i);
    combinations.insert(newone);
  }
  return combinations;
}