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

void heapSort(int arr[], int n) {
  while (n != 1) {
    swap(arr[1], arr[n]);
    n--;
    heapify(arr, n, 1);
  }
}

int main() {
  
  int arr[] = {-1, 5, 10, 15, 20, 25, 12};
  buildHeap(arr, 6);
  cout << "Printing heap: ";
  for (int i = 1; i <= 6; i++)
  {
    cout << arr[i] << " ";
  }
  cout <<  endl;
  // Printing heap: 25 20 15 5 10 12 


  heapSort(arr, 6);
  cout << "Printing heap: ";
  for (int i = 1; i <= 6; i++)
  {
    cout << arr[i] << " ";
  }
  cout <<  endl;
  //Printing heap: 5 10 12 15 20 25 

  return 0;
}