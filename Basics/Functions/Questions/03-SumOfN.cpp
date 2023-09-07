#include<iostream>
using namespace std;
 
/**
 *  Sum of natural numbers
 */ 

int sumOfN(int lastNum) {
  return (lastNum*(lastNum + 1)) / 2;
}
int main() {

  cout << sumOfN(10) << endl; //55
  return 0;
}