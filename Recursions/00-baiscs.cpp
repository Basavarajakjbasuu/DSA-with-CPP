#include<iostream>
using namespace std;
 
int func1(int x, int y) {
  if(x == 0) {
    return y;
  }else {
   return func1(x - 1, x + y);
  }
}

int fibonacci(int n) {
  //Base case
  if(n == 0) return 0;
  if(n == 1) return 1;


  //Recursive call
  return fibonacci(n-1) + fibonacci(n-2);

}

int main() {

  int x = 5, y = 2;
  // cout << func1(x, y);
  // cout <<"Ans: " << fibonacci(4) << endl;
  
  // Fibonacci series
  int n = 5;
  for(int i=0; i<n; i++) {
    cout << fibonacci(i) << " ";
  }

  cout << endl;
  return 0;
}