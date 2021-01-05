#include "../src/mathMatrix.h"
#include "../src/vector.h"

class MatrixTest : public ::testing::Test {//test fixture
protected : //繼承的人可用
    void SetUp() override {
      i[0]=a;
      i[1]=b;
      i[2]=c;
      i[3]=d;

    }
    int row = 4;
    int column = 3;
    double a[3]= {1,2,3};
    double b[3]= {4,5,6};
    double c[3]= {7,8,9};
    double d[3]= {5,5,5};

    double *i[4];//4*3
    double *j[2];//2*3

};
//TEST 是獨立測試
//TEST_F 則是多跑 class
TEST_F(MatrixTest, case1){
  mathMatrix m = mathMatrix(i,row,column);
  ASSERT_EQ(1, m.at(1,1));
}

TEST_F(MatrixTest, case2){

  mathMatrix m = mathMatrix(i,row,column);
  mathVector result = m.row(2);
  ASSERT_EQ(3,result.dimension());

}

TEST_F(MatrixTest, case3){


  mathMatrix m = mathMatrix(i, row, column);

  mathVector result = m.column(2);

  ASSERT_EQ(4, result.dimension());
  ASSERT_EQ(2, result.component(0));
  ASSERT_EQ(5, result.component(1));
  ASSERT_EQ(8, result.component(2));
  ASSERT_EQ(5, result.component(3));
  //ASSERT_EQ(1, result);
}
