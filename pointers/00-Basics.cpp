#include<iostream>
using namespace std;
 
int f(int x, int *py, int **ppz ) {
  int y , z;

  **ppz += 1;
  z = **ppz;
  *py += 2;
  y = *py;
  x += 3;

  return x + y + z;
} 
int main() {

  int c, *b, **a;

  c = 4;
  b = &c;
  a = &b;

  // cout << f(c, b, a);

  int const p = 5;
  cout << ++5;
  return 0;
}