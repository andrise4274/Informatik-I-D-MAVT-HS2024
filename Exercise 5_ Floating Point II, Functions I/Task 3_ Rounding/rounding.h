#pragma once

// PRE: x is roundable to a number in the value range of type int
// POST: return value is the integer nearest to x, or the one further
//       away from 0 if x lies right in between two integers.
int round_number(double x) {
  double add = 0;
  if (x <= 0) {
    add = -0.5;
  } else {
    add = 0.5;
  }
  
  int rounded = x + add;
  return rounded;
}
