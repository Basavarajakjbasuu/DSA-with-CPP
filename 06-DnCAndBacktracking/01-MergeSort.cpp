#include<iostream>
using namespace std;


void merge(int arr[], int startIndex, int endIndex) {
  int mid = (startIndex + endIndex) / 2;

  int lenLeftArray = mid - startIndex + 1;
  int lenRightArray = endIndex - mid;

  // Create left and right empty array
  int *leftArray = new int[lenLeftArray];
  int *rightArray = new int[lenRightArray];

  // copy values from original array to left array
  int k = startIndex;

  // k -> 
  for (int i = 0; i < lenLeftArray; i++)
  {
    leftArray[i] = arr[k];
    k++;
  }
  
  //copy values from right array
  k = mid + 1;
  for (int i = 0; i < lenRightArray; i++)
  {
    rightArray[i] = arr[k];
    k++;
  }

  // Two pointer appraoch
  // Actual merge
  int leftIndex = 0;
  int rightIndex = 0;

  int mainArrayIndex = startIndex;

  while(leftIndex < lenLeftArray && rightIndex << lenRightArray) {
    if(leftArray[leftIndex] < rightArray[rightIndex]) {
      arr[mainArrayIndex] = leftArray[leftIndex];
      mainArrayIndex++;
      leftIndex++;
    }else {
      arr[mainArrayIndex] = rightArray[rightIndex];
      mainArrayIndex++;
      rightIndex++;
    }
  }


  // 2 more case
  /*
    CASE 1
    If left array exhaust but right array me element there

  */
  while(lenLeftArray) {

  }

  /*
    CASE 2
    If right array exhaust but left array me element there

  */
}



//MERGE SORT

void mergeSort(int arr[], int startIndex, int endIndex) {
	//base case
	if(startIndex >= endIndex) {
		return;
	}
	if(startIndex == endIndex) {
		return;
	}
	
	//Break
    int mid = (startIndex + endIndex)/2;

	mergeSort(arr, startIndex, mid);
	mergeSort(arr, mid+1, endIndex);

  //Merge two sorted array
  merge(arr, startIndex, endIndex);
}

int main() {
 
  return 0;
}