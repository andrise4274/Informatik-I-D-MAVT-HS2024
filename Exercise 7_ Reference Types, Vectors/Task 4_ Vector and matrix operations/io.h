#pragma once

#include <vector>

using vec = std::vector<int>;
using mat = std::vector<vec>;

// PRE: -
// POST: v is set to vector read from std::cin
void read_vector(vec& v);

// PRE: -
// POST: m is set to matrix read from std::cin
void read_matrix(mat& m);

// PRE: -
// POST: scalar s printed to std::cout
void print_scalar(int s);

// PRE: -
// POST: vector v printed to std::cout
void print_vector(const vec& v);

// PRE: m is a bi-dimensional vector (matrix) with non-zero dimensions
// POST: matrix m printed to std::cout
void print_matrix(const mat& m);