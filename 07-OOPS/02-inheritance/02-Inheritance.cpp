#include<iostream>
using namespace std;

class Car {

  public:
    string name = "Audi";
    string color = "white";
    int speed = 120;

  void speedUp() {
    cout << "Speeding..." << endl;
  }


};

class Audi:public Car{
  public:
  void printName() {
    cout << this->name; 
  }

};

class A4:public Audi {
  public:

  void printParentBrand() {
    cout << this->name;
  }
};

int main() {

  A4 a1;
  a1.printParentBrand(); //Audi
  return 0;
}