#include "../src/vector.h"
#include "../src/bubblesort.h"
#include "../src/circle.h"
#include "../src/shape.h"
#include <cmath>
double const epsilon = 0.0001;

TEST(CIRCLETEST,case1 ){
  Circle * c = new Circle(6);
  ASSERT_NEAR(6 * 6 * M_PI, c->area(), epsilon);
  ASSERT_NEAR(12 * M_PI, c->primeter(), epsilon);
}
