#include "dot.h"


double dot(double* input,int len, double* input1,int len2){
  double output=0;

  //cout << sizeof(input); // added
  //cout << sizeof(double); // added

  if(len != len2){
    throw string("ERROR");
  }
  for(int i=0;i<len;i++){
    output += input[i] * input1[i];
  }
  return output;
}

double dot(mathVector const & a, mathVector const & b) {
  double output=0;

  for(int i=1;i<=a.dimension();i++){
      output += a.component(i) * b.component(i);
  }
  return output;
}
