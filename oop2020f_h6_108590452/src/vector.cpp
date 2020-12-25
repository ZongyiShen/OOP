#include "bubblesort.h"
#include "vector.h"
#include "bubblesort.cpp"


int Vector::dim() {
    return _dim;
  }
double & Vector::at(int i) const{
	return _v[i-1];
}

void Vector::subtract(Vector const & v){
	if (v._dim != _dim){
		throw std::string("Length Error");
	}
	for (int i = 0; i < _dim; i++) {
		_v[i]=_v[i]-v._v[i];
	}
}

void Vector::add(Vector const & v){
	if (v._dim != _dim){
		throw std::string("Length Error");
	}
	for (int i = 0; i < _dim; i++) {
		_v[i]=_v[i]+v._v[i];
	}
}

Vector & Vector::operator = (Vector const & u){
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

Vector Vector::operator - (Vector const & v) const{
		Vector result(*this);
		result.subtract(v);
		return result;
}

Vector Vector::operator + (Vector const & v) const{
	Vector result(*this);
	result.add(v);
	return result;
}

double Vector::length() const{
    double accumulate = 0;
    for(int i = 0;i < _dim;i++) {
      accumulate += pow(_v[i], 2);
    }
    return sqrt (accumulate);
}

double Vector::dot(Vector input) {
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

bool Vector::larger180(Vector input){
    return (this->at(1)*input.at(2) - this->at(2)*input.at(1))>=0;
}
double Vector::angle(Vector input){
    double sumofdot = this->dot(input);
    double mulen = this->length() * input.length();
    if(this->larger180(input)){
      return 360-acos(sumofdot/mulen)*180/M_PI;
    }
    return acos(sumofdot/mulen)*180/M_PI;
}

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

double Area(Vector u, Vector v, Vector w) // 回傳三個 vector 所圍成的三角形面積
{
		double A = (u-v).length();
    double B = (v-w).length();
    double C = (w-u).length();
    double S = (A + B + C) / 2;
    return sqrt(S*(S-A)*(S-B)*(S-C));

}

double Area(Vector a[], int sides)		// 回傳多個 vector 所圍成的多邊形面積
{
	Vector center = centroid(a,sides);
	Vector b = a[0] - center;
  angleComparator comp = angleComparator(center, b);
  BubbleSort(a,a+sides,comp);

	double ans = 0;
    for (int i  = 0; i < (sides - 2); i++ ){

				double temp = Area(a[0],a[i+1], a[i+2]);
				ans+=temp;

    }
    return ans;

}

double Primeter(Vector a[], int sides)	// 回傳多個 vector 所圍成的多邊形周長
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