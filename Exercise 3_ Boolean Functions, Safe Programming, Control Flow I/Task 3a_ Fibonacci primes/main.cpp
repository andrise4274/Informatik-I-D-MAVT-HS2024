#include <iostream>


bool is_prime(int num) {

  // check if 0 or 1
  if (num == 0 || num == 1) {
    return false;
  }
  // go through all possible divisors from 2 up to num/2
  for (int i = 2; i <= num/2; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  // if now divisor found: return true
  return true;
}

int main() {
  // user input
  int m = 0;
  std::cout << "Give a max bound to find Fibonacci primes: ";
  std::cin >> m;
  
   int a_1 = 0;
   int a_2 = 1;
   int count = 0;
   
  // for loop
  while (a_2 <= m){
    
    if (is_prime(a_2)) {
      std::cout << a_2 << "\n";
      count++;
    }
    // update last two fibonacci numbers
    int ch = a_2;
    a_2 = a_1 + a_2;
    a_1 = ch;
  }
  
  // output count
  std::cout << "Found " << count << " Fibonacci primes";
  
  return 0;
}