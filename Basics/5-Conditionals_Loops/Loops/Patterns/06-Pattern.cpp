#include<iostream>
using namespace std;
 
/*
  * * * * *
  * * * *
  * * *
  * *
  *

  row0 - 5 start 
  row1 - 4 start 
  row2 - 3 start 
  row3 - 2 start 
  row4 - 1 start

  formula iterate col for lop till number of rows - 1

*/
int main() {
 
  int numRows;
  cin >> numRows;

  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < numRows - row; col++)
    {
      cout << "* ";
    }

    cout << endl;
  }
  
  return 0;
}
 
/*
  OUTPUT

  5
  * * * * *
  * * * *
  * * *
  * *
  *
*/