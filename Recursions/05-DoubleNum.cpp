#include<iostream>
using namespace std;

void doubleArray(int arr[], int size, int index) {
  //BASE CASE
  if(index >= size) {
    return;
  }

  arr[index] = 2 * arr[index];

  doubleArray(arr, size, index + 1);
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << ' ';
  }

  cout << endl;
}

int main() {

  int arr[6] = {2, 4, 6, 8, 10, 12};
  int size = 6;
  int index = 0;

  doubleArray(arr, size, index);
  printArray(arr, size); //4 8 12 16 20 24 
  return 0;
}