#include<iostream>
using namespace std;

int getQuotient(int dividend, int divisor){

  if(dividend == 0) {
    return dividend;
  }else if(divisor == 0) {
    return divisor; //Infinity
  }


  int startIndex = 0;
  int endIndex = dividend;

  int ans = -1;

  while(startIndex <= endIndex) {
    int mid = startIndex + (endIndex - startIndex) / 2;

    if(mid*divisor == dividend) {
      return mid;
    }else if(mid*divisor < dividend) {
      ans = mid;
      //  move to right
      startIndex = mid + 1;
    }else {
      // move to left
      endIndex = mid - 1;
    }
  }

  return ans;
}

int main() {

  int dividend = 35;
  int divisor = -1;

  int result = getQuotient(abs(dividend), abs(divisor));

  // handling negative input - just add negative sign based on cond
  if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
    result = 0 - result;
  } 

  cout << "Quotient of " << dividend << "/" << divisor << " is: " << result << endl;
  return 0;
}

/*
  TestCases

    1.
      int dividend = 29;
      int divisor = 7;

      cout << "Quotient of " << dividend << "/" << divisor << " is: " << getQuotient(dividend, divisor) << endl;

      Quotient of 29/7 is: 4

    2
      int dividend = 35;
      int divisor = 1;

      cout << "Quotient of " << dividend << "/" << divisor << " is: " << getQuotient(dividend, divisor) << endl;

      Quotient of 35/1 is: 35

    3.
      int dividend = 500500;
      int divisor = 2575;

      cout << "Quotient of " << dividend << "/" << divisor << " is: " << getQuotient(dividend, divisor) << endl;

      Quotient of 500500/2575 is: 194

    4.
      int dividend = 35;
      int divisor = -1;

      Quotient of 35/-1 is: -35

    5.
      int dividend = -35;
      int divisor = -1;

      Quotient of 35/-1 is: 35

    6.
      int dividend = -35;
      int divisor = 1;

      Quotient of 35/-1 is: -35
*/