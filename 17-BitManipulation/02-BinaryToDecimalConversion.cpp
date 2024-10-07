#include<iostream>
using namespace std;

int convertToDecimal(string binNum) {
  int len = binNum.length(), pow2=1, num=0;

  //Right to left reading
  for(int i=len-1; i>=0; i--) {

    if(binNum[i] == '1')
      num +=pow2;
    pow2 *=2;
  } 

  return num;
}

int main() {
 
  string binNum = "";
  cout << "Enter binary number: ";
  cin >> binNum;

  cout << "Decimal equivalent of " << binNum << " is: " << convertToDecimal(binNum) << endl;
  return 0;
}

/*
  Enter binary number: 1101     
  Decimal equivalent of 1101 is: 13

  Enter binary number: 1010
  Decimal equivalent of 1010 is: 10

  Enter binary number: 11111101
  Decimal equivalent of 11111101 is: 253
*/