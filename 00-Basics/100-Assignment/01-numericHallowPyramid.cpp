#include<iostream>
using namespace std;
 
int main() {
  
  int numRows=0;

  cout << "Enter number of rows: ";
  cin >> numRows;

  for(int row = 0; row<numRows; row++) {

    for(int col = 0; col<row+1; col++) {

      if(col == 0 || col == row || row == numRows - 1) {
        cout <<col+1 <<" ";
      }else {
        cout <<"  ";
      }

    }
      cout << endl;
  }
  return 0;
}

/*
  Enter number of rows: 5
  1 
  1 2 
  1   3 
  1     4 
  1 2 3 4 5
*/