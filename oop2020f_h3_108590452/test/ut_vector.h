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

TEST(CHKVECTOR, caseNormalInput1) {
  MathVector test = MathVector();
  ASSERT_EQ(0, test.getDim());
}

TEST(CHKVECTOR, caseNormalInput2) {
  double input1[5] = {1, 0, 4, 1, 0};
  MathVector test = MathVector(input1, 5);
  ASSERT_EQ(5, test.getDim());

  ASSERT_EQ(1, test.component(1));
  ASSERT_EQ(0, test.component(2));
  ASSERT_EQ(4, test.component(3));
  ASSERT_EQ(1, test.component(4));
  ASSERT_EQ(0, test.component(5));
}

TEST(CHKDOT, caseNormalInput1) {
  double u[]={1, 0, 2};
  double v[]={1, 1, 3};

  ASSERT_EQ(7, dot(u, 3, v, 3));
}

TEST(CHKDOT, caseNormalInput2) {
  double u[]={1, 1, 2, 5};
  double v[]={1, 4, 3, 6};

  ASSERT_EQ(41, dot(u, 4, v, 4));
}

TEST(CHKDOT, caseNotNormalInput1) {
  double input[3] = {1,1,0};
  double input1[2] = {1,0};
  try{
    double result = dot(input, 3, input1, 2);
    FAIL() << "Shuold not be here"; // added before class
  }catch(std::string s){
    ASSERT_EQ("undefined",s);
  }
}

TEST(CHKDOT, caseNotNormalInput2) {
  double input[3] = {};
  double input1[5] = {1,0,4,1,0};

  try{
    double result = dot(input, 3, input1, 5);
    FAIL() << "Shuold not be here"; // added before class
  }catch(std::string s){
    ASSERT_EQ("undefined", s);
  }
}

TEST(CHKCOMPONENT, case1) {
  double input1[5] = {1, 2, 2, 6, 7};
  MathVector test = MathVector(input1, 5);
  ASSERT_EQ(5, test.getDim());

  ASSERT_EQ(1, test.component(1));
  ASSERT_EQ(2, test.component(2));
  ASSERT_EQ(2, test.component(3));
  ASSERT_EQ(6, test.component(4));
  ASSERT_EQ(7, test.component(5));
}

TEST(CHKISZERO, case1) {
  MathVector test = MathVector();
  ASSERT_TRUE(test.isZero());
}

TEST(CHKISZERO, case2) {
  double input1[5] = {1, 2, 2, 6, 7};
  MathVector test = MathVector(input1, 5);
  ASSERT_FALSE(test.isZero());
}

TEST(CHKLENGTH, case1) {
  double input1[2] = {1, 2};
  MathVector test = MathVector(input1, 2);
  ASSERT_NEAR(2.236, test.length(), 0.5);
}

TEST(CHKLENGTH, case2) {
  double input1[5] = {1, 2, 2, 6, 7};
  MathVector test = MathVector(input1, 5);
  ASSERT_NEAR(9.695, test.length(), 0.5);
}

TEST(CHKDIM, case1) {
  double input1[2] = {1, 2};
  MathVector test = MathVector(input1, 2);
  ASSERT_EQ(2, test.getDim());
}

TEST(CHKDIM, case2) {
  double input1[5] = {1, 2, 2, 6, 7};
  MathVector test = MathVector(input1, 5);
  ASSERT_EQ(5, test.getDim());
}
