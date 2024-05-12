#include<iostream>
using namespace std;
 
float giveMiles(int km) {

  float _1KmMile = 0.621371;
  return km * _1KmMile;
} 
int main() {
  float kiloMeters = 0.0;

  cout << "Enter kilometers: ";
  cin >> kiloMeters;

  float sol = giveMiles(kiloMeters);

  cout << "Miles: " << sol << endl;
  return 0;
}

/*
  Enter kilometers: 34
  Miles: 21.1266
  
  Enter kilometers: 1
  Miles: 0.621371
*/