#include<iostream>
using namespace std;

int findFirstOccurrence(int arr[], int size, int key) {
  int startIndex = 0;
  int lastIndex = size - 1;

  int ans = -1;
  while (startIndex <= lastIndex)
  {
    int midIndex = startIndex + (lastIndex - startIndex) / 2;

    if(key == arr[midIndex]) {
      ans = midIndex;

      lastIndex = midIndex - 1;
    } else if(key > arr[midIndex]) {

      startIndex = midIndex + 1;

    } else if(key < arr[midIndex]) {

      lastIndex = midIndex - 1;

    }
  }

  return ans;
} 

int main() {

  int inArr[7] = {10, 20, 20, 30, 30, 60, 60};
  int key = 30;
  int size = 7;

  cout << "First occurrence of " << key << " is " << findFirstOccurrence(inArr, size, key);
  return 0;
}

/*
  First occurrence of 60 is 5
*/