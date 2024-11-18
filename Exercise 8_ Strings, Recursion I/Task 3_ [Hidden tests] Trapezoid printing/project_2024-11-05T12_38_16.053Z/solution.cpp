#include <assert.h>

#include <iostream>

#include "solution.h"

void print_row(int n_bricks, int offset_left) {
  // print spaces for offset
  for (int i = 0; i < offset_left; ++i) {
    std::cout << " ";
  }

  // print bricks
  for (int i = 0; i < n_bricks; ++i) {
    if (i != 0) {
      std::cout << " ";
    }
    std::cout << "0";
  }
  std::cout << std::endl;
}

void print_trapezoid(int base_width, int height,
                     int offset_left, bool upsidedown) {
  assert(base_width >= height);
  
  // if not pyramid shape
  if (!upsidedown) {
    // terminal condition
    if (height == 0) {
      return;
    }
    // print row and recurively print next row
    // careful -> base_width-height+1, offset_left +height-1
    print_row(base_width - height + 1, offset_left + height - 1);
    // (base_width) (height-1) (offset_left)
    print_trapezoid(base_width, height - 1, offset_left, upsidedown);
  
    
  } else {
    // terminal condition
    if (height == 0) {
      return;
    }
    // print row and recurively print next row
    print_row(base_width, offset_left);
    // (base_width-1) (height-1) (offset_left+1)
    print_trapezoid(base_width - 1, height - 1, offset_left + 1, upsidedown);
  }
}


void print_diamond(int center_width) {
  // print top and bottom part - avoid doublicate rows, with function params
  print_trapezoid(center_width, center_width, 0, false);
  print_trapezoid(center_width - 1, center_width - 1, 1, true);
  return;
}

void print_hourglass(int base_width) {
  // print top and bottom part - avoid doublicate rows, with function params
  print_trapezoid(base_width, base_width, 0, true);
  print_trapezoid(base_width, base_width - 1, 0, false);
  return;
}