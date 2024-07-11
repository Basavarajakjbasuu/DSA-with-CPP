#include<iostream>
#include<vector>

using namespace std;

//Two pointer approach
void moveAllNegNumToLeft(vector<int> &nums) {
   int low = 0, high = nums.size() -1;

  while(low < high) {

    if(nums[low] < 0) {
      low++;
    } else if (nums[high] >= 0) {
      high--;
    } else {
      swap(nums[low], nums[high]);
    }
  }
}

int main() {
  vector<int> nums = {1, 2, -3, 4, -5, 6};
  
  moveAllNegNumToLeft(nums);

  cout << "After moving: ";
  for(int i=0; i<nums.size(); i++) {
    cout << nums[i] << " ";
  }
  return 0;
}

// After moving: -5 -3 2 4 1 6