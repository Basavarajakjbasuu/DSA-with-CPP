#include<iostream>
using namespace std;
 
void transposeOfMatrix(int arr[][5], int rowCount, int colCount) {

  if(rowCount != colCount) {
    cout << "Row count and column count must be same: " << endl;
    return;
  }

  for(int i = 0; i< rowCount; i++) {

    for(int j = i+1; j<colCount; j++) {
      swap(arr[i][j], arr[j][i]);
    }

  }
} 

void output2DArray(int arr[][5], int rowCount, int colCount) {

  for (int row = 0; row < rowCount; row++)
  {
    for (int col = 0; col < colCount; col++)
    {
      cout << arr[row][col] << " ";
    }

    cout << endl;
  }
  
} 


int main() {
  int arr[4][5] = {
                  {1, 2, 3, 4, },
                  {6, 7, 8, 9, },
                  {10, 11, 12, 13, },
                  {14, 15, 16, 17, },
                };
  int rowCount = 4, colCount = 5;

  output2DArray(arr, rowCount, colCount); 
  transposeOfMatrix(arr, rowCount, colCount);
  output2DArray(arr, rowCount, colCount); 
  return 0;
}

/*
  INP
      1 2 3 4 
      6 7 8 9 
      10 11 12 13 
      14 15 16 17 

  OUT
      1 6 10 14 
      6 7 11 15 
      10 11 12 16 
      14 15 16 17 
*/