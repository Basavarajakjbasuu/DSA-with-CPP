#include<iostream>
using namespace std;
 
int main() {
  
  int num1 = 5;
  int num2 = 10;

  // Arithmetic
  cout << num1 + num2 << endl; // 15
  cout << num1 - num2 << endl; // -5
  cout << num1 * num2 << endl; // 50
  cout << num1 / num2 << endl; // 0 Ex. 3/2 => 1 :=> due to int datatype 
  cout << num1 % num2 << endl; // 5


  // Relational

  int value1 = 7;
  int value2 = 5;

  // comparision opp

  cout << (value1 < value2) << endl; // False
  cout << (value1 > value2) << endl; // True
  cout << (value1 <= value2) << endl; // False
  cout << (value1 >= value2) << endl; // True
  cout << (value1 != value2) << endl; // True
  cout << (value1 == value2) << endl; // false

  // 3. Logical
  /*
    && - AND => Both condition should true
    || - OR  => Any one condition should true
    ! - NOT  => True to False
  */
  
  return 0;
}