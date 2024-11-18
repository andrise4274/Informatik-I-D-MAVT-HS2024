#include <iostream>
#include "loop.h"

// Fill out the file with the required answers


/*

  Subtask 1: Describe the output of the program as a function of its input n.

  the program calculates f(n) = 2^n

*/

/*

  Subtask 2: For which values of n do you expect a correct output x? Explain why.

  for all n > 0, the correct result of 2^n is calculated

*/


/*

  Subtask 3: Show that this program terminates for all values of n found in (2).
  
  for n = 0: the first if statement returns false --> returns 2^0 = 1
  for n = 1: the do while loop runs once, calculating 2^1 = 1 * 2
  
  for n - 1: the program goes once less through the do loop, as for n
    --> terminates one step earlier, so it can't terminate earlier than
    the 0th iteration, so all values below 0 terminate before the first iteration
    
  
*/

/*
  Subtask 4: Provide a more elegant implementation of this function using 
  another type of loop.
*/

void loop(){
  
  int n;
  std::cin >> n;
  
  int x = 1;
  for (int i = 0; i < n; i++) {
    x *= 2;
  }
  std::cout << x << std::endl;
  
}

