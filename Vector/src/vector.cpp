#include "./vector.h"

mathVector & mathVector::operator = (mathVector const &input) { //operator overloadding for copy assignment
  //printf("copy assignment \n");
  if(content != NULL) {
    delete [] content;
  }

  len = input.len;
  //this->len = input.len;
  //(*this).len = input.len;
  content = new double[len];
  for(int i=0;i<len;i++){
    content[i] = input.vector()[i];
  }
  return *this;
}

mathVector mathVector::operator -(const mathVector &input) {
  if(this->len != input.len){
    throw std::string("Error in Length");
  }

  mathVector result = *this; // copy constructer

  for (int i = 1; i <= len; i++) {
    result.component(i) -= input.component(i);
  }

  return result;
}

int mathVector::dimension() const {//getter
  return len;
}

double* mathVector::vector() const {
  return content;
}

void mathVector::setDimension(int input) // setter
{
  len = input;
}

double & mathVector::component(int index) const {
  return content[index-1];
}

double mathVector::dot(mathVector input) {
  double result = 0;
            //input.len also works, beacuse
            // input is an object of the same class
  if(len != input.dimension()){
    throw string("ERROR");
  }
  for(int i=0;i<len;i++) {
                          // input.content[i] also works, beacuse
                          // input is an object of the same class
    result += content[i] * input.vector()[i];
  }

  return result;
}

double mathVector::length(){
  double l = 0;
  for (int i = 0; i < len; i++) {
    l += content[i]*content[i];
  }
  return sqrt(l);
}

double mathVector::getArea(mathVector inputA, mathVector inputB){
  double A = (inputA - *this).length();
  double B = (inputB - *this).length();
  double C = (inputA - inputB).length();
  double S = (A + B + C) / 2;
  return sqrt(S*(S-A)*(S-B)*(S-C));
}

bool mathVector::larger180(mathVector input){
  return (this->component(1)*input.component(2) - this->component(2)*input.component(1))>=0;
}

double mathVector::angle(mathVector input){
  double sum1=0,sum2=0;
  sum1 = this->dot(input);
  sum2 = this->length() * input.length();
  if(this->larger180(input)){
    return 360-acos(sum1/sum2)*180/M_PI;
  }
  return acos(sum1/sum2)*180/M_PI;
}

mathVector mathVector::centroid(mathVector vectors[], int num){ // static function
  mathVector sum(2);
  for(int i=0;i<num;i++){
    sum.component(1) += vectors[i].component(1);
    sum.component(2) += vectors[i].component(2);
    //sum += vectors[i];
  }
  sum.component(1) /= num;
  sum.component(2) /= num;
  //sum /= num;
  return sum;
}

// Friend Function
ostream & operator << (ostream & output, const mathVector & vec){
  output << "(";
  output << vec.content[0];
  for(int i=1;i<vec.len;i++){
    output << "," << vec.content[i];
  }
  output <<")";
  return output;
}
// Assume input.str() -> {2,5,5} // len + point
istream & operator >> (istream & input, mathVector & vec){
  int len = 0;
  //string ipt = input.str();
  //input = cin
  char c;
  double v;
  input >> c >> len;
  double vs[len];
  for(int i=0;i<len;i++){
    input >> c >> v;
    vs[i] = v;
  }
  input >> c;
  vec.initialize(vs, len);
  /*
  ipt = ipt.replace(ipt.length()-1, 1, "");
  ipt = ipt.replace(0, 1, "");
  while()
  ipt = ipt.replace(ipt.find(","), 1, "");
  ipt = ipt.replace(ipt.find(","), 1, "");
  stringstream ss;
  ss <<
  */
  return input;
}

