#include<iostream>
using namespace std;

void reverseAString(string &str, int startIndex, int endIndex) {

  //BASE CASE
  if(startIndex >= endIndex) return;

  swap(str[startIndex], str[endIndex]);

  reverseAString(str, startIndex+1, endIndex-1);
}

int main() {
  
  string inpStr = "abcd";
  int startIndex = 0, endIndex = inpStr.length() - 1;

  reverseAString(inpStr, startIndex, endIndex);
  cout << "Reverse of strong is: " << inpStr << endl;

  return 0;
}