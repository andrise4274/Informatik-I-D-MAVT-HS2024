#include "add.h"

// PRE:  a, b, and res are valid pointers to integer values.
// POST: integer at location res contains the result of adding the integer at 
//       location a and the integer at location b.
void add(int* res, const int* a, const int* b) {
  // set the value at address res, to value at address a + value at address b
  *res = *a + *b;
}