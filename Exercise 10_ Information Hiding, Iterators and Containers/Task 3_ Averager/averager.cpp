#include "averager.h"

// Write implementation of methods of class Averager here
    
void Averager::add_value(double value) {
  sum += value;
  count ++;
}

double Averager::get_average() {
  if (count == 0) {
    return 0.0;
  }
  return sum / count;
}

void Averager::reset() {
  sum = 0.0;
  count = 0;
}
