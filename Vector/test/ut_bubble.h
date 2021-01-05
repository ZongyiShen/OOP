#include "../src/bubbleSort.h"
TEST(CHKBUBBLE, case1){
  int b[]={100, 2, 55, 5, 6, 15};
  BubbleSort<int*>(b, b+6);
  ASSERT_EQ(b[0], 2);
  ASSERT_EQ(b[1], 5);
  ASSERT_EQ(b[2], 6);
  ASSERT_EQ(b[3], 15);
  ASSERT_EQ(b[4], 55);
  ASSERT_EQ(b[5], 100);
}
