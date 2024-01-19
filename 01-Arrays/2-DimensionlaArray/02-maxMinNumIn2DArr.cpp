#include<iostream>
using namespace std;

int findMaximumValue(int arr[3][3], int rowCount, int colCount) {
  int maximumValue = INT_MIN;

    for (int row = 0; row < rowCount; row++)
  {
    for (int  col = 0; col < colCount; col++)
    {
      if(maximumValue < arr[row][col]) {
        maximumValue = arr[row][col];
      }
    }
    
  }

  return maximumValue;
}

int minimumValueIn2D(int arr[3][3], int rowCount, int colCount ) {
  int minimumValue = INT_MAX;

  for (int row = 0; row < rowCount; row++) {
    for (int col = 0; col < colCount; col++) {
      if(minimumValue > arr[row][col]) {
        minimumValue = arr[row][col];
      }
    }
  }

  return minimumValue;
}
int main() {
 
  int arr[3][3] = {
                  {2, 3, 4},
                  {5, -6, 7},
                  {8, 5667, 10},
                };

  int rowCount = 3;
  int colCOunt = 3;
  cout << findMaximumValue(arr, rowCount, colCOunt) << endl; // 5667
  cout << minimumValueIn2D(arr, rowCount, colCOunt) << endl; // -6
  return 0;
}