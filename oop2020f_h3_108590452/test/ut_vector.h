#include "../src/math_vector.h"
#include "../src/dot.h"
#include <cmath>

TEST(CHKDOT, case1) {
  double u[3]={1, 0, 2};
  double v[3]={1, 1, 3};

  ASSERT_EQ(7, dot(u, 3, v, 3));
}

TEST(CHKDOT, case2){
  double input[3] = {1,1,0};
  double input1[2] = {1,0};
  try{
    double result = dot(input, 3, input1, 2);
    FAIL() << "Shuold not be here"; // added before class
  }catch(std::string s){
    ASSERT_EQ("undefined",s);
  }
}

TEST(CHECKVETOR, case1) {// getDim component
  double u[]={1, 0, 2};
  MathVector w= MathVector(u,3);
  ASSERT_EQ(3, w.getDim());
  ASSERT_EQ(1, w.component(1));
}

TEST(CHECKVETOR, case2) {//isZero
  double u[]={0, 0, 0};
  MathVector w= MathVector(u,3);
  ASSERT_EQ(true, w.isZero());
  double v[]={1, 0, 0};
  MathVector x= MathVector(u,3);
  ASSERT_EQ(true, x.isZero());
}

TEST(CHECKVETOR, case3) {// length
  double u[]={3, 4};
  MathVector w= MathVector(u,2);
  ASSERT_EQ(5.0, w.length());

}
