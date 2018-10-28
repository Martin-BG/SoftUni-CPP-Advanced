#ifndef CPP_ADVANCED_SHAPE_H
#define CPP_ADVANCED_SHAPE_H

#include <iomanip>
#include "Vector2D.h"

class Shape {
private:
  const Vector2D center;
protected:
  double area;
public:
  Shape() : center(Vector2D(0.0, 0.0)), area(0.0) { };

  explicit Shape(const Vector2D& center) : center(center), area(0.0) { }

  virtual ~Shape() = default;

  std::string getCenter() const {
    return this->center;
  }

  double getArea() const {
    return this->area;
  }
};

#endif //CPP_ADVANCED_SHAPE_H
