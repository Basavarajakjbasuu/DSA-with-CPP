#include<iostream>
using namespace std;

class Animal {
  public:

   Animal() {
    cout << "Animal constructor" << endl;
   }

   virtual void speak() {
    cout << "Speaking..." << endl;
  }
};

class Dog:public Animal {
  public:
   Dog() {
    cout << "Dog constructor" << endl;
   }
  //Override
  void speak() {
    cout << "Barking..." << endl;
  }
};


int main() {
  
  Dog a;
  a.speak();

  Animal* b = new Animal();
  b->speak(); // Speaking...


  Dog* d = new Dog();
  d->speak(); // Barking...


  //UpCasting
  Animal* a2 = new Dog();
  a2->speak(); // Barking...


  //DownCasting
  Dog* d2 = (Dog* )new Animal();
  d2->speak(); // Barking... -> with virtual key
               // Speaking... -> without virtual keyword 

  Dog* d3 = new Dog(); //Animal constructor
                       // Dog constructor -> both constructor call

  Animal* d4 = new Dog(); //Animal constructor
                       // Dog constructor -> both constructor call



  Animal* a3 = (Dog* ) new Animal(); //Animal constructor
  
  return 0;
}
