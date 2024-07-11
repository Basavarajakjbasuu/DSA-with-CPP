#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Brute
int sortAndFindMissing(vector<int> &nums)
{
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++)
  {
    if (i == nums[i])
      continue;
    else
      return i;
  }

  return nums.size();
}

// Optimal
int xorr(vector<int> &nums)
{
  int ans = 0;

  // Xor all the values
  for (int i = 0; i < nums.size(); i++)
  {
    ans ^= nums[i];
  }

  // XOR the all range[0,N] with i
  for (int i = 0; i <= nums.size(); i++)
  {
    ans ^= i;
  }

  return ans;
}

int missingNumber(vector<int> &nums)
{
  // return sortAndFindMissing(nums);
  return xorr(nums);
}
int main()
{

  vector<int> nums = {4, 1, 2, 3, 6, 5, 7, 9, 0};
  int missing = missingNumber(nums);
  cout << "The missing number is: " << missing << endl;

  return 0;
}

// The missing number is: 8