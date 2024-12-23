#include <cmath>
#include "house_shapes.h"

const double pi = 4.0 * atan(1.0);



// constructors - implements a Shape class with the printable variable
// assigned to cP via calling original constructor of parent class shape

Triangle::Triangle(bool cP, double w, double h) : Shape(cP), w(w), h(h) {}
Rectangle::Rectangle(bool cP, double w, double h) : Shape(cP), w(w), h(h) {}
Circle::Circle(bool cP, double r) : Shape(cP), r(r) {}


// member functions
// need const keyword
double Triangle::get_area() const {
  return w * h / 2;
}


double Circle::get_area() const {
  return r * r * pi;
}

double Rectangle::get_area() const {
  return w * h;
}