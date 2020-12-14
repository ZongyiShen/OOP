#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include<cmath>
#include "../src/bubblesort.h"
class Vector {
public:
	Vector(){
		_dim = 0;
    		_v = new double[_dim];
	}

	Vector(double v[], int dim) {
		_v = new double[dim];
		    for(int i=0;i<dim;i++){
		      _v[i] = v[i];
		    }
		    _dim = dim;

	}

	Vector(int dim){
		_v = new double[dim];
		for(int i=0;i<dim;i++){
      			_v[i] = 0;
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

	double dot(Vector input) {
    double result = 0;
              //input.len also works, beacuse
              // input is an object of the same class
    if(_dim != input.dim()){
      throw std::string("ERROR");
    }
    for(int i=0;i<_dim;i++) {
                            // input.content[i] also works, beacuse
                            // input is an object of the same class
      result += _v[i] * input._v[i];
    }

    return result;
  }

	bool larger180(Vector input){
    return (this->at(1)*input.at(2) - this->at(2)*input.at(1))>=0;
  }
  double angle(Vector input){
    double sumofdot = this->dot(input);
    double mulen = this->length() * input.length();
    if(this->larger180(input)){
      return 360-acos(sumofdot/mulen)*180/M_PI;
    }
    return acos(sumofdot/mulen)*180/M_PI;
  }
	friend 	Vector centroid(Vector vec[], int sides) ;


	friend double distance(Vector u, Vector v);


	friend double area(Vector u, Vector v, Vector w);


	friend double area(Vector a[], int sides)	;


	friend double perimeter(Vector a[], int sides)	;


private:
	int _dim;
	double * _v;
	//void copy(int dim, double v[]){...}
};

class angleComparator{
  private:
    Vector _a;
    Vector _b;
  public:

    angleComparator(Vector &a, Vector &b){
      _a = a;
      _b = b;
    }

    bool operator ()(Vector &u, Vector &v){
      return _b.angle(u-_a)<_b.angle(v-_a);
    }
};



Vector centroid(Vector vec[], int sides) 	// 回傳多個 vector 所組成的重心
{
	Vector center=Vector(vec[0]._dim);
	for (int i = 0; i < sides; i++) {
		center=center+vec[i];
	}
	for (int i = 0; i < center._dim; i++) {
		center._v[i]/=sides;
	}
	return center;
}

double distance(Vector u, Vector v)		// 回傳兩個 vector 的距離
{
	if (v._dim != u._dim){
		throw std::string("Length Error");
	}
	// Vector temp=u-v;
	// double dis=0;
	// for (int i = 0; i < v._dim; i++) {
	// 	 dis +=temp._v[i]*temp._v[i];
	// }
	// return sqrt(dis);
	return (u-v).length();

}

double area(Vector u, Vector v, Vector w) // 回傳三個 vector 所圍成的三角形面積
{
		double A = (u-v).length();
    double B = (v-w).length();
    double C = (w-u).length();
    double S = (A + B + C) / 2;
    return sqrt(S*(S-A)*(S-B)*(S-C));

}

double area(Vector a[], int sides)		// 回傳多個 vector 所圍成的多邊形面積
{
	Vector center = centroid(a,sides);
	Vector b = a[0] - center;
  angleComparator comp = angleComparator(center, b);
  BubbleSort(a,a+sides,comp);

	double ans = 0;
    for (int i  = 0; i < (sides - 2); i++ ){

				double temp = area(a[0],a[i+1], a[i+2]);
				ans+=temp;

    }
    return ans;

}

double perimeter(Vector a[], int sides)	// 回傳多個 vector 所圍成的多邊形周長
{
		Vector center = centroid(a,sides);
		Vector b = a[0] - center;
		angleComparator comp = angleComparator(center, b);
		BubbleSort(a,a+sides,comp);

		double primeter = 0;
    for (int i = 0; i < sides; i++) {
      primeter += (a[(i+1)%sides] - a[i]).length();
    }
    return primeter;

}


#endif
