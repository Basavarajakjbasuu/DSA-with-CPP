#include<iostream>
using namespace std;

void findSubsequences(string inputStr, string outputStr, int index) {

  //BASE CASE
  if(index >= inputStr.length()) {
    cout << "->" << outputStr <<  endl;
    return;
  }

  char ch = inputStr[index];

  //Include
  outputStr.push_back(ch);
  findSubsequences(inputStr, outputStr, index+1);

  //Exclude
  outputStr.pop_back();
  findSubsequences(inputStr, outputStr, index+1);

  /* 
    //Exclude
    findSubsequences(inputStr, outputStr, index+1);
    //Include
    outputStr.push_back(ch);
    findSubsequences(inputStr, outputStr, index+1);
  */
}

int main() {
 
  string inputStr = "XY", outputStr="";
  int index = 0;

  findSubsequences(inputStr, outputStr, index);
  return 0;
}