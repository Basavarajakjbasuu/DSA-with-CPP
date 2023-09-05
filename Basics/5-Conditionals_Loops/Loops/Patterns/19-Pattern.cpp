#include<iostream>
using namespace std;

/*

A
A B
A B C
A B C D
A B C D E

print row + 1
*/
int main() {

  int numRows = 0;
  cin >> numRows;
 
  for (int row = 0; row < numRows; row++){
    
    for (int col = 0; col < row + 1; col++){

      char ch = col + 'A';
      cout << ch << " ";
    }
    cout << endl;
  }
  
  return 0;
}

/*
    5
    A
    A B
    A B C
    A B C D
    A B C D E
*/