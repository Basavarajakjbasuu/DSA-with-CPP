#include<iostream>
#include<cstring>
using namespace std;

//LEFT to  RIGHT
int lastOccurrencesOfChar(string str, char ch, int index) {
  int ans = -1;
  //BASE CASE
  if(index >= str.length()) return -1;

  if(str[index] == ch) {
    ans = index;
  }

  int recursiveResult = lastOccurrencesOfChar(str, ch, index+1);

  if(recursiveResult != -1) {
    ans = recursiveResult;
  }
  return ans;
} 

int lastOccurrencesOfCharFromRight(string str, char ch, int index) {
  int ans = -1;

  //BASE CASE
  if(index <= 0) return ans;

  if(str[index] == ch) {
    ans = index;
    return ans;
  }

  int recursiveResult = lastOccurrencesOfCharFromRight(str, ch, index-1);

  if(recursiveResult != 0) {
    ans = recursiveResult;
  }
  return ans;
}

int main() {
  
  string inpStr = "";
  char ch;
  int index = 0;

  cout << "Enter string: ";
  cin >> inpStr;
  cout << "Enter char to get last Occurrence: ";
  cin>> ch;

  cout << "Last Occurrence of " << ch << " is: " << lastOccurrencesOfChar(inpStr, ch, index) << endl; 
  cout << "Last Occurrence of " << ch << " is: " << lastOccurrencesOfCharFromRight(inpStr, ch, inpStr.length() - 1) << endl;

  //STL
  const char* result =  strrchr(inpStr.c_str(), ch);
  cout << "Last Occurrence of " << ch << " is: " << (result - inpStr.c_str()) << endl;
  return 0;
}

/*
  1. 
    Enter string: HeyPrabhu
    Enter char to get last Occurrence: a
    Last Occurrence of a is: 5
    Last Occurrence of a is: 5
    Last Occurrence of a is: 5

  2.
    Enter string: abababadd 
    Enter char to get last Occurrence: a
    Last Occurrence of a is: 6
    Last Occurrence of a is: 6
    Last Occurrence of a is: 6

*/