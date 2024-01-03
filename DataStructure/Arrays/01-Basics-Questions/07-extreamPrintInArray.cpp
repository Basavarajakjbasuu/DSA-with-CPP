#include<iostream>
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

void extremePrint(int arr[], int size) {

  int leftIndex = 0;
  int rightIndex = size - 1;

  while(leftIndex <= rightIndex) {

    // Handling odd element case
    if ( leftIndex == rightIndex) {
      cout << arr[leftIndex] << " ";
    } else {
      cout << arr[leftIndex] << " ";
      cout << arr[rightIndex] << " ";
    }
    
    leftIndex++;
    rightIndex--;

  }
}

int main() {
 
  int arr[7];
  int size = 7;

  inputArray(arr, size);
  outputArray(arr, size);
  extremePrint(arr, size);
  return 0;
}

/*
  Enter 8 values for Array: 1 2 3 4 5 6 7 8
  Displaying array: 1 2 3 4 5 6 7 8 
  1 8 2 7 3 6 4 5 

  Enter 7 values for Array: 2 4 6 8 10 12 14
  Displaying array: 2 4 6 8 10 12 14 
  2 14 4 12 6 10 8 
*/