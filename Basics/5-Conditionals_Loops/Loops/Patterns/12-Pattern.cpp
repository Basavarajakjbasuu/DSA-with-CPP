#include<iostream>
using namespace std;
 
/*
    *
   * *
  *   *
 *     *
*       *


----*----
---* *---
--*---*--
-*-----*-
*-------*

numRows = 5

  first col and last col as only start and tackle that only

*/

int main() {
  
  int numRows = 0;
  cin >> numRows;

  for(int row = 0; row < numRows; row++) {

    //space
    for (int col = 0; col < numRows - row - 1; col++) {
      cout << " ";
    }

    //star
    for (int col = 0; col < row + 1; col ++) {
     
      if(col == 0 || col == row) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }

    cout << endl;
  }
  return 0;
}

/*
  5
    *
   * *
  *   *
 *     *
*       *

*/