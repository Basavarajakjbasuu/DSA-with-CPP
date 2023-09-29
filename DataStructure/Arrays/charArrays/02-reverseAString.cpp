#include<iostream>
#include<string.h>
using namespace std;

void reverseString(char ch[], int length) {

  int startIndex = 0;
  int endIndex = length - 1;

  while(startIndex <= endIndex) {

    swap(ch[startIndex], ch[endIndex]);
    startIndex++;
    endIndex--;
  }
} 


int main() {

  char ch[100];
  cin.getline(ch, 100);

  cout << "Before Reverse: " << ch << endl;

  int length = strlen(ch);
  reverseString(ch, length);

  cout << "Reverse of is: " << ch << endl;
  return 0;
}

/*
  1.

    Bassu
    Before Reverse: Bassu
    Reverse of is: ussaB

  2.

    Malayalam
    Before Reverse: Malayalam
    Reverse of is: malayalaM


*/