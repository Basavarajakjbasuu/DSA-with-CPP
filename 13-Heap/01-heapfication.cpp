#include<iostream>
using namespace std;

void heapify(int *arr, int n, int index) {
  int leftIndex = 2*index;
  int rightIndex = 2*index+1;
  int largestIndex = index;

  if(leftIndex <= n && arr[leftIndex] > arr[largestIndex]) {
    largestIndex = leftIndex;
  }
  if(rightIndex <= n && arr[rightIndex] > arr[largestIndex]) {
    largestIndex = rightIndex;
  }

  //After above code largestIndex is pointing towards largest element
  if(index != largestIndex) {
    swap(arr[index], arr[largestIndex]);
    index = largestIndex;
    heapify(arr, n, index);
  }
}

void buildHeap(int arr[], int n) {
  for(int index = n/2; index>0; index--) {
    heapify(arr, n, index);
  }
}
int main() {
 
  
  return 0;
}