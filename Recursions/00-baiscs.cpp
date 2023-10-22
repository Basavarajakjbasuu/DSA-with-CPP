#include<iostream>
using namespace std;
 
int func1(int x, int y) {
  if(x == 0) {
    return y;
  }else {
   return func1(x - 1, x + y);
  }
}
int main() {

  int x = 5, y = 2;
  cout << func1(x, y);
  return 0;
}