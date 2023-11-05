#include<iostream>
using namespace std;

class Student {

  // States Or Properties
  int id;
  public:
  int age;
  string name;

  // Behaviour
  void study() {
    cout << "He is studying" << endl;
  }

  void assignment() {
    cout << "Assignment submited" << endl;
  }

  //Getter function
  int getId() {
    return id;
  }

  //Setter function
  void setId(int id)  {
    this->id = id;
  }
};

class Animal {

  public:
  int age;
  int weight;
  string name;

  //Default constructor
  Animal() {
    this->age = 0;
    this->weight = 0;
    this->name = "";
    cout << "Constructor calling..." << endl;
  }

  //Parameterized constructor
  Animal(int age) {
    cout << "Parameterized constructor..." << endl;
    this->age = age;
  }

  //COpy constructor
  Animal(Animal &obj) {
    this->age = obj.age;
    this->weight = obj.weight;
    this->name = obj.name;
    cout << "Copy constructor called..." << endl;
  }
};

int main() {

  Animal an(23);
  Animal *an1 = new Animal(34);

  // object copy
  Animal an2 = an;
  // Animal an3(an2);
  //Object creation
  Student stud1;

  //Static allocation
  stud1.age = 24;
  cout << "Name of Student: " << stud1.name << endl;
  cout << "Age of Student: " << stud1.age << endl;

  stud1.study();
  stud1.assignment();

  stud1.setId(234);
  cout << "Student Id: " << stud1.getId() << endl;

  //Dynamic allocation

  Student *stud2 = new Student;
  (*stud2).age = 13;
  (*stud2).name = "Sham";

  cout << "Name of Student: " << (*stud2).name << endl;
  cout << "Age of Student: " << (*stud2).age << endl;
  // Name of Student: Sham
  // Age of Student: 13

  stud2->age = 56;
  stud2->name = "Shital";

  cout << "Name of Student: " << stud2->name << endl;
  cout << "Age of Student: " << stud2->age << endl;
  // Name of Student: Shital
  // Age of Student: 56

  stud2->assignment();
  // Assignment submited

  return 0;
}

/*
  Name of Student: 
  Age of Student: 24
  He is studying
  Assignment submited
  Student Id: 234
*/