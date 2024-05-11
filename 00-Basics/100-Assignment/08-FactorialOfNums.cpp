#include<iostream>
using namespace std;

int factorialOfNum(int num) {
  int fact = 1;
  for(int i=1; i<=num; i++) {
    fact = fact * i;
  }
  return fact;
}

int main() {
 
 int n;
  cout << "Enter the num: ";
  cin >> n;

  cout << "Factorial value of " << n << " is: " << factorialOfNum(n) << endl;
  return 0;
}

/*
  Enter the num: 5
  Factorial value of 5 is: 120

  Enter the num: 6
  Factorial value of 6 is: 720
*/