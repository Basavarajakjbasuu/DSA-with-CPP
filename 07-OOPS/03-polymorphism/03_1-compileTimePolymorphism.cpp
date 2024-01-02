#include<iostream>
using namespace std;
 
// FUNCTION OVERLOADING
class Maths {
  public:

  int sum(int a, int b) {
    return a + b;
  }

  int sum(int a, int b, int c) {
    return a + b + c;
  }

  float sum(float f1, int i1) {
    return f1 + i1;
  }
}; 

//OPERATOR OVERLOADING
class Parameter {
  public:
  int val;

  void operator+(Parameter& obj2) {
    int value1 = this->val;
    int value2 = obj2.val;
    cout << (value2 - value1);
  }

};
int main() {
 
  Maths obj;

  cout << obj.sum(2, 5) << endl; // 7
  cout << obj.sum(2, 5, 3) << endl; // 10
  cout << obj.sum(2.5f, 5) << endl; // 7.5

  Parameter object1, object2;
  object1.val = 8;
  object2.val = 3;

   object1+object2; // -5
  return 0;
}