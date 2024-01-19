#include<iostream>
using namespace std;
 
/*
  *
  * *
  * * *
  * * * *
  * * * * *

  row0 - 1 start 
  row1 - 2 start 
  row2 - 3 start 
  row3 - 4 start 
  row4 - 5 start

  formula iterate col for lop till row + 1 

*/
int main() {
 
  int rows;
  cin >> rows;

  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < row + 1; col++)
    {
      cout << "* ";
    }

    cout << endl;
  }
  
  return 0;
}
 
/*
  OUTPUT

  *
  * *
  * * *
  * * * *
  * * * * *
*/