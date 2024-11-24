#include "solution.h"

StringSet new_combinations(const std::string& s, int max_index);
StringSet all_combinations(std::string s, char ch);


// PRE: takes string
// POST: returns all String premutations of chars in that string as Stringset
StringSet all_permutations(const std::string& s) {
  // check if set is empty
  if (int(s.size()) == 0) {
    return StringSet("");
  }
  
  // recursively add combinations
  // index goes from sets.size() - 1 to 0
  return new_combinations(s, s.size() - 1);
}

// PRE: takes string and a maximum index (for chars to consider in the string) < sets.size()
// POST: returns recursively all String premutations of chars in that string as Stringset
StringSet new_combinations(const std::string& s, int max_index) {
  // terminal condition/base case
  if (max_index == 0) {
    return StringSet(std::string(1, s[0]));
  }
  // recursive call
  StringSet out = new_combinations(s, max_index - 1);
  StringSet new_combs;
  
  // append all combinations of strings in StringSet out and next char (s[max_index])
  for (int i = 0; i < out.size(); i++) {
    new_combs = new_combs + all_combinations(out[i], s[max_index]);
  }
  return new_combs;
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