#include<iostream>
using namespace std;

void giveDigits(int number) {

  while(number) {
    int onePlaceDigit = number % 10;
    cout << "Digits: " << onePlaceDigit << endl;
    number /=10;
  }
}


int main() {
  int number=0;

  cout << "Enter the number to see digits: ";
  cin >> number;

  giveDigits(number);
  return 0;
}

/*
  Enter the number to see digits: 7895
  Digits: 5
  Digits: 9
  Digits: 8
  Digits: 7
*/