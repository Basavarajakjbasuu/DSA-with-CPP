#include<iostream>
using namespace std;

/*
* * * * *
-* * * *
--* * *
---* *
----*

numsRows = 5

r0 -> 0 space 5 *
r1 -> 1 space 4 *
r2 -> 2 space 3 *
r3 -> 3 space 2 *
r4 -> 4 space 1 *

=> space
    col < row

=> star
    col < numsRows - row    

*/ 
int main() {
  
  int numsRows = 0;
  cin >> numsRows;

  for (int row = 0; row < numsRows; row++) {

    // space
    for (int col = 0; col < row; col++){
      cout << " ";
    }

    //star
    for (int col = 0; col < numsRows - row; col++) {
      cout << "* ";
    }

    cout << endl;
  }

    return 0;
}

/*
5
* * * * *
 * * * *
  * * *
   * *
    *

*/