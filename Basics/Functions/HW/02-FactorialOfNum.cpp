#include<iostream>
using namespace std;

int factorial(int num) {
  int res = 1, i;
  for (i = 2; i <= num; i++) {
    res *= i;
  }

  return res;
}


int main() {

  int num;
  cin >> num;

  cout << "factorial is: " << factorial(num); 
  
  return 0;
}

/*
6
factorial is: 720
*/