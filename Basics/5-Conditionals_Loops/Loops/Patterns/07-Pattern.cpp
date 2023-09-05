#include<iostream>
using namespace std;
 
/*
  1
  1 2
  1 2 3
  1 2 3 4
  1 2 3 4 5

  row0 - 1 start 
  row1 - 2 start 
  row2 - 3 start 
  row3 - 4 start 
  row4 - 5 start

  formula iterate col for lop till number of rows + 1

  then for number of col:  col + 1
*/
int main() {
 
  int numRows;
  cin >> numRows;

  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < row + 1; col++)
    {
      cout << col + 1 << " ";
    }

    cout << endl;
  }
  
  return 0;
}
 
/*
  OUTPUT

  5

  1
  1 2
  1 2 3
  1 2 3 4
  1 2 3 4 5
*/