#pragma once

#include "shape.h"

class Triangle : public Shape {
public:
  Triangle(bool cP, double w, double h);
  
private:
  // local variables width and height, printable is inherited from shapes (with const keyword necessary)
  double w;
  double h;
  // override get_area() function from Shape class
  double get_area() const;
};


class Rectangle : public Shape {
public:
  Rectangle(bool cP, double w, double h);
  
private:
  // local variables width and height, printable is inherited from shapes (with const keyword necessary)
  double w;
  double h;
  // override get_area() function from Shape class
  double get_area() const;
};


class Circle : public Shape {
public:
  Circle(bool cP, double r);
  
private:
  // local variable radius, printable is inherited from shapes
  double r;
  // override get_area() function from Shape class (with const keyword necessary)
  double get_area() const;
};
