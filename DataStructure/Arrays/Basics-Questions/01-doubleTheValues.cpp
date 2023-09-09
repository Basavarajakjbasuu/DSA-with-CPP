#include<iostream>
using namespace std;
 
/*
  => Take 10 values from user
  => double those values
  => Print the result
*/ 
int main() {

  int arr[10];

  for (int i = 0; i < 10; i++)
  {
    cout << "Enter values for index " << i << ": ";
    cin >> arr[i];
  }

  for (int i = 0; i < 10; i++) {
    arr[i] *= 2;
  }

  cout << "doubled values is: ";
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
    return 0;
}

/*
  Enter values for index 0: 1
  Enter values for index 1: 2
  Enter values for index 2: 3
  Enter values for index 3: 4
  Enter values for index 4: 5
  Enter values for index 5: 6
  Enter values for index 6: 7
  Enter values for index 7: 8
  Enter values for index 8: 9
  Enter values for index 9: 10
  doubled values is: 2 4 6 8 10 12 14 16 18 20 
*/