#include<iostream>
using namespace std;
 
int main() {

  int a = 5;
  // cout << (++a) << endl; // 6
   cout << (a++) << endl; //5 

  for (int i = 0; i < 5; ++i)
  {
    cout << i << " ";
  } // 0 1 2 3 4

  cout << (a++) * (++a); //48
  return 0;
}