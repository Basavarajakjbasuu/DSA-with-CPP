#include<iostream>
#include<cmath>

using namespace std;
 
int binaryToDecimalMethod1(int binaryNum) {

  //Division method
  int decimal = 0;
  int i = 0;

  while(binaryNum > 0) {

    int bit = binaryNum % 10;
    decimal = decimal +  bit * pow(2, i++);
    binaryNum /= 10;
  }

  return decimal;
}

int binaryToDecimalMethod2(int binaryNum) {

  //Bit method
  int decimal = 0;
  int i = 0;

  while(binaryNum > 0) {

    int bit = (binaryNum & 1);
    decimal =  bit * pow(2, i++) + decimal ;
    binaryNum = binaryNum >> 1;
  }

  return decimal;
}

int main() {

  string binaryInput1;
  int binaryInput2;
  cin >> binaryInput1;
  cin >> binaryInput2;

  int binaryNumber = stoi(binaryInput1, 0, 2);

  int decimalNum1 = binaryToDecimalMethod1(binaryInput2);
  int decimalNum2 = binaryToDecimalMethod2(binaryNumber);
  cout << decimalNum1 << endl;
  cout << decimalNum2 << endl;

  return 0;
}