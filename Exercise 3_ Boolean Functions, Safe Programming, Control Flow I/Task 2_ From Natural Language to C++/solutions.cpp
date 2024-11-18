#include "solutions.h"

// Fill out each function with the appropriate expression

bool task1(int a, int b) { 
  // a greater than  b and the difference between a and b is smaller than 15.
  return (a > b) && ((a-b) < 15); // Replace with your solution 
}


bool task2(int a) { 
  // a is an even natural number greater than 3.
  return (a % 2 == 0) && a > 3; // Replace with your solution
}


bool task3(int a, int b, int c) { 
  // a is at most 5 times greater than b (but can also be smaller than b) 
  // and at least 5 times greater than c.
  return a <= 5 * b && a >= 5 * c; // Replace with your solution
}


bool task4(bool a, bool b, bool c) { 
  // Either a and b are both false or c is true, but not both.
  return (!a && !b) ^ (c); // Replace with your solution 
}


bool task5(bool a, int b) { 
  // a is false and b is zero.
  return !a && b == 0; // Replace with your solution
}