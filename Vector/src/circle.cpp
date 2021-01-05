#include "circle.h"

double Circle::getPrimeter()const {
  return 2*_radius*M_PI;
}
double Circle::getArea()const {
  return _radius*_radius*M_PI;
}
void Circle::changeNameTo(string input){
  _name=input;
}
string Circle::toString(){
   stringstream ss;
   ss<<"Circle" << "{\n" << _name << "\n" << _point <<"\n" << _radius <<"\n"<<"}";
   return ss.str();
}