#include <iostream>
using namespace std;

int f(int x, int *py, int **ppz)
{
  int y, z;

  **ppz += 1;
  z = **ppz;
  *py += 2;
  y = *py;
  x += 3;

  return x + y + z;
}
int main()
{


  // int a = 100, b =200;
  // int *p = &a, *q = &b;


  // cout << "p" <<p << endl;
  // cout <<"q" << q << endl;
  // p = q;
  // cout <<"p" << p << endl;
  // cout <<"q" << q << endl;

  // char st[] = "ABCD";
  // for(int i=0; st[i] != '\0'; i++) {

  //   cout << st[i] << *(st)+i << *(st+i) << i[st]<< endl;
  // }

  int const pt =5;
  cout << ++pt;

  int *arr = new int*[10];
  return 0;
}