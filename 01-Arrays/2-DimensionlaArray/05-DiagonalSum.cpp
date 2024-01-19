#include<iostream>
using namespace std;

int diagonalSum(int arr[][4], int rowCount, int colCount) {

  if(rowCount != colCount) {
    cout <<"Oops! Diagonal sum not possible" << endl;
    return 0;
  }

  int sum = 0;
  for( int i=0; i< colCount; i++) {
    sum += arr[i][i];
  }

  return sum;
} 

int main() {
 
  int arr[4][4] = {
                    {1, 2, 3, 4},
                    {1, 2, 3, 4},
                    {1, 2, 3, 4},
                    {1, 2, 3, 4},
                  };

int colCount = 4, rowCount = 4; 
cout << "Diagonal sum: " << diagonalSum(arr, rowCount, colCount) << endl;
  
  return 0;
}

/*
  Diagonal sum: 10
*/