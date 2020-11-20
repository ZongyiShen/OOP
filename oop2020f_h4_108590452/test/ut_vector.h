#include "../src/vector.h"
#include <cmath>
#include <string>

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
