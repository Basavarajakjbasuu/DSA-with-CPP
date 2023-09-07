#include<iostream>
using namespace std;
 
/*
  Bitwise Operators
*/
int main() {

  int a = 3;
  int b = 2;

  cout << (a & b) << endl; //2

  a = 5, b = 10;
  cout << (a | b) << endl; // 15

  a = 7;
  // HW -> bool is converted to integer so giving this ans
  bool num = 1;
  cout << ~num << endl; //-2
  cout << ~(num) << endl; //-2
  cout << (~num) << endl; //-2
  cout << (~a) << endl; // -8

  a = 6, b = 6;
  cout << (a ^ b) << endl; // 0
  a = 5, b = 10;
  cout << (a ^ b) << endl; // 15
  a = 5, b = -5;
  cout << (a ^ b) << endl; // -2

  /**
   * Left shift Operators
  */

  int num1 = 7;
  cout << (num1 << 1) << endl; // 14 -> 7 * 2
  cout << (num1 << 2) << endl; // 28 -> 7 * 2^2 -> 28
  cout << (num1 << 4) << endl; // 112 -> 7 * 2^4 -> 112

  /**
   * Right shift Operators
  */

  int num2 = 7;
  cout << (num2 >> 1) << endl; // 3 -> 7/2
  cout << (num2 >> 2) << endl; // 1 -> 7/2^2 -> 7/4
  cout << (num2 >> 4) << endl; // 0 -> 7/2^4 -> 7/16
  return 0;
}