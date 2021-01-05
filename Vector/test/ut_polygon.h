#include "../src/convexPolygon.h"
#include "../src/vector.h"

#include <algorithm>

class PolygonTest : public ::testing::Test { // test fixture, PolygonTest: derived class, Test: base class
  protected :
    void SetUp() override {
      double a[2] = {1,0},
            b[2] = {4,0},
            c[2] = {4,4},
            d[2] = {1,4};
      u = mathVector(a,2);
      v = mathVector(b,2);
      w = mathVector(c,2);
      x = mathVector(d,2);
    }
    mathVector u,v,w,x;
};

TEST_F(PolygonTest,fixtureTest){
  ASSERT_EQ(1,u.component(1));
  ASSERT_EQ(0,v.component(2));
  ASSERT_EQ(4,w.component(1));
  ASSERT_EQ(4,x.component(2));
}

TEST_F(PolygonTest,constructTest){
  mathVector vectors[4] = {u, v, w, x};
  Polygon p = Polygon::CreatePolygon(4, vectors);

  ASSERT_EQ(4,p.getNumberOfVerties());
  //ASSERT_EQ(0,v.component(2));
}

TEST_F(PolygonTest,lengthprimeterTest){
  mathVector vectors[4] = {u, v, w, x};
  Polygon p = Polygon::CreatePolygon(4, vectors);
  ASSERT_EQ(p.getPrimeter(), 14);
}

TEST_F(PolygonTest,areaTest){
  mathVector vectors[4] = {u, v, w, x};
  Polygon p = Polygon::CreatePolygon(4, vectors);
  ASSERT_NEAR(p.getArea(), 12, 0.001);
}

TEST_F(PolygonTest,centroidTEST){
  mathVector vectors[4] = {u, v, w, x};
  Polygon p = Polygon::CreatePolygon(4, vectors);
  mathVector test = p.centroid();
  ASSERT_NEAR(test.component(1), 2.5, 0.001);
  ASSERT_NEAR(test.component(2), 2, 0.001);
}

TEST_F(PolygonTest,createTEST){
  mathVector vectors[4] = {u, w, v, x};
  Polygon p = Polygon::CreatePolygon(4, vectors);
  ASSERT_EQ(p.getPrimeter(), 14);
}

TEST(SORT,asending){
  int array[]={10,16,24,12,0,2};
  std::sort(array,array+6);
  ASSERT_EQ(0,array[0]);
  ASSERT_EQ(2,array[1]);
  ASSERT_EQ(10,array[2]);
  ASSERT_EQ(12,array[3]);
  ASSERT_EQ(16,array[4]);
  ASSERT_EQ(24,array[5]);
}

template <class T>
bool greaterThan(T a, T b){
  return (a > b);
}

TEST(SORT,desending){
  int array[]={10,16,24,12,0,2};
  bool tmp = greaterThan<int>(1, 2);
  std::sort(array,array+6,greaterThan<int>);
  ASSERT_EQ(0,array[5]);
  ASSERT_EQ(2,array[4]);
  ASSERT_EQ(10,array[3]);
  ASSERT_EQ(12,array[2]);
  ASSERT_EQ(16,array[1]);
  ASSERT_EQ(24,array[0]);
}
bool to100(int a, int b){
  return (100-a > 100-b);
}
TEST(SORT,to100Desending){
  int array[]={10,16,24,12,0,2};
  std::sort(array,array+6,to100);
  ASSERT_EQ(0,array[0]);
  ASSERT_EQ(2,array[1]);
  ASSERT_EQ(10,array[2]);
  ASSERT_EQ(12,array[3]);
  ASSERT_EQ(16,array[4]);
  ASSERT_EQ(24,array[5]);

}

TEST(TRIANGLE, case1){
  double a[2] = {1,0},
        b[2] = {4,0},
        d[2] = {1,4};
  mathVector u = mathVector(a,2);
  mathVector v = mathVector(b,2);
  mathVector x = mathVector(d,2);
  mathVector vectors[3] = {u, v, x};
  Triangle t(vectors);
  ASSERT_NEAR(t.getArea(), 6, 0.001);
  mathVector cen = t.getCentroid();
  ASSERT_NEAR(cen.component(1), 2, 0.001);
  ASSERT_NEAR(cen.component(2), 1.333333, 0.001);
}
