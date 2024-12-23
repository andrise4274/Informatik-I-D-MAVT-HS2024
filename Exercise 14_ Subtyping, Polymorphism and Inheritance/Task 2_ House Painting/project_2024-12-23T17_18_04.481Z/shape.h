#pragma once

class Shape {
public:
  Shape(bool p);

  // PRE: -
  // POST: Returns true is area is paintable.
  bool can_paint() const;

  // PRE: -
  // POST: Returns the area of the shape.
  virtual double get_area() const = 0;

  // PRE: -
  // POST: Returns the area of the shape, negated iff area is not
  //       paintable.
  double get_signed_area() const;

  virtual ~Shape() = default;

private:
  const bool paintable;
};
