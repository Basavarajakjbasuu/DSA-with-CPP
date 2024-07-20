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
void selectionSortIncreasingOrder(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i <n-1; i++){
    int minIndex = i;
    for(int j=i+1; j <n; j++) {
      if(arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    //Swap
    swap(arr[i], arr[minIndex]);
  }
  
}

//Decreasing order
void selectionSortDecreasingOrder(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i <n-1; i++){
    int minIndex = i;
    for(int j=i+1; j <n; j++) {
      if(arr[j] > arr[minIndex]) {
        minIndex = j;
      }
    }
    //Swap
    swap(arr[i], arr[minIndex]);
  }
  
}

int main() {
  vector<int> nums = {12, 34, -24, 68, -12, 6, 0, 6};
  vector<int> nums1 = {12, 34, -24, 68, -12, 6, 0, 6};
  vector<int> nums2 = {22,44,11,33,55,99};

  selectionSortIncreasingOrder(nums);
  printArray(nums);
  selectionSortDecreasingOrder(nums1);
  printArray(nums1);
  selectionSortDecreasingOrder(nums2);
  printArray(nums2);
  return 0;
}

/* TEST CASES
      vector<int> nums = {12, 34, -24, 68, -12, 6, 0, 6};
      vector<int> nums1 = {12, 34, -24, 68, -12, 6, 0, 6};
      vector<int> nums2 = {22,44,11,33,55,99};

      -24 -12 0 6 6 12 34 68 
      68 34 12 6 6 0 -12 -24
      99 55 44 33 22 11

*/

