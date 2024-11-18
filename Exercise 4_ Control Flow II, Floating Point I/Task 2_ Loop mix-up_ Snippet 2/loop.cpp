#include <iostream>
#include "loop.h"

// Fill out the file with the required answers


/*

  Subtask 1: describe what the code snippet computes

  In an infinite for loop, thwo integers are read in, and their sum is computed
  then the user is asked if it the whole program 
  should start again (new loop iteration)
  
  the user can end/break out the infinite loop by typing 0 into the console

*/

/*

  Subtask 2: decide which of the other two kind of loops would fit better, and
  describe why.

  
  do while() would fit better, since it is a classic example
  of a loop which should iterate at least once, and could iterate 
  more dependant on the condition.
  
*/


/*
  Subtask 3: update the function below by rewriting the snippet into the 
  loop you specified in (2).
  Note: print the control message "Again? (0/1)" using the same format used
  in the snippet.
*/

void loop(){
  int again;
  
  do{
    int i1, i2;
    std::cin >> i1 >> i2;
    std::cout << i1 + i2 << "\n";
    std::cout << "Again? (0/1)\n";
    std::cin >> again;
  } while (again != 0);
}
