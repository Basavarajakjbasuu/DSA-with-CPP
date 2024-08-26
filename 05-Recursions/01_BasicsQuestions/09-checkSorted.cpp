#include<iostream>
using namespace std;

bool checkSorted(int arr[], int size, int index) {
  //BASE CASE
  if(index >= size) {
    return true;
  }


  //Processing
  if(arr[index] > arr[index-1]) {
    //Check next element
    bool nextAns = checkSorted(arr, size, index + 1);
    return nextAns;
  } else {
    //array is not sorted
    return false;
  }

} 

int main() {
  
  int arr[6] = {2, 4, 6, 8, 10, 12};
  int size = 6;
  int index = 1;

  bool isSorted = checkSorted(arr, size, index);

  if(isSorted) {
    cout << "Array is sorted." << endl;
  }else {
    cout << "Array is not sorted." << endl;
  }

  return 0;
}

/*
  int arr[6] = {2, 4, 6, 18, 10, 12};
  Array is not sorted.

  int arr[6] = {2, 4, 6, 8, 10, 12};
  Array is sorted.

  int arr[1] = {2};
  Array is sorted.

  int arr[] = {};
  Array is sorted.
*/