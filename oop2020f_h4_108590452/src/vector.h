#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include<cmath>
class Vector {
public:
	Vector(double v[], int dim) {
		_v = new double[dim];
    for(int i=0;i<dim;i++){
      _v[i] = v[i];
    }
    _dim = dim;

	}

	Vector(Vector const & v){
		_v = new double[v._dim];
    for(int i=0;i<v._dim;i++){
      _v[i] = v._v[i];
    }
    _dim = v._dim;
	}

	// destructor
	~Vector() {
		if(_v !=NULL)
		delete []_v;
	}

	// constant member function
	int dim() {
    return _dim;
  }

	double & at(int i) const{
		return _v[i-1];
	}

	void subtract(Vector const & v){
		if (v._dim != _dim){
			throw std::string("Length Error");
		}
		for (int i = 0; i < _dim; i++) {
			_v[i]=_v[i]-v._v[i];
		}
	}

	void add(Vector const & v){
		if (v._dim != _dim){
			throw std::string("Length Error");
		}
		for (int i = 0; i < _dim; i++) {
			_v[i]=_v[i]+v._v[i];
		}
	}

	Vector & operator = (Vector const & u){
    if(_v != NULL) {
      delete [] _v;
    }

    _dim = u._dim;
    _v = new double[_dim];
    for(int i=0;i<_dim;i++){
      _v[i] = u._v[i];
    }
    return *this;
	}

	Vector operator - (Vector const & v) const{
		Vector result(*this);
		result.subtract(v);
		return result;
	}

	Vector operator + (Vector const & v) const{
		Vector result(*this);
		result.add(v);
		return result;
	}

	double length() const{
    double accumulate = 0;
    for(int i = 0;i < _dim;i++) {
      accumulate += pow(_v[i], 2);
    }
    return sqrt (accumulate);
  }


private:
	int _dim;
	double * _v;
	//void copy(int dim, double v[]){...}
};

#endif
