#include<iostream>
using namespace std;

/*
   *
  * *
 *   *
*     *
*     *
 *   *
  * *
   *

*/
int main() {

  int rows;
  cin >> rows;

  int numRows = rows / 2;

  //Top half pyramid
  for (int row = 0; row < numRows; row++) {

    //space
    for (int col = 0; col < numRows - row - 1; col++) {
      cout << " ";
    }

    //star
    for (int col = 0; col < row + 1; col++) {

      //first col at 0th index and last column at rowth index
      if (col == 0 || col == row ) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }

    cout << endl;
  }

  // Bottom half inverted pyramid
    for (int row = 0; row < numRows; row++) {

    //space
    for (int col = 0; col < row; col++) {
      cout << " ";
    }

    //star
    for (int col = 0; col < numRows - row; col++) {

      //first col at 0th index and last column at totalRows - row - 1 index
      // -1 because we are starting fro 0th index
      if (col == 0 || col == numRows - row - 1 ) {
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
  OUTPUT

  8
   *
  * *
 *   *
*     *
*     *
 *   *
  * *
   *

*/