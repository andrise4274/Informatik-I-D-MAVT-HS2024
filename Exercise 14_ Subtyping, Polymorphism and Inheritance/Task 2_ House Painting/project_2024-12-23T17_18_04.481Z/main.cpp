#include <iostream>
#include <vector>
#include "house_shapes.h"

int main() {
  std::vector<Shape*> shapes = std::vector<Shape*>();

  // parse test data in the following format until end marker is found:
  // <add/remove> <shape> <parameter 1> <parameter 2>
  // where <parameter 2> is optional
  char sign;
  while (std::cin >> sign && (sign == '+' || sign == '-')) {
    bool is_paintable = sign == '+';
    
    std::string shape = std::string();
    std::cin >> shape;
    
    if (shape == "triangle") {
      double width, height;
      std::cin >> width >> height;

      shapes.push_back(new Triangle(is_paintable, width, height));
        
    } else if (shape == "rectangle") {
      double width, height;
      std::cin >> width >> height;

      shapes.push_back(new Rectangle(is_paintable, width, height));
        
    } else if (shape == "circle") {
      double radius;
      std::cin >> radius;

      shapes.push_back(new Circle(is_paintable, radius));
        
    } else {
      std::cout << "unknown shape: " << shape << "\n";
      break;
    }
  }

  // calculate area to be painted
  double area = 0;
  for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it) {
    area += (*it)->get_signed_area();
  }
  std::cout << "Paintable area:\n" << area << "\n";

  // clean up allocated shape objects
  for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it) {
    delete *it;
  }
  return 0;
}
