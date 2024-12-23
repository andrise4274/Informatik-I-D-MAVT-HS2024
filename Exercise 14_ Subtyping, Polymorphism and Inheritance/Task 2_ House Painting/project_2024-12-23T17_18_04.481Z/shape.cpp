#include "shape.h"

Shape::Shape(bool p) : paintable(p) {}

bool Shape::can_paint() const {
  return paintable;
}

double Shape::get_signed_area() const {
  double a = get_area();
  if (can_paint()) {
    return a;
  } else {
    return -a;
  }
}


