#include<iostream>
#include<vector>
using namespace std;
 
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row * col;

        int startIndex = 0;
        int endIndex = n - 1;


        while(startIndex <= endIndex) {
            int mid = startIndex + (endIndex - startIndex)/2;
            // conversion form 1D -> 2D array
            int rowIndex = mid / col;
            int colIndex = mid % col;

            int currNumber = matrix[rowIndex][colIndex];

            if(currNumber == target) {
                return true;
            }else if (target > currNumber){
                startIndex = mid + 1;
            }else {
                endIndex = mid - 1;
            }
        }

        return false;
    } 

int main() {

  vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
  int target = 50;

  cout << "Is value there: " << searchMatrix(matrix, target);

  return 0;
}

/*
  TestCases

  1.
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 16;
    Is value there: 1

  2.
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 50;
    Is value there: 0


*/