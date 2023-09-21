#include<iostream>
#include<vector>
using namespace std;

/*
  FInd the maximum element - pivot in sorted and rotated array

  EX.

    here arr is sorted and rotated
    12, 14, 16, 2, 4, 6, 8, 10
    ----------  --------------
        A             B

    here maximum element is 16 
*/
int findPivotElement(vector<int>&arr ) {

  int n = arr.size();
  int startIndex = 0;
  int endIndex = n - 1;

  int mid = startIndex + (endIndex - startIndex) / 2;

  while (startIndex <= endIndex) 
  {
    // array as single element
    if(startIndex == endIndex){
      return startIndex;
    }
    else if(mid+1 < n && arr[mid] > arr[mid + 1]){
      return mid;
    }else if(mid - 1 >= 0 && arr[mid] < arr[mid-1]) {
      return mid - 1;
    } 
    else if(arr[startIndex] > arr[mid]) {
      // left search
      endIndex = mid - 1;
    } else {
      // right search
      startIndex = mid + 1;
    }

    mid = startIndex + (endIndex - startIndex) / 2;
  }

  return -1;
}

int main() {

  vector<int> inArr;

  inArr.push_back(10);
  inArr.push_back(12);
  inArr.push_back(14);
  inArr.push_back(16);
  inArr.push_back(2);
  inArr.push_back(4);
  inArr.push_back(8);

  cout << findPivotElement(inArr);

  return 0;
}