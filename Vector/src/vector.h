#ifndef VECTOR
#define VECTOR
#include <cmath>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Polygon;
class mathVector {

private:
  double *content;
  int len;
  void initialize(double* input, int l){
    content = new double[l];
    for(int i=0;i<l;i++){
      content[i] = input[i];
    }
    len = l;
  }

public:
  friend mathVector centroid(mathVector vectors[], int num);
  //friend class Polygon;
  mathVector() {//constructer
    //content = {};
    len = 0;
    content = new double[len];
  }

  mathVector(int l){
    len = l;
    content = new double[len];
    for (int i = 0;i < len;i++) {
      content[i] = 0;
    }
  }

  mathVector(double* input, int l) { //constructer
    initialize(input, l);
  }

  mathVector(mathVector const &input) { //copy constructer
    //printf("copy constructer \n");

    initialize(input.vector(), input.len);

  }

  ~mathVector() {//destructer
    if(content != NULL) {
      delete [] content;
    }
  }
  int dimension() const;
  double* vector() const;
  void setDimension(int input);
  double & component(int index) const;
  double dot(mathVector input);
  double length();
  double getArea(mathVector inputA, mathVector inputB);
  bool larger180(mathVector input);
  double angle(mathVector input);
  static mathVector centroid(mathVector vectors[], int num);
  mathVector & operator = (mathVector const &input);
  mathVector operator -(const mathVector &input);
  friend ostream & operator << (ostream & output, const mathVector & vec);
  friend istream & operator >> (istream & input,  mathVector & vec);
};

class angleComparator{
  private:
    mathVector _a;
    mathVector _b;
  public:

    angleComparator(){

    }

    angleComparator(mathVector &a, mathVector &b){
      _a = a;
      _b = b;
    }

    bool operator ()(mathVector &u, mathVector &v){
      return _b.angle(u-_a)<_b.angle(v-_a);
    }
};

#endif
