#include "run_length.h"

bool valid_input(int input) {
  return (input <= 255 && input >= -1);
}


void decode()
{
  // implement decode function
  // NOTE: do not printout new line (i.e., std::endl or '\n')
  int value;
  int repeats;
  int ptr = 0;
  
  std::cout << "0 ";
  
  do {
     std::cin >> value;
     
    //check input
    if (!valid_input(value)) {
      std::cout << "error";
      return;
    }
    
    if (ptr % 2 == 0) {
      repeats = value;
    } else if (value != -1){
      for (int i = 0; i < repeats; i++) {
        std::cout << value << " ";
      }
    } else {
      std::cout << "error";
      return;
    }
    ptr++;
  } while (value != -1 && ptr < 255);
  
  std::cout << -1;
}



void encode()
{
  int value;
  int prev;
  int repeats = 1;
  
  std::cout << "1 ";
  std::cin >> value;
  
  while (value != -1) {
    
    prev = value;
    std::cin >> value;
    //check input
    if (!valid_input(prev)) {
      std::cout << "error";
      return;
    }
    
    if (prev == value && repeats < 255) {
      repeats ++;
    } else {
      // print out the new tuple n, w
      std::cout << repeats << " " << prev << " ";
      repeats = 1;
    }
  }
  std::cout << -1;
}