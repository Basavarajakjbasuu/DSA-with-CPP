#include<iostream>
using namespace std;
 
/*
    *
   * *
  * * *
 * * * *
* * * * *


----*----
---* *---
--* * *--
-* * * *-
* * * * *

numRows = 5
r0 4 space and 1 star
r1 3 space and 2 star
r2 2 space and 3 star
r3 1 space and 4 star
r4 0 space and 5 star

=> space
  numRows-row-1
    Ex.
      for row 3 
      5-3-1 => 1space

=> star
  row + 1
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
      cout << "* ";
    }

    cout << endl;
  }
  return 0;
}

/*
  5
    *
   * *
  * * *
 * * * *
* * * * *

*/