#include<iostream>
using namespace std;

void printArray(int arr[], int size, int index) {
  //Base case
  if(index >= size) {
    return;
  }

  //Recursive call
  printArray(arr, size, index + 1);
  
  // Processing
  cout << arr[index] << " ";
}


bool searchArray(int arr[], int size, int target, int index) {
  // Base case
  if(index >= size) {
    return false;
  }
  if(arr[index] == target) {
    return true;
  }

  // Recursive call
  bool nextSearch = searchArray(arr, size, target, index + 1);
  return nextSearch;
}

int main() {

  int arr[] = {10, 20, 30, 40};
  int size = 4;
  int index = 0;

  int target = 30;
  printArray(arr, size, index);
  bool result = searchArray(arr, size, target, index);
  cout << result << endl; //  1 -> True
  return 0;
}

/*
  OUTPUT
  10 20 30 40 

  if Processing after recursive call
  40 30 20 10 
*/