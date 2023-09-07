#include<iostream>
using namespace std;

bool isEvenOrOdd(int num) {
  if(num%2 == 0)
    return true;
  else
    return false;
}

bool isEvenApproach2(int num) {

  if((num ^ 1) == (num + 1))
    return true;
  else
    return false;
}

bool isEvenApproach3(int num) {

  /**
   * Ex
   *  6 -> 0110
   *      6>>1 0011 => 3
   *      6<<1 0011 => 0110 here inital num == final num
   *  9 -> 1001
   *      9>>1 1001 => 0100 
   *      9<<1 0100 => 1000 here inital Num != final num
   * 
  */
  
  if( num == (num >> 1) <<1) {
    return true;
  }else {
    return false;
  }
}

int main() {

  int num = 10;
  if (isEvenOrOdd(num))
  {
    cout << "Even Number";
  }else {
    cout << "Odd number";
  }//Even Number
  cout << endl;

  /*
    Approach2
  */
  isEvenApproach2(7) ? cout << "Even" : cout<< "Odd"; //Odd
  cout << endl;
  /*
    Approach 3
  */

  isEvenApproach3(23) ? cout << "Even num" : cout << "Odd num"; //Odd num
  cout << endl;
  return 0;
}