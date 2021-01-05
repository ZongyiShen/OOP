#include "../src/circle.h"
#include "../src/vector.h"

class CircleTest : public ::testing::Test { // test fixture, PolygonTest: derived class, Test: base class
  protected :
    void SetUp() override {
      a = Circle(5, p, "Big");
      b = Circle();
    }
    Circle a,b;
    mathVector p = mathVector(2);
};
TEST_F(CircleTest,primeterTest){
  ASSERT_NEAR(10*M_PI,a.getPrimeter(),0.001);
}
