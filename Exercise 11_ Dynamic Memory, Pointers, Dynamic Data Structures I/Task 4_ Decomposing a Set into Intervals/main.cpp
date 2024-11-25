#include <iostream>
#include <set>

using iterator = std::set<int>::iterator;


int main() {
  // input
  std::set<int> values;
  int in;
  std::cin >> in;
   while (in >= 0) {
    values.insert(in);
    std::cin >> in;
  };
  
  // check if empty set
  if (values.empty()) {
    std::cout << "()" << std::endl;
    return 0;
  }
  
  // initialize intervall length and first element in values
  int length = 0;
  int begin = *values.begin();
  // start output print
  std::cout << "(";
  // loop over all values and print found intervalls continiously
  for (iterator it = values.begin(); it != values.end(); it ++) {
    // skip first element, to avoid out of bounds indexing by prev(it)
    if (it != values.begin()) {
      // if the previous element is only one smaller than current, increase length of found intervall
      if (*it == *(std::prev(it)) + 1) {
        length++;
      // if the difference is bigger than 1, print the found intervall
      } else {
        std::cout << "[" << begin << "," << begin + length << "]U";
        // reset begin of new intervall to current iteration and length to 0
        begin = *it;
        length = 0;
      }
    }
  }
  // print the last intervall found outside loop
  std::cout << "[" << begin << "," << begin + length << "]";
  // print ending braces
  std::cout << ")";
  return 0;
}