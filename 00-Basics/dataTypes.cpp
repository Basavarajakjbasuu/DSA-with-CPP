#include<iostream>
using namespace std;
 
int main() {
 
  
  // garbage value
  int num;
  cout << num << endl; //455Xe44

  //--------- Primitive/ Builtin DataTypes --------
  
  // int - 4bytes
  int num = 50;
  cout << sizeof(num) << endl; // 4

  // char - 1bytes
  char ch = 'b';
  cout << sizeof(char) << endl; // 1

  // float - 4bytes
  float points = 34.566;
  cout << sizeof(points) << endl; // 4

  // long - 4 bytes
  long values = 34.567777;
  cout << sizeof(values) << endl; // 4

  // long long - 8 bytes
  long long values1 = 34.567777;
  cout << sizeof(values1) << endl; // 8

  // double - 8 bytes
  double point = 5.66666666666666;
  cout << sizeof(point) << endl; // 8

  return 0;
}