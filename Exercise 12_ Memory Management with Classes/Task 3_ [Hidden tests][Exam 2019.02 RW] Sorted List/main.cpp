#include <iostream>
#include "sorted_list.h"


bool hasInt(std::istream& in){
  while (in.good() && std::isspace(in.peek()))
    in.get();
  return in.good()  && (std::isdigit(in.peek()) || in.peek () == '-');
}

// The following main function implements a little command interface
// The format of the test input is 
// {Add | Remove | Print} "end".
// Add = "add" {Integer}.
// Remove = "remove" {Integer}.
// Print = "print".
int main() {
  sorted_list list;
  while (std::cin.good()) {
    std::string command;
    std::cin >> command;
    if (command == "end") {
      break;
    }
    if (command == "add") {
      while (hasInt(std::cin)){
        int value;
        std::cin >> value;
        list.add(value);
      }
    } else if (command == "remove") {
      while (hasInt(std::cin)){
        int value;
        std::cin >> value;
        if (!list.remove(value))
          std::cout << value << " not contained." << std::endl;
        else
          std::cout << value << " removed." << std::endl;
      }
    } else if (command == "print") {
      list.print(std::cout);
      std::cout << std::endl;
    } else {
      std::cout << "unknown command: " << command << std::endl;
    }
  }
  return 0;
}