#include<iostream>
using namespace std;

/*
917. REVERSE ONLY LETTERS
  Given a string s, reverse the string according to the following rules:

  All the characters that are not English letters remain in the same position.
  All the English letters (lowercase or uppercase) should be reversed.
  Return s after reversing it.

  Example 1:

  Input: s = "ab-cd"
  Output: "dc-ba"

  Example 3:

  Input: s = "Test1ng-Leet=code-Q!"
  Output:    "Qedo1ct-eeLg=ntse-T!
*/

//Custom isAlphabet function
bool isAlpha(char ch) {
  return (ch >= 'A' && ch<= 'Z') || (ch >= 'a' && ch <= 'z');
}

string reverseOnlyLetters(string str) {
  int low = 0, high=str.size()-1;

  while(low<high) {
    if(isAlpha(str[low]) && isAlpha(str[high])) {
      swap(str[low], str[high]);
      low++;
      high--;
    }else if(!isAlpha(str[low])) {
      low++;
    }else {
      high--;
    }
  }

  return str;
}

int main() {
 string inStr;
 cin>>inStr;

 cout<<"Reversed only letters: " << reverseOnlyLetters(inStr) << endl;
 return 0;
}

/*  TEST CASES
  1. Testing-Leet=code-Q!
     Reversed only letters: Qedocte-eLgn=itse-T!
  2. ab-cd
     Reversed only letters: dc-ba
*/