#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include "bubblesort.h"
#include<cmath>

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
	int dim();

	double & at(int i) const;

	void subtract(Vector const & v);

	void add(Vector const & v);

	Vector & operator = (Vector const & u);

	Vector operator - (Vector const & v) const;

	Vector operator + (Vector const & v) const;

	double length() const;

	double dot(Vector input);

	bool larger180(Vector input);

  	double angle(Vector input);

	friend 	Vector centroid(Vector vec[], int sides) ;


	friend double distance(Vector u, Vector v);


	friend double Area(Vector u, Vector v, Vector w);


	friend double Area(Vector a[], int sides)	;


	friend double Primeter(Vector a[], int sides)	;


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



Vector centroid(Vector vec[], int sides) ;

double distance(Vector u, Vector v);

double Area(Vector u, Vector v, Vector w);

double Area(Vector a[], int sides);

double Primeter(Vector a[], int sides);


#endif
