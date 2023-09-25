#include<iostream>
using namespace std;
 
void shiftNegativeOneSide(int arr[], int size) {

  int isNegativeNumIndex = 0;

  for (int index = 0; index < size; index++)
  {
    if(arr[index] < 0) {
      swap(arr[index], arr[isNegativeNumIndex]);
      isNegativeNumIndex++;
    }
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

int main() {

  // int arr[10] = {-23, 10, 4, 34, 56, -34, 67, 0, -3, -1};
  int arr[6] = {3, -2, -1, 0, -4, 5};

  int size = 6;
  shiftNegativeOneSide(arr, size);
  outputArray(arr, size);
  return 0;
}