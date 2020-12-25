#include "polygon.h"

double Polygon::primeter() const {
  double result = Primeter(_vertices,_numVertices);
  return result;
}

double Polygon::area() const {
  double result = Area(_vertices,_numVertices);
  return result;
}