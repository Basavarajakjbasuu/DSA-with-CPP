#include<iostream>
using namespace std;

class Car {
  public:
  int speed = 140;

  void speedUp() {
    cout << "Speeding...";
  }
};

class audi: public Car {

};

class Benz: public Car {

};

int main() {
 
  Benz obj;
  obj.speedUp();
  cout << obj.speed << endl;
  return 0;
}