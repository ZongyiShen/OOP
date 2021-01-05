#include "../src/shape.h"
#include "../src/convexPolygon.h"
#include "../src/circle.h"
#include "../src/vector.h"
#include <array>

class ShapeTest : public ::testing::Test { // test fixture, PolygonTest: derived class, Test: base class
  protected :
    void SetUp() override {
      a = Circle(5, c,"Big");
      b = Circle(12,c, "Big");
      double a[2] = {1,0},
            b[2] = {4,0},
            c[2] = {4,4},
            d[2] = {1,4};
      u = mathVector(a,2);
      v = mathVector(b,2);
      w = mathVector(c,2);
      x = mathVector(d,2);
    }
    Circle a,b;
    mathVector u,v,w,x;
    mathVector c = mathVector(2);
};

TEST_F(ShapeTest,circleTest){
  Shape * circle = new Circle(13,c, "Big"); // why ?
  ASSERT_NEAR(13*2*M_PI,circle->getPrimeter(),0.001);
  ASSERT_NEAR(13*13*M_PI,circle->getArea(),0.001);
  delete circle;
}
TEST_F(ShapeTest,polygonTest){
  mathVector vectors[4] = {u, v, w, x};
  Polygon p = Polygon::CreatePolygon(4, vectors);
  Shape & polygon = p;
  ASSERT_NEAR(14,polygon.getPrimeter(),0.001);
  ASSERT_NEAR(12,polygon.getArea(),0.001);
}
TEST_F(ShapeTest,polygonTest2){
  mathVector vectors[4] = {u, v, w, x};
  Polygon p = Polygon::CreatePolygon(4, vectors);
  Shape * polygon_ptr = &p;
  ASSERT_NEAR(14,polygon_ptr->getPrimeter(),0.001);
  ASSERT_NEAR(12,polygon_ptr->getArea(),0.001);
}
TEST_F(ShapeTest,arrayTest){
  mathVector vectors[4] = {u, v, w, x};
  Polygon p = Polygon::CreatePolygon(4, vectors);
  array<Shape *, 3> shape_array = {new Circle(5,c, "Big"), &p, new Circle(2,c, "Big")};
  // will it work ? will not ! Shape sha;
  ASSERT_NEAR(10*M_PI,shape_array[0]->getPrimeter(),0.001);
  ASSERT_NEAR(12,shape_array[1]->getArea(),0.001);
}

TEST(TESTSHAPE, case1){
  //Circle a = Circle(5, "Small");
  mathVector d = mathVector(2);
  Shape * c = new Circle(13,d, "Big"); // why ?
  //ASSERT_EQ(a.getName(), "Small");
  ASSERT_EQ(c->getName(), "Big");
  delete c;
}

TEST(TESTSHAPE, case2){
  mathVector d = mathVector(2);
  Circle a = Circle(5,d, "Big");
  Shape * c = new Circle(13,d, "Big"); // why ?
  a.changeNameTo("small");
  ASSERT_EQ(a.getName(), "small");
  c->changeNameTo("small");
  ASSERT_EQ(c->getName(), "small");
  delete c;
}

TEST_F(ShapeTest,toStringTest){
  stringstream a,b;
  a << "Circle" << "{\n" << "Big" << "\n" << "(0,0)" << "\n" << 5 <<"\n" <<"}";
  mathVector vectors[4] = {u, v, w, x};
  Polygon p = Polygon::CreatePolygon(4, vectors);
  array<Shape *, 3> shape_array = {new Circle(5, c, "Big"), &p, new Circle(2, c, "Big")};
  ASSERT_EQ(a.str(),shape_array[0]->toString());
}

TEST_F(ShapeTest,fromStringTest){
  stringstream a;
  a<<2;
  Circle c(5,u,"Big");
  c.fromString(a);
  stringstream ss;
  ss << "Circle" << "{\n" << "Big" << "\n" << "(0,0)" << "\n" << 5 <<"\n" <<"}";
  ASSERT_EQ(c.toString(),ss.str());

}