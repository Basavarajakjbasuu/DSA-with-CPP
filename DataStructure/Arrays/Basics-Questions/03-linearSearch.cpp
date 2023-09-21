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

bool linearSearch(int arr[], int n, int key) {

  for (int i = 0; i < n; i++)
  {
    if(key == arr[i]) {
      cout << "Value found at index " << i << endl;
      return true;
    }
  }

  return false;
}

int main() {

  int arr[8];
  inputArray(arr, 8);
  outputArray(arr, 8);

  int key = 0;
  cin >> key;

  linearSearch(arr, 8, key);
  return 0;
}

/*
  Enter 8 values for Array: 1 3 6 8 9 4 2 4 
  Displaying array: 1 3 6 8 9 4 2 4 
  4
  Value found at index 5
*/