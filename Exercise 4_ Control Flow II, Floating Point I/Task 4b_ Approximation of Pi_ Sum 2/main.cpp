#include <iostream>


double mul_term(int i);

int main () {
  //input
  int m;
  std::cout << "Give an Integer bigger than 0: ";
  do {
    std::cin >> m;
  } while (m < 1);
  
  double pi = 1.0;
  
  // sum up all terms
  for (int i = 1; i < m; i++) {
    pi += mul_term(i);
  }
  
  // output
  std::cout << "Approximation of Pi: " << pi * 2 << "\n";
  return 0;
}

double mul_term(int i) {
  double nominator = 1;
  double denominator = 1;
  // multiply up all terms
  for (int j = 1; j <= i; j++) {
    nominator *= j;
    denominator *= (2.0 * j + 1);
  }
  return nominator / denominator;
}