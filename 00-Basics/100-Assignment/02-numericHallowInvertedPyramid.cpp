#include<iostream>
using namespace std;
 
/*
  1 2 3 4 5 
  2     5 
  3   5 
  4 5 
  5
*/

int main() {    
  int numRows=0;

  cout << "Enter num of rows: ";
  cin >> numRows;

  for(int row = 0; row<numRows; row++) {

    for(int col = row+1; col<=numRows; col++) {
      
      if(col == row+1 || col == numRows || row == 0) {
        cout << col << " ";
      }else {
        cout << "  ";
      }
    }

    cout << endl;
  }
  
  return 0;
}

/*

  Enter num of rows: 5
  1 2 3 4 5 
  2     5 
  3   5 
  4 5 
  5
*/