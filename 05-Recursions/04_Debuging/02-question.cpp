#include<iostream>
using namespace std;

double myPow(double x, int n) {

    int p = abs(n);
    double ans = 1.0;
    while( p>0 ){

      if(p%2 == 1) {
        ans *= x;
      }
      p /= 2 ;
      x *= x;
    }
    return n<0 ? 1/ans : ans;    
}

int main() {
 
  cout << "2 power 4 is " << myPow(2, 10);
  return 0;
}