#include<iostream>
#include<string.h>
using namespace std;

bool isPalindrome(char ch[], int size) {

  int startIndex = 0;
  int lastIndex = size - 1;

  while(startIndex <= lastIndex) {

    if(ch[startIndex] == ch[lastIndex]) {
      startIndex++;
      lastIndex--;
    } else {
      return false;
    }
  }

  return true;
} 

int main() {

  char ch[100];

  cin >> ch;

  int len = strlen(ch);

  if(isPalindrome(ch, len)) {
    cout << ch << " is Palindrome!";
  } else {
    cout << ch << " is not Palindrome.";
  }

  return 0;
}

/*
  TEST CASES

  1.

    mam
    mam is Palindrome!
  
  2.
    malayalam
    malayalam is Palindrome!

  3.

    Bassu
    Bassu is not Palindrome.
  
*/