#include<iostream>
using namespace std;
 
int main() {
  
  //For loop

  // for(int i = 10; i>=0; i= i - 1) {
  //   cout << i << endl;
  // }

  // for(int i = 0; i<10; i+=2) {
  //   cout << i << endl;
  // }

  // for(int i = 0; i<10; i++) {
  //   cout << i << endl;
  // }

  for (int i = 0; i < 3; i++)
  {
    cout << "Outer Loop: " << i << endl;

    for (int j = 0; j < 3; j++)
    {
      cout << "Inner Loop: " << j << endl;
    }
    
  }

  /*
    OUTPUT
    Outer Loop: 0
    Inner Loop: 0
    Inner Loop: 1
    Inner Loop: 2
    Outer Loop: 1
    Inner Loop: 0
    Inner Loop: 1
    Inner Loop: 2
    Outer Loop: 2
    Inner Loop: 0
    Inner Loop: 1
    Inner Loop: 2

  */
  

  return 0;
}