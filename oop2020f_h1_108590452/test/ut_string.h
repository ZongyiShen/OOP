#include "../src/ConvString.h"

TEST(CHK, case1){
  string test = "2[abc2[e]]3[g]";
  string result = convert(test);
  ASSERT_EQ("abceeabceeggg", result);

}
TEST(CHK,case2){
  string test="ab[c3[s][";
  string result = convert(test);
  ASSERT_EQ("",result);

}
TEST(CHK1,case1){
  string test="";
  int result = checkInput(test);
  ASSERT_EQ(0,result);
}
