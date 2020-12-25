#include "../src/vector.h"
#include "../src/bubblesort.h"
#include <cmath>
#include <string>
#include <algorithm>

TEST(CHKCONSTRUCTOR,case1){//constructor , dim and at function
  double a[2]={1.0,2.0};
  Vector v(a,2);
  ASSERT_EQ(2, v.dim());
  ASSERT_EQ(1.0, v.at(1));
  ASSERT_EQ(2.0, v.at(2));
}

TEST(CHKFUNC,AddSubLen){
  double a[2]={3.0,4.0};
  Vector v(a,2);
  double b[2]={2.0,-4.0};
  Vector u(b,2);
  v.subtract(u);
  ASSERT_EQ(1, v.at(1));
  ASSERT_EQ(8, v.at(2));
  v.add(u);
  ASSERT_EQ(3, v.at(1));
  ASSERT_EQ(4, v.at(2));
  ASSERT_EQ(5, v.length());
}

TEST(CHKERROR,LengthError){
  double a[2]={3.0,4.0};
  Vector v(a,2);
  double b[1]={2.0};
  Vector u(b,1);
  try{
    v.add(u);
    FAIL() << "Shuold not be here"; // added before class
  }catch(std::string s){
    ASSERT_EQ("Length Error",s);
  }
  try{
    v.subtract(u);
    FAIL() << "Shuold not be here"; // added before class
  }catch(std::string s){
    ASSERT_EQ("Length Error",s);
  }
}

TEST(CHKOPERATOR,AddSubEQ){
  double a[2]={1.0,2.0};
  Vector v(a,2);
  double b[1]={2.0};
  Vector u(b,1);
  u=v;//operator =
  ASSERT_EQ(2, u.dim());
  ASSERT_EQ(1.0, u.at(1));
  ASSERT_EQ(2.0, u.at(2));
  u=u+v;//operator = and +
  ASSERT_EQ(2, u.dim());
  ASSERT_EQ(2.0, u.at(1));
  ASSERT_EQ(4.0, u.at(2));
  u=u-v; //operator = and -
  ASSERT_EQ(2, u.dim());
  ASSERT_EQ(1.0, u.at(1));
  ASSERT_EQ(2.0, u.at(2));
}

TEST(CHKOPERATOR,OperatorLenError){
  double a[2]={1.0,2.0};
  Vector v(a,2);
  double b[1]={2.0};
  Vector u(b,1);
  try{
    u=u-v;
    FAIL() << "Shuold not be here"; // added before class
  }catch(std::string s){
    ASSERT_EQ("Length Error",s);
  }
  try{
    u=u+v;
    FAIL() << "Shuold not be here"; // added before class
  }catch(std::string s){
    ASSERT_EQ("Length Error",s);
  }
}

class PolygonTest : public ::testing::Test { // test fixture, PolygonTest: derived class, Test: base class
  protected :
    void SetUp() override {
      double a[2] = {1,0},
            b[2] = {4,0},
            c[2] = {4,4},
            d[2] = {1,4};
      u = Vector(a,2);
      v = Vector(b,2);
      w = Vector(c,2);
      x = Vector(d,2);
    }
    Vector u,v,w,x;
};

TEST_F(PolygonTest,fixtureTest){
  ASSERT_EQ(1,u.at(1));
  ASSERT_EQ(0,v.at(2));
  ASSERT_EQ(4,w.at(1));
  ASSERT_EQ(4,x.at(2));
}
TEST_F(PolygonTest,centroidTEST){
  Vector vectors[4] = {u, v, w, x};
  Vector test = centroid(vectors,4);
  ASSERT_NEAR(test.at(1), 2.5, 0.001);
  ASSERT_NEAR(test.at(2), 2, 0.001);
}

TEST_F(PolygonTest,distanceTEST){
  ASSERT_NEAR(distance(v,w), 4, 0.001);
}

TEST_F(PolygonTest,AreaTest){
  ASSERT_NEAR( Area(u,v,w) ,6,0.001);
}

TEST(BubbleSort,case1){
  int b[]={100, 2, 55, 5, 6, 15};
  BubbleSort<int*>(b, b+6);
  ASSERT_EQ(b[0], 2);
  ASSERT_EQ(b[1], 5);
  ASSERT_EQ(b[2], 6);
  ASSERT_EQ(b[3], 15);
  ASSERT_EQ(b[4], 55);
  ASSERT_EQ(b[5], 100);
}

TEST_F(PolygonTest,primeterTest){
  Vector vectors[4] = {u, v, x, w};
  ASSERT_NEAR( Primeter(vectors,4) ,14,0.001);
}

TEST_F(PolygonTest,areaTest){
  Vector vectors[4] = {u, v, x, w};
  ASSERT_NEAR( Area(vectors,4) ,12,0.001);
}
