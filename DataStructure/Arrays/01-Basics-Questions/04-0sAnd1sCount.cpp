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

/*
  find the count of 0's and 1's count in an array
*/ 

void countOfZerosAndOnes(int arr[], int n) {

  int zeros = 0, ones = 0;
  
  for (int i = 0; i < n; i++) {
    if(arr[i] == 0) {
      zeros++;
    }
    if(arr[i] == 1) {
      ones++;
    }
  }

  cout << "zeros: " << zeros << " one's: " << ones << endl;
}

int main() {

  int arr[6];

  inputArray(arr, 6);
  outputArray(arr, 6);
  countOfZerosAndOnes(arr, 6);
  return 0;
}