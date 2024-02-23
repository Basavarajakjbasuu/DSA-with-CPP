#include<iostream>
using namespace std;
 
int findMissingElement(int arr[], int size) {
  int startIndex = 0;
  int lastIndex = size - 1;

  int ans = -1;

  while(startIndex <= lastIndex) {

    int midIndex = startIndex + (lastIndex - startIndex) / 2;

    int diff = arr[midIndex] - midIndex;

    // cout << "dif" << diff << endl;
    if(diff == 1) {
      // check in right side
      startIndex = midIndex + 1;
    } else {
      ans = midIndex;

      lastIndex = midIndex - 1;
    }

  }

  if(ans + 1 == 0)
    return size + 1;

  return ans + 1;
}

int findMissingElement1(int arr[], int size) {
    int startIndex = 0;
    int lastIndex = size - 1;

    while (startIndex <= lastIndex) {
        int midIndex = startIndex + (lastIndex - startIndex) / 2;

        if (arr[midIndex] == midIndex + arr[0]) {
            startIndex = midIndex + 1;
        } else {
            lastIndex = midIndex - 1;
        }
    }

    // Return the missing element
    return arr[startIndex] - 1;
}
int main() {
  // int inArr[7] = { 1,2,3,4,6,7,8};
  int inArr[7] = { 2,4,6,8,10,14,16};
  int size = 7;

  cout << "Missing element is: " << findMissingElement(inArr, size);
  return 0;
}