#include<iostream>
#include<vector>
using namespace std;

void subArraysRE_Util(vector<int> &nums, int startIndex, int endIndex) {
  //BASE CASE
  if(endIndex == nums.size()) {
    return;
  }

  // 1 case sol.
  for(int i=startIndex; i<=endIndex; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;

  //RE
  subArraysRE_Util(nums, startIndex, endIndex+1);
}

void subArraysRE(vector<int> &nums) {
  for(int startIndex = 0; startIndex<nums.size(); startIndex++) {
    int endIndex = startIndex;
    subArraysRE_Util(nums, startIndex, endIndex);
  }
}

//In single function itself

void printAllTheSubArrays(vector<int> &nums, int startIndex, int endIndex) {
  //BASE CASE
  if (endIndex == nums.size()) {
    return;
    // Increment the end point and start from 0
  } else if (startIndex > endIndex) {
    printAllTheSubArrays(nums, 0, endIndex+1);
    // Print the sub-array and increment the starting point
  } else {
    for(int i=startIndex; i< endIndex; i++) {
      cout << nums[i] << " ";
    }
    cout << nums[endIndex];
    cout << endl;
    printAllTheSubArrays(nums, startIndex+1, endIndex);
  }

}

int main() {
 
  vector<int> nums{1, 2, 3};

  // subArraysRE(nums);
  printAllTheSubArrays(nums, 0 , 0);
  return 0;
}

/*
  subArraysRE(nums);
  1 
  1 2 
  1 2 3 
  2 
  2 3 
  3

  printAllTheSubArrays(nums, 0 , 0);
  1
  1 2
  2
  1 2 3
  2 3
  3

*/