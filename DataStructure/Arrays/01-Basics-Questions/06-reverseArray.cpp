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

void reverseArray(int arr[], int n){

  int leftIndex = 0, rightIndex = n - 1;

  while(leftIndex < rightIndex) {

    swap(arr[leftIndex], arr[rightIndex]);

    leftIndex++;
    rightIndex--;
  }

}
int main() {

  int arr[7];
  int n = 7;
  inputArray(arr, n);
  outputArray(arr, n);
  cout << "=========After Reverse=========\n";
  reverseArray(arr, n);
  outputArray(arr, n);

  return 0;
}

/*
  Even values:
  ------------
  Enter 8 values for Array: -1 -3 4 5 -6 -3  10 23
  Displaying array: -1 -3 4 5 -6 -3 10 23 
  =========After Reverse=========
  Displaying array: 23 10 -3 -6 5 4 -3 -1

  Odd values:
  Enter 7 values for Array: 1 4 6 7 8 9 3
  Displaying array: 1 4 6 7 8 9 3 
  =========After Reverse=========
  Displaying array: 3 9 8 7 6 4 1
*/