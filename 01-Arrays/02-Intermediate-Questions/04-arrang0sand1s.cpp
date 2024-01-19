#include<iostream>
using namespace std;
 
/*
  Arrange all zero at first place and 1's at last
*/ 

void sortZerosAndOnes(int arr[], int n) {

  int zeros = 0;
  int ones = 0;
  for (int i = 0; i < n; i++)
  {
    if(arr[i]== 0) {
      zeros++;
    }
    if(arr[i] == 1) {
      ones++;
    }
  }
  
  // place all zeros first
  int i;
  for (int i = 0; i < zeros; i++) {
    arr[i] = 0;
  }

  for (int i = zeros; i < n; i++)
  {
    arr[i] = 1;
  }
  
}


void twoIndexApproach(int arr[], int n) {

  int leftIndex = 0, rightIndex = n-1;

  while(leftIndex < rightIndex) {

    if(arr[leftIndex] == 0) {
      leftIndex++;
    }

    if(arr[rightIndex] == 1) {
      rightIndex--;
    }

    if(leftIndex < rightIndex) {
      arr[leftIndex] = 0;
      arr[rightIndex] = 1;
      leftIndex++;
      rightIndex--;
    }

  }

}


void twoPointerApproach(int arr[], int n) {

  int leftIndex = 0, rightIndex = n -1;

  while (leftIndex < rightIndex)
  {
    if(arr[leftIndex] == 1) {
      if(arr[rightIndex] != 1 ) {
        swap( arr[leftIndex], arr[rightIndex]);
        leftIndex++;
      }
        rightIndex--;
    } else
        leftIndex++;
  }
  
}

void outputArray(int arr[], int n) {
  cout << "Displaying array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {

  int arr[10] = {0, 1, 0, 1, 0, 0, 0, 1, 0, 1};

  int n = 10;
  // sortZerosAndOnes(arr, n);
  // twoIndexApproach(arr, n);
  twoPointerApproach(arr, n);
  outputArray(arr, n);
  return 0;
}

/*
  Displaying array: 0 0 0 0 0 0 1 1 1 1
*/