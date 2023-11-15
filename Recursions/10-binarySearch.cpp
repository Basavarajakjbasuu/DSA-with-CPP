#include<iostream>
using namespace std;

int binarySearch(int arr[], int startIndex, int endIndex,  int target) {

  //Base Case
  if(startIndex > endIndex) {
    return -1;
  }

  //Processing
  int midIndex = startIndex + (endIndex - startIndex)/2;
  if(arr[midIndex] == target) {
    return midIndex;
  }

  if(arr[midIndex < target]) {
    startIndex = midIndex + 1;

    return binarySearch(arr, startIndex, endIndex, target);
  } else {
    endIndex = midIndex - 1;
    return binarySearch(arr, startIndex, endIndex, target);
  }
}


int main() {
 
  int arr[6] = {2, 4, 6, 8, 10, 12};
  int size = 6;
  int index = 1;
  int target = 150;

  int result = binarySearch(arr, 0, size - 1, target);
  
  if(result == -1) {
    cout << "Element not found" << endl;
  } else {
    cout << "Element found at index: " << result << endl;
  }
  return 0;
}

/*  Time Complexity: O(logn)
    Space Complexity: O(logn)

    Element found at index: 4
    > 150
    Element not found
*/