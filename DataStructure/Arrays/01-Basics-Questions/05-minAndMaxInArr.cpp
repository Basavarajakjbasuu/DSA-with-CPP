#include<iostream>
#include<limits.h>
using namespace std;

void inputArray(int arr[], int n) {

  cout << "Enter " << n << " values for Array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
} 

void outputArray(int arr[], int n) {
  cout << "Displaying array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void minAndMaxInArray(int arr[], int n) {

  int minimumValue = INT_MAX;
  int maximumValue = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    if(arr[i] < minimumValue) {
      minimumValue = arr[i];
    }
    if(arr[i] > maximumValue) {
      maximumValue = arr[i];
    } 
  }

  cout << "Minimum value: " << minimumValue << " and Maximum value: " << maximumValue << endl;
}
int main() {

  int arr[7];

  inputArray(arr, 7);
  outputArray(arr, 7);
  minAndMaxInArray(arr, 7);
  return 0;
}

/*
  Enter 7 values for Array: 1 -4 22 56 778 44 78
  Displaying array: 1 -4 22 56 778 44 78 
  Minimum value: -4 and Maximum value: 778
*/