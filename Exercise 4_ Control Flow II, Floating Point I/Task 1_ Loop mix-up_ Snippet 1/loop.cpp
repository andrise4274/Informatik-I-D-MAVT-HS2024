#include <iostream>
#include "loop.h"

// Fill out the file with the required answers


/*

  Subtask 1: describe what the code snippet computes
  
  This functions computes the n!: while n > 0 the result f is 
  multiplied with n, then n-2 then n-3 and so on
  
*/

/*

  Subtask 2: decide which of the other two kind of loops would fit better, and
  describe why.
  
  the while loop would fit better, 
  because one could remove the if condition

*/


/*
  Subtask 3: update the function below by rewriting the snippet into the 
  loop you specified in (2)
*/

void loop(){
  
  int n;
  std::cin >> n;
  int f = 1;
    while (n > 0){
      f = f * n;
      --n;
    }
  std::cout << f << std::endl;

}
