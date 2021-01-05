#ifndef POLYGON
#define POLYGON
#include "vector.h"
#include "bubblesort.h"
#include "shape.h"


class Polygon :public Shape{
private:
  int _numVertices;
  mathVector * _vertices;
protected:
  Polygon(int inputVerties, mathVector * input){
      _numVertices = inputVerties;
      _vertices = new mathVector[_numVertices];
      for (int i = 0; i < _numVertices; i++) {
        _vertices[i] = input[i];
      }
  }

public:
  friend class PolygonFactory;

  static Polygon CreatePolygon(int numVertices,mathVector * input){
      mathVector c = mathVector::centroid(input, numVertices);
      mathVector b = input[0] - c;
      // angleComparator comp = angleComparator(c, b);
      // std::sort(input,input+numVertices,comp);
      // BubbleSort(input,input+numVertices,comp);
      //BubbleSort(input,input+numVertices,[&c,&b] (mathVector&i,mathVector&j)
      BubbleSort(input,input+numVertices,[c,b] (mathVector&i,mathVector&j)mutable{
        return b.angle(i-c) < b.angle(j-c);
      });
      return Polygon(numVertices,input);
  }

  Polygon(){
    _numVertices = 0;
    _vertices = new mathVector[_numVertices];
  }



  int getNumberOfVerties() const ;

  double getPrimeter() const override;


  double getArea() const override;


  mathVector centroid();

  void changeNameTo(string input)override;

  string toString();

  void fromString(stringstream &s) override;
  
};




// class PolygonFactory:public mathVector{
class PolygonFactory{
public:
  friend mathVector;
  Polygon CreatePolygon(mathVector vertices[],int num){
    mathVector c = mathVector::centroid( vertices , num );
    //try to make centrid as friend
    mathVector b = vertices[0] - c;
    angleComparator comp = angleComparator(c, b);
    BubbleSort(vertices,vertices+num,comp);
    return Polygon(num,vertices);
  }
};

class Triangle:public Polygon{
public:
  mathVector _centroid;

  Triangle(mathVector*v):Polygon(3,v){
    _centroid=this->centroid();
  }
  mathVector getCentroid(){
    return _centroid;
  }
};

#endif
