#include<iostream>
using namespace std;

bool isPalindromeRE(string &str, int startIndex, int endIndex) {
  //BASE CASE
  if(startIndex >= endIndex) return true;

  //Check two char
  if(str[startIndex] != str[endIndex]) {
    return false;
  }

  //RE
  bool recursiveResult =  isPalindromeRE(str, startIndex+1, endIndex-1);

  return recursiveResult;
}

int main() {
  
  string inpStr = "malayalam";

  if(isPalindromeRE(inpStr, 0, inpStr.length()-1)) {
    cout << inpStr << " is Palindrome" << endl;
  } else {
    cout << inpStr << " is not Palindrome" << endl;
  }
  return 0; 
}