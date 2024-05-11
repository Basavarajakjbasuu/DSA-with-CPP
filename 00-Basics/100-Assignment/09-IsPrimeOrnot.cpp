#include<iostream>
using namespace std;

bool isPrime(int num) {
  int i = 2;

  for( i=2; i<num; i++) {
    if(num%i == 0) {
      return false;
    }
  }

  return true;

} 

int main() {
  
 int n;
  cout << "Enter the num: ";
  cin >> n;

  if(isPrime(n)) {
    cout<< n << " is Prime" << endl;
  } else {
    cout<< n << " is non-prime" << endl;
  } 

  return 0;
}

/*
  Enter the num: 3
  3 is Prime

  Enter the num: 9
  9 is non-prime

  Enter the num: 4
  4 is non-prime
*/