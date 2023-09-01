#include<iostream>
using namespace std;

/*

1
2 * 2
3 * 3 * 3
4 * 4 * 4 * 4
5 * 5 * 5 * 5 * 5

Odd column as numbers and even column as *

*/
int main() {

  int numRows = 0;
  cin >> numRows;

  for (int row = 0; row < numRows; row++){
    
    for (int col = 0; col < 2 * row + 1; col++){
      
      //odd
      if( col % 2 == 1) {
        cout << " * ";
      } 
      // even
      else {
        cout << row + 1;
      }
    }
    cout << endl;
  }
  
  return 0;
}