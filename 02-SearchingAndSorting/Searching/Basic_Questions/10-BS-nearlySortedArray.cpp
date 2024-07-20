#include<iostream>
using namespace std;

int searchInNearlySortedArray(int arr[], int n, int target) {
  int startIndex = 0;
  int endIndex = n-1;
  int targetIndex = -1;
  while(startIndex <= endIndex) {
    int midIndex = startIndex + (endIndex - startIndex) /2;

    //Checking three condition
      //should check index is not negative It may causes array out of bound
    if(midIndex - 1 >=0 && arr[midIndex-1] == target) {
      targetIndex = midIndex-1;
    }
    if(arr[midIndex] == target) {
      targetIndex = midIndex;
    }
      // should check index is not more than array size to avoid index out of bound array
    if(midIndex + 1 <= n && arr[midIndex+1] == target) {
      targetIndex = midIndex+1;
    }

    if(target > arr[midIndex]) {
      //move to right side and next element we already checking so can skip it
      startIndex = midIndex+2;
    } else {
      //move to left side and previous element we already checking so can skip it
      endIndex = midIndex-2;
    }

  }

  return targetIndex;
}

int main() {
  
  int arr[] = {20,10,30,50,40,70,60};
  int n = 7;
  int target = 100;

  int targetIndex = searchInNearlySortedArray(arr,n,target);

  if(targetIndex == -1) {
    cout << target << " Not found " << endl;
  } else {
    cout << target << " found at " << targetIndex << " index" <<  endl;
  }
  return 0;
}

/* TEST CASES
  1. 70 found at 5 index
  2. 10 found at 1 index
  3. 30 found at 2 index
  4. 100 Not found
*/