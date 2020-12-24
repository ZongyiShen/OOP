#include "polygon.h"

double Polygon::perimeter() const {
  double result = Perimeter(_vertices,_numVertices);
  return result;
}

double Polygon::area() const {
  double result = Area(_vertices,_numVertices);
  return result;
}