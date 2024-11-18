#include <iostream>
#include <cassert>
#include "reverse.h"


int main() {
  
    // Input
    int a;
    
    std::cout << "Enter your number: ";
    std::cin >> a;
    
    assert(a >= 0);
    reverse(a);
    
    return 0;
}
