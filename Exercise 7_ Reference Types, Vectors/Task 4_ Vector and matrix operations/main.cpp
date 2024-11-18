#include <iostream>
// Enable std::vectors
#include <vector>
#include <cassert>
#include "io.h"

using vec = std::vector<int>;
using mat = std::vector<vec>;


// PRE: two vectors of equal dimension
// POST: integer which is the result of the dot Product
int dotp(vec v1, vec v2) {
  assert(v1.size() == v2.size());
  int result = 0;
  int rows1 = int(v1.size());
  
  for (int i = 0; i < rows1; i++) {
    result += v1[i] * v2[i];
  }
  return result;
}


// POST: result of dot product of v1 and v2 is printed to standard output,
// or "error" if dimensions are not compatible
void dot_product(const vec& v1, const vec& v2) {
  
  int result = 0;
  int rows1 = int(v1.size());
  int rows2 = int(v2.size());
  // check if dimensions match
  if (rows1 != rows2) {
    std::cout << "error";
    return;
  }
  
  result = dotp(v1, v2);
  
  print_scalar(result);
}


// POST: result of matrix product of m1 and m2 is printed to standard output,
// or "error" if dimensions are not compatible
void matrix_product(const mat& m1, const mat& m2) {
  
  // extract dimensions
  int rows1 = m1.size();
  int cols1 = m1.at(0).size();
  int rows2 = m2.size();
  int cols2 = m2.at(0).size();
  
  
  // check if dimensions work out
  // check if dimensions match
  if (cols1 != rows2) {
    std::cout << "error";
    return;
  }
  
  mat result = mat(rows1, vec(cols2, 0));
  
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols2; j++) {
      // set a new vector to column values (to be able to use dotp())
      vec colum;
      for (int k = 0; k < rows2; k++) {
        colum.push_back(m2[k][j]);
      }
      result[i][j] = dotp(m1[i], colum);
    }
  }
  
  print_matrix(result);
}


// POST: result of product of m1 and v2 is printed to standard output,
// or "error" if dimensions are not compatible
void matrix_vec_product(const mat& m1, const vec& v2) {
  
  // extract dimensions
  int rows1 = m1.size();
  int cols1 = m1.at(0).size();
  int rows2 = v2.size();
  
  // check if dimensions match
  if (cols1 != rows2) {
    std::cout << "error";
    return;
  }
  
  vec result = vec(rows1);
  for (int i = 0; i < rows1; i++) {
    result[i] = dotp(m1[i], v2);
  }
  print_vector(result);
}


int main() {
  std::cout << "Left operand" << std::endl;
  char left_type;
  std::cin >> left_type;

  if (left_type == 'v') {
    // left operand is vector

    // get vector from input
    vec left_operand;
    read_vector(left_operand);

    // get right operand type
    std::cout << "Right operand" << std::endl;
    char right_type;
    std::cin >> right_type;

    if (right_type == 'v') {
      // right operand is a vector => compute dot product

      // get vector from input
      vec right_operand;
      read_vector(right_operand);

      // compute dot product
      dot_product(left_operand, right_operand);
      
    } else {
      //throw error
      std::cout << "error";
      return 0;
    }
    
  } else if (left_type == 'm') {
    
    // left operand is vector

    // get vector from input
    mat left_operand;
    read_matrix(left_operand);

    // get right operand type
    std::cout << "Right operand" << std::endl;
    char right_type;
    std::cin >> right_type;
    
    if (right_type == 'v') {
      // right operand is a vector => compute matrix vector product
      
      vec right_operand;
      read_vector(right_operand);

      // compute matrixproduct
      matrix_vec_product(left_operand, right_operand);
      
      
    } else if (right_type == 'm') {
      // right operand is a matrix => compute matrix product
      
      mat right_operand;
      read_matrix(right_operand);

      // compute matrixproduct
      matrix_product(left_operand, right_operand);
      
    } else {
      //throw error
      std::cout << "error";
      return 0;
    }
    
  } else {
    //throw error
    std::cout << "error";
    return 0;
  }
  
  
  // TODO: handle other cases
 
  return 0;
}
