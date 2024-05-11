#include<iostream>
using namespace std;

/*
        1 
      1 2 1 
    1 2 3 2 1 
  1 2 3 4 3 2 1 
1 2 3 4 5 4 3 2 1  
*/ 

int main() {
  int numRows=0;

  cout << "Enter num of rows: ";
  cin >> numRows;


  int extraRow = numRows;

  for(int row = 0; row<numRows; row++) {

    int num = 1;
    for (int col = 0; col<extraRow; col++) {

      //Spaces
      if( col < numRows - row - 1) {
        cout << "  ";
      }else if (col <= numRows - 1) {
        cout << num << " ";
        num++;

      //Second half when col count == num of Rows start from num-2 Ex. 3-2 = 1
      } else if(col == numRows) {
        num = num-2;
        cout << num << " ";
        num--;
      } else {
        //Continuation
        cout << num << " ";
        num--;
      }
      
    }
    extraRow++;


    cout << endl;
  }
  return 0;
}

/*
  Enter num of rows: 5
        1 
      1 2 1 
    1 2 3 2 1 
  1 2 3 4 3 2 1 
1 2 3 4 5 4 3 2 1 
*/