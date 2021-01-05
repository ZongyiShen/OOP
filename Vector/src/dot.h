#ifndef DOT
#define DOT
#include <string>
#include <iostream>
#include "shape.h"
#include "vector.h"

using namespace std;

double dot(double* input, int len, double* input1, int len2);

double dot(mathVector const & a, mathVector const & b); // not call copy constructor
// //double dot(mathVector a, mathVector b); // copy constructor will be called



#endif
