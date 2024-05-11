#include<iostream>
using namespace std;

// print count from 1 to N
void printCounting(int n) {
  for (int i = 0; i < n; i++)
  {
    cout << i << endl;
  }
  
}
int main() {

  printCounting(7);
  /*
    0
    1
    2
    3
    4
    5
    6
  */
  return 0;
}