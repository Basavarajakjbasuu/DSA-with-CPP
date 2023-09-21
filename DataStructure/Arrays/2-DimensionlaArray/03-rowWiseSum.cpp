#include<iostream>
using namespace std;

void rowWiseSum(int arr[3][3], int rowCount, int colCount) {

  for (int row = 0; row < rowCount; row++)
  {
    int sum = 0;
    for (int  col = 0; col < colCount; col++)
    {
      sum += arr[row][col];
    }

    cout << sum << endl;
  }
}

int main() {
 
  int arr[3][3] = {
                  {2, 3, 4},
                  {5, -6, 7},
                  {8, 5667, 10},
                };

  int rowCount = 3;
  int colCount = 3;

  rowWiseSum(arr, rowCount, colCount);

  return 0;
}

/*
  9
  6
  5685
*/