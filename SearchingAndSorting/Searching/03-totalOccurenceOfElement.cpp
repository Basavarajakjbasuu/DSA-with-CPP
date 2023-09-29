#include<iostream>
using namespace std;

int findFirstOccurrence(int arr[], int size, int key) {
  int startIndex = 0;
  int lastIndex = size - 1;

  int ans = -1;
  while(startIndex <= lastIndex) {
    int midIndex = startIndex + (lastIndex - startIndex) / 2;

    if(key == arr[midIndex]) {
      ans = midIndex;

      lastIndex = midIndex - 1;
    }else if(key > arr[midIndex]) {
      startIndex = midIndex + 1;
    } else if(key < arr[midIndex]) {
      lastIndex = midIndex - 1;
    }
  }

  return ans;
} 

int findLastOccurrence(int arr[], int size, int key) {
  int startIndex = 0;
  int lastIndex = size - 1;

  int ans = -1;
  while(startIndex <= lastIndex) {
    int midIndex = startIndex + (lastIndex - startIndex) / 2;

    if(key == arr[midIndex]) {
      ans = midIndex;

      startIndex = midIndex + 1;
    }else if(key > arr[midIndex]) {
      startIndex = midIndex + 1;
    } else if(key < arr[midIndex]) {
      lastIndex = midIndex - 1;
    }
  }

  return ans;
}

int totalOccurrence(int arr[], int size, int key) {

  return findLastOccurrence(arr, size, key) - findFirstOccurrence(arr, size, key) + 1;
}
int main() {
  
  int inArr[7] = { 20, 30, 30, 30, 30, 60, 60};
  int key = 30;
  int size = 7;

  cout << "Total occurrence of " << key << " is " << totalOccurrence(inArr, size, key) << endl;

  return 0;
}

/*
  Total occurrence of 30 is 4
*/