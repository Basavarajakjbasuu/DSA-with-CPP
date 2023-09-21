#include<iostream>
using namespace std;

void columnViceSum(int arr[3][3], int rowCount, int colCount){

  for (int col = 0; col < colCount; col++)
  {
    int colSum = 0;
    for (int row = 0; row < rowCount; row++)
    {
      colSum += arr[row][col];
    }

    cout << colSum << endl;
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

  columnViceSum(arr, rowCount, colCount);
  return 0;
}

/*
  15
  5664
  21
*/