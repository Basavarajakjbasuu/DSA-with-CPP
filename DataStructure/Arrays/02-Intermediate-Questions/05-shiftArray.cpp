#include<iostream>
using namespace std;

void shiftArrayByRight(int arr[], int n) {

//  int arr[5] = {10, 20, 30, 40, 50};
  // Displaying array: 50 10 20 30 40 
  int temp = arr[n-1];

  for (int i = n-1; i >= 1; i--)
  {
    arr[i] = arr[i - 1];
  }

  arr[0] = temp;
} 

void shiftArrayByLeft(int arr[], int n) {

  int temp = arr[0];

  for(int i=0; i<n-1; i++) {

    arr[i] = arr[i+1];
  }

  arr[n-1] = temp;
}


void outputArray(int arr[], int n) {
  cout << "Displaying array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}


void rightShiftArrayByPos(int arr[], int n, int k) {

  /*
    10 20 30 40 50 
    n=5
    k =2
    40 50 10 20 30
  */

  if (k<= 0 || k>= n) {
    cout << "Oops! Invalid Input" << endl;
    return;
  }

  int temp[k] = {0};
  for(int i = n-k, j = 0; i<n; i++, j++) {
    temp[j] = arr[i];
  }

  //Shift remaining element by kth postion
  for(int i = n-1; i >=k; i--) {
    arr[i] = arr[i-k];
  }

  for(int i=0; i<k; i++) {
    arr[i] = temp[i];
  }

}


void reverseArray(int arr[], int start, int end) {
  while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

void shiftArrayByK(int arr[], int n, int k) {
  k = k % n; // To handle cases where k is larger than the array size

  // Reverse the entire array
  /*
    10 20 30 40 50
    => 50 40 30 20 10
  */
  reverseArray(arr, 0, n - 1);

  // Reverse the first k elements
  /*
    50 40 30 20 10
    => 40 50 30 20 10
  */
  reverseArray(arr, 0, k - 1);

  // Reverse the remaining elements
  /*
    40 50 30 20 10
    => 40 50 10 20 30
  */
  reverseArray(arr, k, n - 1);
}


int main() {

  int arr[5] = {10, 20, 30, 40, 50};
  int n = 5;
  // shiftArrayByRight(arr, n);
  // shiftArrayByLeft(arr, n);

  // rightShiftArrayByPos(arr, n, 3);

  shiftArrayByK(arr, n, 2);
  outputArray(arr, n);
  return 0;
}

/*
  int arr[5] = {10, 20, 30, 40, 50};
  Displaying array: 50 10 20 30 40 


  10, 20, 30, 40, 50

left-> 20, 30, 40, 50, 10

*/