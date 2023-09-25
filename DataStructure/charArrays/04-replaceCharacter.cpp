#include<iostream>
using namespace std;

void replaceCharacter(char ch[]) {

  int index=0;

  while(ch[index] != '\0') {

    char currCharacter = ch[index];

    if(currCharacter == '@') {
      ch[index] = ' ';
    }

    index++;
  }
} 

int main() {

  char ch[100];

  cin >> ch;

  cout << "Input: " << ch << endl;

  replaceCharacter(ch);
  cout << "After replace: " << ch << endl;
  return 0;
}

/*
  TEST CASES

  1.

    @I@am@coder!
    Input: @I@am@coder!
    After replace:  I am coder!

  2.

    Welcome@to@coding@world@
    Input: Welcome@to@coding@world@
    After replace: Welcome to coding world 

*/