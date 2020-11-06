#ifndef VECTOR
#define VECTOR

using namespace std;

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
  mathVector() {//constructer
    //content = {};
    len = 0;
    content = new double[len];
  }

  mathVector(int l){
    len = l;
    content = new double[len];
  }

  mathVector(double* input, int l) { //constructer
    initialize(input, l);
  }

  mathVector(mathVector const &input) { //copy constructer
    printf("copy constructer \n");

    initialize(input.vector(), input.len);

  }

  mathVector & operator = (mathVector const &input) { //operator overloadding for copy assignment
    printf("copy assignment \n");
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

    return *this; // we will discuss more abuot this
  }

  ~mathVector() {//destructer
    if(content != NULL) {
      delete [] content;
    }
  }

  int dimension() const {//getter
    return len;
  }

  double* vector() const {
    return content;
  }

  void setDimension(int input) // setter
  {
    len = input;
  }

  double & component(int index) const {
    return content[index];
  }

  double dot(mathVector input) {
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
};

#endif
