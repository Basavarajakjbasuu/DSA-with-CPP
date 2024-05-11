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

  for (int i=2; i<=n; i++) {
    bool isPrimeNum = isPrime(i);

    if(isPrimeNum) {
      cout << i << " ";
    }
  }
  cout << endl;
  
  return 0;
}

/*
Enter the num: 20
2 3 5 7 11 13 17 19 
Enter the num: 50
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
*/