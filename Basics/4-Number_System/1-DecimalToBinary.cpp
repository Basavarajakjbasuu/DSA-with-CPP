#include<iostream>
#include<cmath>

using namespace std;

int decimalToBinaryMethod1(int decimalNumber) {

  //1.Division Method 

    // while(decimalNumber > 0) {

    //   int bit = decimalNumber % 2; // Remainder
    //   cout << bit << endl;
    //   decimalNumber = decimalNumber / 2;
    // }
    
    // return 0;

  //!Reversing

  int binaryNum = 0;
  int i = 0;
  while(decimalNumber > 0) {

    int bit = decimalNumber % 2;
    binaryNum = bit * pow(10, i++) + binaryNum;
    decimalNumber = decimalNumber / 2;
  }

  return binaryNum;
}

int decimalToBinaryMethod2(int decimalNumber) {

  int binaryNum = 0;
  int i = 0;

  while(decimalNumber > 0) {
    int bit = (decimalNumber & 1);
    binaryNum = bit * pow(10, i++) + binaryNum;
    decimalNumber = decimalNumber >> 1; //RightShift by 1
  }

  return binaryNum;
}

int main() {

  int deciNum = 0;

  cin >> deciNum;

  int binaryNum1 = decimalToBinaryMethod1(deciNum);
  int binaryNum2 = decimalToBinaryMethod2(deciNum);
  cout << "Converted Binary number from Method1: " << binaryNum1 << endl;
  cout << "Converted Binary number from Method2: " << binaryNum2 << endl;

  return 0;
}

/* 
  Output:
  23
  Converted Binary number from Method1: 10111
  Converted Binary number from Method2: 10111
*/