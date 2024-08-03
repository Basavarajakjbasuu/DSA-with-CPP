#include<iostream>
#include<string.h>
using namespace std;

string removeAllOccurrence(string str, string part) {

  while(str.find(part) != string::npos){
    str.erase(str.find(part), part.length());
  }

  return str;
}

int main() {

  string str = "axxxxyyyyb";

  string part = "xy";

  cout << "Input string: " << str << endl;
  cout << "Input part: " << part << endl;

  cout << "Final string is: " << removeAllOccurrence(str, part) << endl;
  return 0;
}

/*
  TEST CASES

  1.
  Input string: daabcbaabcbc
  part: abc
  Final string is: dab

  2.
  Input string: axxxxyyyyb
  Input part: xy
  Final string is: ab

*/