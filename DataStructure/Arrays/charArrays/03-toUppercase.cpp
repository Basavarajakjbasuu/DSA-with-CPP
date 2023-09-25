#include<iostream>
#include<string.h>
using namespace std;

void toUppercase(char ch[]) {

  int index = 0;

  while(ch[index] != '\0') {

    char currCharacter = ch[index];

    // checking letter is lower case or not
    if(currCharacter >= 'a' && currCharacter <= 'z') {

      ch[index] = currCharacter - 'a' + 'A';
    }

    index++;
  }

} 

void toLowercase(char ch[]) {

  int index = 0;

  while(ch[index] != '\0') {

    char currCharacter = ch[index];

    // checking letter is lower case or not
    if(currCharacter >= 'A' && currCharacter <= 'Z') {

      ch[index] = currCharacter - 'A' + 'a';
    }

    index++;
  }

}



int main() {

  char ch[100];

  cin.getline(ch, 100);

  cout << "input:  " << ch << endl;
  toUppercase(ch);
  cout << "Uppercase of string:  " << ch << endl;
  toLowercase(ch);
  cout << "Lowercase of string:  " << ch << endl;

  return 0;
}

/*
  TEST CASES

  1.

    bassu
    input:  bassu
    Uppercase of string:  BASSU

  2.
    I am working in Cognizant
    input:  I am working in Cognizant
    Uppercase of string:  I AM WORKING IN COGNIZANT

  3.

    I am a Good Coder!
    input:  I am a Good Coder!
    Uppercase of string:  I AM A GOOD CODER!
    Lowercase of string:  i am a good coder!

*/