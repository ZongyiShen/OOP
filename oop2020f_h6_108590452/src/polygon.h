#ifndef POLYGON
#define POLYGON
#include "vector.h"
#include "bubblesort.h"
#include "shape.h"


class Polygon :public Shape{
private:
  int _numVertices;
  Vector * _vertices;
protected:
  

public:
Polygon(){
    _numVertices = 0;
    _vertices = new Vector[_numVertices];
}

Polygon( Vector * input ,int inputVerties){
    _numVertices = inputVerties;
    _vertices = new Vector[_numVertices];
    for (int i = 0; i < _numVertices; i++) {
     _vertices[i] = input[i];
    }
}

double primeter() const override;


double area() const override;

};


  

#endif
