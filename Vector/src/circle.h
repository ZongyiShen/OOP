#ifndef CIRCLE
#define CIRCLE
#include <cmath>
#include "shape.h"
#include "vector.h"

using namespace std;

// Dervied class of shape class
// Circle inherets Shape
// **public** inheritance makes public members of the base class public in the derived class, and the protected members of the base class remain protected in the derived class.
// **protected** inheritance makes the public and protected members of the base class protected in the derived class.
// **private** inheritance makes the public and protected members of the base class private in the derived class.

class Circle : public Shape {
private:
  double _radius;
  mathVector _point;
public:
  Circle() : _radius(0){
    cout << "Constructor in circle" << endl;
    _point = mathVector();
  //  _radius = 0;
  }
  Circle(double radius, mathVector point, string name) : Shape(name){ //constructor initialization list
    _radius = radius;
    _point = point;
  }

  ~Circle() override {
    cout << "Circle deconstructor" << endl;
  }

  double getPrimeter() const override ;
  double getArea() const override;
  void changeNameTo(string input) override ;
  string toString();
  void fromString(stringstream &s)override{ //copy constructor
    s >>_point;
  }
};




#endif
