#include "../src/mathMatrix.h"
#include "../src/vector.h"


TEST(CHKMATRIX, case1){
  int row = 4;
  int column = 3;
  double i[4][3]= {{1,2,3},{4,5,6,},{7,8,9},{5,5,5}};
  mathMatrix m = mathMatrix(i,row,column);
  ASSERT_EQ(1, m.at(1,1));
}

TEST(CHKMATRIX, case2){
  int row = 4;
  int column = 3;
  double i[4][3]= {{1,2,3},{4,5,6,},{7,8,9},{5,5,5}};
  mathMatrix m = mathMatrix(i,row,column);
  mathVector result = m.row(2);
  ASSERT_EQ(3,result.dimension());

}

TEST(CHKMATRIX, case3){
  int row = 4;
  int column = 3;
  double i[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {5, 5, 5}};

  mathMatrix m = mathMatrix(i, row, column);

  mathVector result = m.column(2);

  ASSERT_EQ(4, result.dimension());
  ASSERT_EQ(2, result.component(0));
  ASSERT_EQ(5, result.component(1));
  ASSERT_EQ(8, result.component(2));
  ASSERT_EQ(5, result.component(3));
  //ASSERT_EQ(1, result);
}
