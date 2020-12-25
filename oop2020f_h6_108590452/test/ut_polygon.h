#include "../src/vector.h"
#include "../src/bubblesort.h"
#include "../src/polygon.h"
#include "../src/shape.h"
#include <cmath>

double const epsilon = 0.0001;

TEST(POLYGONTEST,case1)
{
  double a[]={0, 0};
  double c[]={2, 2};
  double d[]={1, 3};
  double e[]={0, 2};
  double b[]={2, 0};
  double f[]={3, 1};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(c, 2);
  Vector x(d, 2);
  Vector y(e, 2);
  Vector z(f, 2);
  Vector arr[] = {u, v, w, x, y, z};
  Polygon * poly = new Polygon(arr, 6);
  ASSERT_NEAR(6, poly->area(), epsilon);
  ASSERT_NEAR(4 + 4 * sqrt(2), poly->primeter(), epsilon);

}
