#include "circle.h"
double Circle::primeter() const {
  double result = 2*_radius*M_PI;
  return result;
}

double Circle::area() const {
  double result = _radius*_radius*M_PI;
  return result;
}