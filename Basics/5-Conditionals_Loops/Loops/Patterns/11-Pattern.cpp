#include<iostream>
using namespace std;


/*
   *
  * *
 * * *
* * * *
* * * *
 * * *
  * *
   * 
  
  Combine the implementation of full pyramid and inverted pyramid to become diamond

  and divide numsRows / 2 => half
*/
int main() {
 
  int rows = 0;
  cin >> rows;

  int numRows = rows / 2;

  for (int row = 0; row < numRows; row++) {

    //space
    for (int col = 0; col < numRows - row - 1; col++) {
      cout << " ";
    }

    // star
    for (int col = 0; col < row + 1; col++) {
      cout << "* ";
    }

    cout << endl;

  }

  for (int row = 0; row < numRows; row++) {

    //space
    for (int col = 0; col < row; col++) {
      cout << " ";
    }

    // star
    for (int col = 0; col < numRows - row; col++) {
      cout << "* ";
    }

    cout << endl;
  }
    return 0;
}

/*
  8
   *
  * *
 * * *
* * * *
* * * *
 * * *
  * *
   *


*/