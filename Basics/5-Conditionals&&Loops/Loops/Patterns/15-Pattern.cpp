#include<iostream>
using namespace std;

/*  
  - Flipped solid Diamond

      * * * *   * * * *
      * * *       * * *
      * *           * *
      *               *
      *               *
      * *           * *
      * * *       * * *
      * * * *   * * * * 
  
  - Just break into two half
  - and make three parts add apply rules like
    r0 ->
    r1 ->
    r2 ->
    r3 ->
*/
int main() {

  int rows = 0;
  cin >> rows;

  int numRows = rows / 2;

  for (int row = 0; row < numRows; row++) {

    //first Half

    //inverted half Pyramid
    for (int col = 0; col < numRows - row; col++) {
      cout << "* ";
    }

    //full Pyramid
    for (int col = 0; col < 2 * row + 1; col++){
      cout << "  ";
    }

    //inverted half Pyramid
    for (int col = 0; col < numRows - row; col++) {
      cout << "* ";
    }
    cout << endl;
  }
    for (int row = 0; row < numRows; row++) {
    //second Half

    //inverted half Pyramid
    for (int col = 0; col < row + 1; col++) {
      cout << "* ";
    }

    //inverted full Pyramid
    for (int col = 0; col < 2 * numRows - 2 * row - 1; col++){
      cout << "  ";
    }

    //inverted half Pyramid
    for (int col = 0; col < row + 1; col++) {
      cout << "* ";
    }
    cout << endl;
  }

    return 0;
}

/*
  8
  * * * *   * * * *
  * * *       * * *
  * *           * *
  *               *
  *               *
  * *           * *
  * * *       * * *
  * * * *   * * * *

*/