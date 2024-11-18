#include "io.h"

#include <iostream>

void read_vector(vec& v) {
  int size;
  std::cin >> size;
  v = vec(size);
  for (int i = 0; i < int(v.size()); ++i) {
    std::cin >> v[i];
  }
}

void read_matrix(mat& m) {
  int n_rows, n_cols;
  std::cin >> n_rows >> n_cols;

  m.resize(n_rows);
  for (int row = 0; row < int(m.size()); ++row) {
    m[row].resize(n_cols);
    for (int col = 0; col < int(m[row].size()); ++col) {
      std::cin >> m[row][col];
    }
  }
}

void print_scalar(int s) {
  std::cout << "s"
            << "\n"
            << s << "\n";
}

void print_vector(const vec& v) {
  std::cout << "v " << v.size() << "\n";
  for (int i = 0; i < int(v.size()); ++i) {
    std::cout << v[i] << " ";
  }
  std::cout << "\n";
}

void print_matrix(const mat& m) {
  std::cout << "m " << m.size() << " " << m[0].size() << "\n";
  for (int row = 0; row < int(m.size()); ++row) {
    for (int col = 0; col < int(m[row].size()); ++col) {
      std::cout << m[row][col] << " ";
    }
    std::cout << "\n";
  }
}