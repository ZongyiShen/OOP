#ifndef CIRCLE
#define CIRCLE
#include <cmath>
#include "shape.h"
#include "vector.h"

using namespace std;

// Dervied class of shape class
// Circle inherets Shape
class Circle : public Shape {
private:
  double _radius;
  Vector _point;
public:
  Circle() : _radius(0){
    cout << "Constructor in circle" << endl;
    _point = Vector();
  }

  Circle(double input) : _radius(input){
    cout << "Constructor in circle" << endl;
    _point = Vector();
  }

  Circle(double radius, Vector point, string name) : Shape(name){ //constructor initialization list
    _radius = radius;
    _point = point;
  }

  ~Circle() override {
    cout << "Circle deconstructor" << endl;
  }

  double primeter() const override ;
  double area() const override;
};


#endif