#include<iostream>
using namespace std;

class A {
  public:
  int chemistry;
  A() {
    chemistry = 205;
  }
};

class B {
  public:
  int biology;
};

class D {
  public:
  int chemistry;
  D() {
    chemistry = 504;
  }
};

class C: public A, public B, public D {
  public:
  int maths;
};



int main() {
 
  C obj;
  // cout << obj.biology << " " << obj.chemistry << " " << obj.maths <<  endl; //"C::chemistry" is ambiguousC
  cout << obj.biology << " " << obj.A::chemistry << " " << obj.maths <<  endl;  

  return 0;
}

/*
  568 205 568
*/