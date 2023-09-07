#include<iostream>
using namespace std;
 
double ariaOfCircle(double radius) {
  return 3.14 * radius * radius;
}
int main() {

  double radius;
  cin >> radius;

  cout << "Area of circle with " << radius << " radius is: " << ariaOfCircle(radius); 
  return 0;
}

/*
2.5
Area of circle with 2.5 radius is: 19.625
*/