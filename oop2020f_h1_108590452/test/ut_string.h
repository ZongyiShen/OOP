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



TEST(CHECKINPUT, caseNormalInput1){
  string input= "3[abc]";
  int result = 0;
  ASSERT_EQ(result, checkInput(input));
}

TEST(CHECKINPUT, caseNotNormalInput1){
  string input= "!!3[abc]";
  try {
    checkInput(input);
  } catch (const invalid_argument& ia) {
    ASSERT_EQ("checkInput", ia.what());
  }
}

//To compare two string objects, you should use ASSERT_EQ.
TEST(CONVERT, caseNormalInput1){
  string input= "3[abc]";
  string output = "abcabcabc";
  ASSERT_EQ(output, convert(input));
}

TEST(CONVERT, caseNormalInput2){
  string input= "3[2[d]]";
  string output = "dddddd";
  ASSERT_EQ(output, convert(input));
}

TEST(CONVERT, caseNormalInput3){
  string input= "2[aa2[bb]3[c]]";
  string output = "aabbbbcccaabbbbccc";
  ASSERT_EQ(output, convert(input));
}

TEST(CONVERT, caseNormalInput4){
  string input= "abc";
  string output = "abc";
  ASSERT_EQ(output, convert(input));
}

TEST(CONVERT, caseNormalInput5){
  string input= "abc9[e]";
  string output = "abceeeeeeeee";
  ASSERT_EQ(output, convert(input));
}

TEST(CONVERT, caseNormalInput6){
  string input= "4[abc]9[e]";
  string output = "abcabcabcabceeeeeeeee";
  ASSERT_EQ(output, convert(input));
}

TEST(CONVERT, caseZeroInput1){
  string input= "0[a2[b]3[c]]";
  string output = "";
  ASSERT_EQ(output, convert(input));
}

TEST(CONVERT, caseZeroInput2){
  string input= "2[a0[b]3[c]]";
  string output = "acccaccc";
  ASSERT_EQ(output, convert(input));
}

TEST(CONVERT, caseNotNormalInput1){
  string input= "2[a2[b]3[c]";
  string output = "";
  ASSERT_EQ(output, convert(input));
}

TEST(CONVERT, caseNotNormalInput2){
  string input= "2[a2[b3[c";
  string output = "";
  ASSERT_EQ(output, convert(input));
}
