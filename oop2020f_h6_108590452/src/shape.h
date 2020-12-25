#ifndef SHAPE
#define SHAPE
#include<string>
#include<iostream>
#include<vector>
using namespace std;

// base class to Polygon & Circle
// no instance -> abstrct class, aka interface
class Shape {
protected:
  string _name;
public:
  Shape(){
    cout << "Constructor in Shape" << endl;
    _name = "nothing";
  }
  Shape(string name){
    _name = name;
  }
  virtual ~Shape(){
    cout << "Shape deconstructor" << endl;
  }
  virtual double area() const = 0; // virtual == no definition
  virtual double primeter() const = 0;
  string getName() const;
  //virtual void changeNameTo(string input) = 0;
  // virtual string toString() const{
  //   return "";
  // }
};
template<class RandomAccessIterator,class Condition>
vector<Shape *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond) {
  vector<Shape *> result;
  for (int i = 0; i < end-begin; i++)
  {
    if (cond(*(begin+i)))
    {
      result.push_back(*(begin+i));
    }

  }
  return result;
}


#endif
