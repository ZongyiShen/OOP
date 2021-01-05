#ifndef SHAPE
#define SHAPE
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// base class to Polygon & Circle
// no instance -> abstrct class, aka interface
class Shape {
protected:
  string _name;
public:
  Shape(){
    //cout << "Constructor in Shape" << endl;
    _name = "nothing";
  }
  Shape(string name){
    _name = name;
  }
  virtual ~Shape(){
    //cout << "Shape deconstructor" << endl;
  }
  virtual double getArea() const = 0; // virtual == no definition
  virtual double getPrimeter() const = 0;
  string getName() const {
    return _name;
  }
  virtual void changeNameTo(string input) = 0;
  virtual string toString() const {
    return "";
  }
  virtual void fromString(stringstream &s) = 0;
};

vector <Shape*>objectsFromFile(string fileName){
  ifstream ifs(fileName);

  vector<Shape*>result;

  
  return result;
}

#endif
