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
  ASSERT_EQ(v.component(0),2);
  v.component(0)=1;
  ASSERT_EQ(v.component(0),1);



}
