#include<iostream>
#include<string.h>
using namespace std;
 
int getLength(char ch[], int size) {

  int length = 0;

  for (int i = 0; i < size; i++)
  {
    if(ch[i] == '\0') {
      break;
    }else {
      length++;
    }
  }

  return length;
}

int main() {
  char ch[100];

  cin.getline(ch, 100);
  cout << "Length of '" << ch << "' is: " << getLength(ch, 100) << endl;
  cout << "Length of '" << ch << "' is by inbuilt function: " << strlen(ch) << endl;

  return 0;
}

/*

  Test cases

  1.
   
    Bassu
    Length of 'Bassu' is: 5

  2.

    my name is Bassu
    Length of 'my name is Bassu' is: 16

    ==> spaces are also counted

  3.

    I am jr SE
    Length of 'I am jr SE' is: 10
    Length of 'I am jr SE' is by inbuilt function: 10

*/