#include<iostream>
using namespace std;

int findOddOccurringElementIndex(int arr[], int n){
  int startIndex = 0, endIndex = n-1;

  while(startIndex < endIndex) {

    int midIndex = startIndex + (endIndex - startIndex) /2;
    //MidIndex check odd or even
    if(midIndex & 1){ // midIndex & 1 => odd number
      if(midIndex - 1 >= 0 && arr[midIndex-1] == arr[midIndex]){
        //Move to right side
        startIndex = midIndex +1;
      } else {
        endIndex = midIndex - 1;
      }
    } else {
      //Even index
      if(midIndex + 1 < n && arr[midIndex+1] == arr[midIndex]) {
        //Move to right side
        startIndex = midIndex+2;
      } else {
        endIndex = midIndex;
      }
    }
  }
  return startIndex;
}

int main() {
  int arr[] = {5};
  int n = 11;

  int answer = arr[findOddOccurringElementIndex(arr, n)];
  cout << "Odd element is: " << answer << endl;
  return 0;
}

/* TEST CASES
    int arr[] = {2,10,10,2,2,5,5,3,3,8,8};
    int n = 11;
    Odd element is: 2

    int arr[] = {10,10,2,2,5,5,8,3,3,8,8};
    int n = 11;
    Odd element is: 8

    int arr[] = {10,10,2,2,5,5,8,3,3,8,8,10};
    int n = 11;
    Odd element is: 10

    int arr[] = {5};
    int n = 1;
    Odd element is: 5

*/