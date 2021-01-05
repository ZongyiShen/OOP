#include "../src/vector.h"
#include "../src/dot.h"

TEST(CHKDOT, case1){
  double input[2] = {1,1};
  double input1[2] = {1,0};

  double result = dot(input, 2, input1, 2);

  ASSERT_EQ(1, result);
}
TEST(CHKDOT, case2){
  double input[3] = {1,1,0};
  double input1[2] = {1,0};
  try{
    double result = dot(input, 3, input1, 2);
    FAIL() << "Shuold not be here";
  }catch(string s){
    ASSERT_EQ("ERROR",s);
  }
}

TEST(CHKDOT, case3){
  double b[]={2, 5, 6};
  mathVector y = mathVector(b, 3);

  double a[]={1, 1, 1};
  mathVector x = mathVector(a, 3);
  ASSERT_EQ(dot(x,y),13);

}



TEST(CHKVECTOR,case1){
  double a[2];
  double b[]={2, 5, 6};
  double *c = new double[2];

  //string x = string("123");
  mathVector v = mathVector(b, 3);
  ASSERT_EQ(v.dimension(), 3);

  delete [] c;
}

TEST(CHKVECTOR,case2){
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);

  double c[]={1, 7, 8};
  mathVector w = mathVector(c, 3);

  ASSERT_EQ(v.dot(w), 85);
}

TEST(CHKVECTOR,case3){ // copy constructor test case
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);
  // 是不是 copy constructor 是看有沒有 初值
  mathVector w(v); // copy constructor
  mathVector x = v; // copy constructor
  mathVector y = mathVector(v); // copy constructor
  y = v;// copy assignment !

  ASSERT_EQ(w.dimension(),3);
}

TEST(CHKVECTOR,case4){ // copy assignment test case
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);

  double c[]={1, 7};
  mathVector w = mathVector(c, 2);

  w = v; // copy assignment !

  ASSERT_EQ(w.dimension(),3);
}

TEST(CHKVECTOR,case5){ // copy assignment test case
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);

  double c[]={1, 7};
  mathVector w = mathVector(c, 2);

  double d[]={1, 7, 9, 8};
  mathVector z = mathVector(d, 4);

  w = v = z; // copy assignment !

  ASSERT_EQ(w.dimension(),4);
}

TEST(CHKLEN,case1){
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);
  ASSERT_EQ(v.dimension(), 3);
  v.setDimension(1);
  ASSERT_EQ(v.dimension(), 1);
}

TEST(CHKCOMPONENT,case1){
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);
  ASSERT_EQ(v.component(1),2);
  v.component(1)=1;
  ASSERT_EQ(v.component(1),1);

}

TEST(CHKLENTH,case1){
  double b[]={3, 4, 12};
  mathVector v = mathVector(b, 3);
  ASSERT_EQ(v.length(), 13);
}

TEST(CHKSUB,case1){
  double a[]={6, 8, 24};
  mathVector x = mathVector(a, 3);
  double b[]={3, 4, 12};
  mathVector v = mathVector(b, 3);
  mathVector result= x-v;
  ASSERT_EQ(result.component(1), 3);
}

TEST(CHKAREA,case1){
  double a[]={0,8};
  mathVector u = mathVector(a, 2);
  double b[]={6,0};
  mathVector v = mathVector(b, 2);
  double c[]={0,0};
  mathVector w = mathVector(c, 2);
  ASSERT_NEAR(24,w.getArea(u,v),0.001);
  ASSERT_EQ(24,w.getArea(u,v));
}

TEST(CHKANGLE,case1){
  double a[]={0,6};
  mathVector u = mathVector(a, 2);
  double b[]={4,0};
  mathVector w = mathVector(b, 2);
  ASSERT_NEAR(90,u.angle(w),0.001);
}

TEST(CHKCENTROID,case1){
  double a[]={0,6};
  mathVector v = mathVector(a, 2);
  double b[]={4,0};
  mathVector w = mathVector(b, 2);
  mathVector x[2]={v,w};
  mathVector y=mathVector::centroid(x,2);
  ASSERT_NEAR(2,y.component(1),0.001);
  ASSERT_NEAR(3,y.component(2),0.001);
}
