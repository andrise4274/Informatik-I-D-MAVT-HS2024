#include <iostream>

#include <limits> 

int main() {
  // input
  int n = 0;
  //std::cout << "Input a number n: ";
  std::cin >> n;
  
  int max = std::numeric_limits<int>::max();
  
  int a_1 = 0;
  int a_2 = 1;
  int count = 0;
  
  // print first 0
  if (n >= 1) {
    std::cout << 0 << "\n";
    count = 1;
  }
  
  while (count < n) {
    
    // check and stop program if a_2 + a_1 would go over max
    if (max - a_2 - a_1 < 0) {
      // print last number
      std::cout << a_2 << "\n";
      count ++;
      break;
    }
    
    count++;
    std::cout << a_2 << "\n";
    // update last two fibonacci numbers
    int ch = a_2;
    a_2 = a_1 + a_2;
    a_1 = ch;
    
  }
  
  std::cout << "Printed " << count << " of " << n << " Fibonacci numbers\n";
  
  return 0;
}