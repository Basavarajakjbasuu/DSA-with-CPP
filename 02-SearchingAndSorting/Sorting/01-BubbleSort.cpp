#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> &arr) {
  for(int i=0; i<arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout <<  endl;
}

//Increasing order
void bubbleSortIncreasing(vector<int> &arr) {
  int n = arr.size() - 1;

  for(int i=0; i<n; i++) {

    for(int j=0; j<n-i; j++) {

      if(arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
      }
    }
  }
}

//Decreasing order
void bubbleSortDecreasing(vector<int> &arr) {
  int n = arr.size() - 1;

  for(int i=0; i<n; i++) {

    for(int j=0; j<n-i; j++) {

      if(arr[j] < arr[j+1]) {
        swap(arr[j], arr[j+1]);
      }
    }
  }
}

int main() {
  vector<int> nums = {12, 34, -24, 68, -12, 6, 0, 6};
  vector<int> nums1 = {12, 34, -24, 68, -12, 6, 0, 6};

  bubbleSortIncreasing(nums);
  printArray(nums);
  bubbleSortDecreasing(nums1);
  printArray(nums1);
  return 0;
}

/* TEST CASES
    vector<int> nums = {12, 34, -24, 68, -12, 6, 0, 6};
    vector<int> nums1 = {12, 34, -24, 68, -12, 6, 0, 6};
    -24 -12 0 6 6 12 34 68 
    68 34 12 6 6 0 -12 -24

    vector<int> nums = {12, 34, 24, 68, 12, 6, 0, 6};
    vector<int> nums1 = {12, 34, 24, 68, 12, 6, 0, 6};
    0 6 6 12 12 24 34 68 
    68 34 24 12 12 6 6 0
*/
