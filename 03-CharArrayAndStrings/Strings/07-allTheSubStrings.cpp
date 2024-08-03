#include<iostream>
using namespace std;

void printSubStrings(string str) {

  for (int i = 0; i < str.length(); i++)
  {
    string subStr;
    for(int j = i; j< str.length(); j++) {
      subStr += str[j];
      cout << subStr  << endl;
    }
  }
}


int main() {
 
  string inpStr = "BOSS";
  printSubStrings(inpStr);
  return 0;
}

/*
  B
  BO
  BOS
  BOSS
  O
  OS
  OSS
  S
  SS
  S
*/