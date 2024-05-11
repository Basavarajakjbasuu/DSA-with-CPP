#include<iostream>
#include "assert.h";
using namespace std;

/*
  ********1********
  *******2*2*******
  ******3*3*3******
  *****4*4*4*4*****
  ****5*5*5*5*5****
*/ 
int main() {
  int numRows = 0;
  
  cout << "Enter num of Rows: ";
  cin >> numRows;

  // if (numRows > 9) {
  //   cout << "Please enter less than 9" << endl;
  //   return;
  // }
  assert(numRows <=9);

  for(int row=0; row<numRows; row++) {

    int startNumIndex = 8-row;
    int num = row+1;
    int countNum = num;
    for (int col=0; col<17; col++) {

      if(col == startNumIndex && countNum > 0) {
        cout << num;
        startNumIndex+=2;
        countNum--;
      }else {
        cout << "*";
      }
    }

    cout << endl;
  } 
  return 0;
}

/*
  Enter num of Rows: 5
  ********1********
  *******2*2*******
  ******3*3*3******
  *****4*4*4*4*****
  ****5*5*5*5*5****
*/