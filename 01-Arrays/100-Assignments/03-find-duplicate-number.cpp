#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// sort(nums.begin(), nums.end());

// for(int i=0; i<nums.size()-1; i++) {

//     if(nums[i] == nums[i+1])
//         return nums[i];
// }

// return -1;

int findDuplicate(vector<int> &nums)
{
  int ans = -1;

  for (int i = 0; i < nums.size(); i++)
  {
    int index = abs(nums[i]);

    // Already visited
    if (nums[index] < 0)
    {
      ans = index;
      break;
    }

    // Marking visited
    nums[index] *= -1;
  }

  return ans;
}

int main()
{
  vector<int> nums = {1, 3, 4, 2, 2};

  int duplicate = findDuplicate(nums);

  cout << "The duplicate number is: " << duplicate << endl;

  return 0;
}

// The duplicate number is: 2