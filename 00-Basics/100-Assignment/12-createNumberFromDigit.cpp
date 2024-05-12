#include<iostream>
using namespace std;

/*
  Create the final number from user given input digits
  ---
  Multiply each number with 10 and add the next digit
  I/P -> 4
        4*10 = 4
  I/P -> 5
        4*10+5 = 45
  I/P -> 2
        45*10+2 = 450+2 = 452       
*/
int createNumberFromDigits( int numOfDigit) {
  int num = 0;
  for(int i=0; i<numOfDigit; i++) {
    int digit = 0;
    cout << "Enter digit: ";
    cin >> digit;
    num = num*10 + digit;
  }
  return num;
}

int main() {
  int numOfDigits = 0;

  cout << "Enter number of digits: ";
  cin>> numOfDigits;

  int answer = createNumberFromDigits(numOfDigits);
  cout << "Number is: " << answer << endl;

  return 0;
}

/*
  Enter number of digits: 3
  Enter digit: 8
  Enter digit: 2
  Enter digit: 6
  Number is: 826
*/