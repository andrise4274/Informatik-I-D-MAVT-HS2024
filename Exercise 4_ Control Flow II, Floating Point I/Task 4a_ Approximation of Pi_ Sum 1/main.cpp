#include <iostream>

double taylor_term(int i);

int main() {
  // input
  int m = 0;
  std::cout << "Integer m, bigger than 0: ";
  do {
    std::cin >> m;
  } while (m < 1);
  
  // sum up the whole taylor series
  double pi = 0;
  for (int i = 0; i < m; i++) {
    pi += taylor_term(i);
  }
  
  // output
  std::cout << "Approximation of PI: " << 4 * pi << "\n";
  return 0;
}

// dunction which calculates the jth term of the taylor series
double taylor_term(int i) {
  double term = 1;
  if (i == 0) {
    term = 1;
  } else if (i % 2 == 0){
    term = 1.0/(2*i + 1);
  } else {
    term =  -1.0/(2*i + 1);
  }
  return term;
}