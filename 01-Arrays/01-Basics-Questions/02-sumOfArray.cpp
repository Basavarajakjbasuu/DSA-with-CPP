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

int sumOfArray(int arr[], int n) {

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }

  return sum;
}
int main() {
  
  int arr[5];
  inputArray(arr, 5);
  outputArray(arr, 5);

  cout << "Sum of Array is: " << sumOfArray(arr, 5) << endl;
  return 0;
}

/*
  Enter 5 values for Array: 1 2 3 4 5
  Displaying array: 1 2 3 4 5 
  Sum of Array is: 15
*/