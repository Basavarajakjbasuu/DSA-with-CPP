#include<iostream>
using namespace std;

/*
  * 
  * * 
  * * * 
  * * * * 
  * * * * * 
  * * * * 
  * * * 
  * * 
  * 
*/ 

int main() {
  int numCols=0;

  cout << "Enter num of columns: ";
  cin >> numCols;

  for(int row = 0; row<2*numCols-1; row++) {

    int cond = 0;

    if (row<numCols) {
      //Growing phase of diamond
      cond=row;
    }else {
      cond = numCols - (row%numCols) - 2;
    }
    //Shrinking phase of diamond
    for (int col = 0; col <= cond; col++) {

      cout << "* ";

    }

    cout << endl;
  } 
  return 0;
}

/*
  Enter num of columns: 5
  * 
  * * 
  * * * 
  * * * * 
  * * * * * 
  * * * * 
  * * * 
  * * 
  * 
*/