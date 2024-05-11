#include<iostream>
using namespace std;

/*
  1 
  1 1 
  1 2 1 
  1 3 3 1 
  1 4 6 4 1 
*/

int main() {
  int numRows = 0;
  
  cout << "Enter num of Rows: ";
  cin >> numRows;

  for(int row = 1; row<=numRows; row++) {
    int C = 1;
    for(int col =1; col <= row; col++) {
      cout << C << " ";
      C = C * (row-col) / col;
    }
    cout << endl;
  } 
  return 0;
}

/*
  Enter num of Rows: 5
  1 
  1 1 
  1 2 1 
  1 3 3 1 
  1 4 6 4 1 
*/