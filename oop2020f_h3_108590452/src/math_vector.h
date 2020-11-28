#include <cmath>

class MathVector {
private:
	double * _vec;
	int _dim;

public:
	MathVector(){
		_vec = 0;
		_dim=0;
	}

  MathVector(double a[], int dim){
    _dim = dim;
    _vec = new double[_dim];
    for( int i = 0; i < _dim; i++){
      _vec[i] = a[i];
    }
  }

  double component(int index)const{
    return _vec[index-1];
  }

  double dot(MathVector input) {
    double result = 0;
              //input.len also works, beacuse
              // input is an object of the same class
    if(_dim != input.getDim()){
      throw std::string("ERROR");
    }
    for(int i=0;i<_dim;i++) {
      result += _vec[i] * input._vec[i];
    }

    return result;
  }

  bool isZero()const{
    for( int i=0;i<_dim;i++){
      if(_vec[i]!=0)
        return false;
    }
    return true;
  }

  double length()const{
    double result=0;
    for(int i=0;i<_dim;i++){
      result += pow(_vec[i],2.0);
    }

    return sqrt(result);
  }

  int getDim()const{
    return _dim;
  }
  ~MathVector(){
    if(_vec != NULL)
      delete [] _vec;
  }
};
