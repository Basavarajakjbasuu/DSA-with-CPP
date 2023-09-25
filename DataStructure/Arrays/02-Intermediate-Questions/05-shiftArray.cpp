#include<iostream>
using namespace std;

void shiftArrayByRight(int arr[], int n) {

  int temp = arr[n-1];

  for (int i = n; i > 0; i--)
  {
    arr[i] = arr[i - 1];
  }

  arr[0] = temp;
} 

void outputArray(int arr[], int n) {
  cout << "Displaying array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main() {

  int arr[5] = {10, 20, 30, 40, 50};
  int n = 5;
  shiftArrayByRight(arr, n);
  outputArray(arr, n);
  return 0;
}

/*
  int arr[5] = {10, 20, 30, 40, 50};
  Displaying array: 50 10 20 30 40 
*/