#include "convexPolygon.h"

int Polygon::getNumberOfVerties() const {
  return _numVertices;
}

double Polygon::getPrimeter() const {
  double primeter = 0;
  for (int i = 0; i < _numVertices; i++) {
    primeter += (_vertices[(i+1)%_numVertices] - _vertices[i]).length();
  }
  return primeter;
}

double Polygon::getArea() const {
  double area = 0;
  for (int i  = 0; i < (_numVertices - 2); i++ ){
    area += _vertices[0].getArea(_vertices[i+1], _vertices[i+2]);
  }
  return area;
}

mathVector Polygon::centroid(){
  mathVector cent(_vertices->dimension());
  for(int j=0;j<_vertices->dimension();j++){
    for(int i=0;i<_numVertices;i++){
      cent.component(j+1)+=_vertices[i].component(j+1);
    }
    cent.component(j+1) /= _numVertices;
  }

  return cent;
}

void Polygon::changeNameTo(string input){
  _name=input;
}

string Polygon::toString(){
   stringstream ss;
   ss<<"Polygon" << "{\n" << _name  <<"\n" << _numVertices <<"\n"<<"}";
   return ss.str();
}

void Polygon::fromString(stringstream &s) {
    string type;
    char c;
    s >> type >> c;
    s >> _name;
    s >> _numVertices;
    for(int i = 0 ; i < _numVertices; i++){
      s >> _vertices[i];
    }
    s >> c;
  }