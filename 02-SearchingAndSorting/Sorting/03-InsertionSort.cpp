#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> &arr) {
  for(int i=0; i<arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout <<  endl;
}

void insertionSort(vector<int> &arr) {
  int n = arr.size();

  for(int i=0; i<n; i++) {
    int key = arr[i];
    int j = i-1;

    while(j>=0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key; // Insertion
  }
}

int main() {
  vector<int> nums = {5,4,3,2,1};
  vector<int> nums1 = {44,34,13,12,8};

  insertionSort(nums);
  printArray(nums);
  insertionSort(nums1);
  printArray(nums1);
  return 0;
}

/* TEST CASES
   vector<int> nums = {5,4,3,2,1};
   1 2 3 4 5 

   vector<int> nums1 = {44,34,13,12,8};
   8 12 13 34 44
*/