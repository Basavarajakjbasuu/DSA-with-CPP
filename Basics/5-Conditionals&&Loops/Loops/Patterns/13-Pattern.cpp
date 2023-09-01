#include<iostream>
using namespace std;
/*

Hallow inverted pyramid
*       *
 *     *
  *   *
   * *
    *

  first and last column as *
*/ 
int main() {

  int numRows = 0;
  cin >> numRows;

  for (int row = 0; row < numRows; row++) {

    //space
    for (int col = 0; col < row; col ++) {
      cout << " ";
    }

    //star
    for (int col = 0; col < numRows - row; col ++) {
      
      if(col == 0 || col == numRows - row - 1) {
        cout << "* ";
      }else {
        cout << "  "; // 2 spaces
      }
    }

    cout << endl;
  }
    return 0;
}

/*
5
*       *
 *     *
  *   *
   * *
    *

*/