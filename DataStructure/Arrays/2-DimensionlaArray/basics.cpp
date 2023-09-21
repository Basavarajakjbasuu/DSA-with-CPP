#include<iostream>
using namespace std;
 
void output2DArray(int arr[3][3], int rowCount, int colCount) {

  for (int row = 0; row < rowCount; row++)
  {
    for (int col = 0; col < colCount; col++)
    {
      cout << arr[row][col] << " ";
    }

    cout << endl;
  }
  
} 

void printColumnVice(int arr[3][3], int rowCount, int colCount) {

  for (int col = 0; col < colCount; col++)
  {
    for (int row = 0; row < rowCount; row++)
    {
      cout << arr[row][col] << " ";
    }
    cout << endl;
  }
  
}

void input2DArray(int arr[3][3], int rowCount, int colCount) {

  for (int row = 0; row < rowCount; row++)
  {
    for (int col = 0; col < colCount; col++)
    {
      cout << "Enter input for row [" << row << "] and col [" << col << "] = ";
      cin >> arr[row][col];
    }

  }
  
}
int main() {

  // Init and creation
  int arr[3][3] = {
                   {2, 3, 4}, 
                   {5, 6, 7},
                   {8, 9, 10},
                  };

  // Accessing
  // cout << arr[0][0];
  // cout << arr[0][1];
  // cout << arr[0][2];
  // cout << arr[1][0];
  // cout << arr[1][1];
  // cout << arr[1][2];

  // 234567

  output2DArray(arr, 3, 3); /*
    2 3 4 
    5 6 7 
    8 9 10
  */

  printColumnVice(arr, 3, 3); /*
    2 5 8 
    3 6 9 
    4 7 10 
  */

  int barr[3][3];
  input2DArray(barr, 3, 3);
  output2DArray(barr, 3, 3);

  /*
    Enter input for row [0] and col [0] = 3
    Enter input for row [0] and col [1] = 6
    Enter input for row [0] and col [2] = 9
    Enter input for row [1] and col [0] = 4
    Enter input for row [1] and col [2] = 12
    Enter input for row [2] and col [0] = 5
    Enter input for row [2] and col [1] = 10
    Enter input for row [2] and col [2] = 15

    3 6 9 
    4 8 12 
    5 10 15 
  */
  return 0;
}