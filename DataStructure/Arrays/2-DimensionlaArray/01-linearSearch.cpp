#include<iostream>
using namespace std;
 
bool linearSearchOf2DArray(int arr[3][3], int rowCount, int colCount, int key) {

  for (int row = 0; row < rowCount; row++)
  {
    for (int  col = 0; col < colCount; col++)
    {
      if(arr[row][col] == key) {
        return true;
      }
    }
    
  }

  return false;
} 
int main() {
 
  int arr[3][3] = {
                  {2, 3, 4}, 
                  {5, 6, 7},
                  {8, 9, 10},
                };

  int rowCount = 3;
  int colCOunt = 3;
  int key = 9;
  cout << linearSearchOf2DArray(arr, rowCount, colCOunt, key) << endl; // 1
  return 0;
}