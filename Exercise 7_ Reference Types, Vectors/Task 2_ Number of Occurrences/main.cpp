#include <iostream>
#include <vector>
#include <cassert>


std::vector<int> read_vec();
int count_occ(std::vector<int>& vec, int n);


int main() {
  int n;
  std::vector<int> vec;
  vec = read_vec();
  
  // read int n
  std::cin >> n;
  assert(n >= 0);
  
  std::cout << count_occ(vec, n) << "\n";
  
  return 0;
}


// POST: read in a vector from console and return it
std::vector<int> read_vec() {
  int in;
  // initialize empty vector
  std::vector<int> vec;
  do {
    std::cin >> in;
    vec.push_back(in);
  } while (in >= 0);
  return vec;
}


// PRE: a vector and a positive integer
// POST: returns the number of occurances of integer i in vector
int count_occ(std::vector<int>& vec, int n) {
  int occ = 0;
  for (int i = 0; i < int(vec.size()); i++) {
    if (vec[i] == n) {
      occ++;
    }
  }
  return occ;
}