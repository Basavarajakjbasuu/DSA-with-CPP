#include<iostream>
using namespace std;

/*
  * * * * * *
  *         *
  *         *
  * * * * * *
*/

int main() {

  int rows, cols;

  cout << "Enter number of Rows and cols: ";
  cin >> rows >> cols;

  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      
      //First row and last row full *
      if(row == 0 || row == rows - 1){

        cout << "* ";
      }else {

        //First and last cols full * 
        if(col == 0 || col == cols - 1 ) {
          cout << "* ";
        } else {
          // Remaining spaces 
          cout << "  ";
        }
      }
    }
    cout << endl;
  }
  
  return 0;
}

/*
  OUTPUT

  Enter number of Rows and cols: 5 7
    * * * * * * *
    *           *
    *           *
    *           *
    * * * * * * *
*/