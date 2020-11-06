#include "ConvString.h"

using namespace std;
string printOUT(string input,int index,int num,int *index_out){//處理數字內的字串並回傳字串
  string strout="";
  string out="";

  for(; index<input.length(); index++){
    if(input[index]==']')
      break;
    if( input[index]<58 && input[index]>47){
      strout.append(printOUT(input,index+2,input[index]-48,&index));
    }else{
      strout.append(1,input[index]);
    }
  }
  *index_out=index;
  for(int n=0;n<num;n++){
    out.append(strout);
  }
  return out;

}
int check(string input){//檢查[]數量是否正確，數量一致回傳0，錯誤回傳1。
  int right=0,left=0;

  for(int n=0; n<input.length(); n++){
    if(input[n]=='[')
      left++;
    if(input[n]==']')
      right++;
  }
  if(right!=left){
    return 1;
  }else{
    return 0;
  }

}
string convert(string input){//回傳字串
  string output="";
  for(int n=0;n<input.length();n++){
    if(!islower(input[n])&&!(input[n]>47&&input[n]<58)&&!(input[n]=='[')&&!(input[n]==']')){
        return "";
    }
  }
  for(int n=0; n<input.length();n++){

    if( input[n]<58 && input[n]>47){
      if(input[n+1]!='[')
        return "";
      if(check(input)){
        return "";
      }else{
        output.append(printOUT(input,n+2,input[n]-48,&n));
      }


    }else{
      output.append(1,input[n]);
    }
  }

  return output;
}

int checkInput(string input){//檢查字串是否只有小寫及數字跟[]，有錯誤輸出"The function checkInput reports input error"
  try{
    if(!(input.length()==0)){
      for(int n=0;n<input.length();n++){
        if(!islower(input[n])&&!(input[n]>47&&input[n]<58)&&!(input[n]=='[')&&!(input[n]==']'))
          throw invalid_argument(__func__);
      }
    }

  }catch(const invalid_argument& ia){
    cout<<"The function checkInput reports input error"<<endl;

  }

  return 0;
}
