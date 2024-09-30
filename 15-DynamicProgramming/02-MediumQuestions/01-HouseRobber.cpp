#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 🌟 Recursive Solution to Maximize Robbery:
     * 
     * 1️⃣ **Base Case**: If the current index exceeds the size of the array, return 0.
     * 2️⃣ **Recursive Choices**:
     *      - Option 1: Rob the current house and move to index + 2 (because adjacent houses cannot be robbed).
     *      - Option 2: Skip the current house and move to index + 1.
     * 3️⃣ **Goal**: Return the maximum amount that can be robbed by making the best choice at each house.
     * 
     * Time Complexity: O(2^n) 🕒 (due to repeated subproblems in recursion).
     * Space Complexity: O(n) 🧠 (due to the recursion stack).
     */
    int solve(vector<int>& nums, int size, int index) {
        if(index >= size) {
            return 0;
        }

        int option1 = nums[index] + solve(nums, size, index + 2);
        int option2 = solve(nums, size, index + 1);

        return max(option1, option2);
    }

    /**
     * 🌟 Memoization Solution to Maximize Robbery:
     * 
     * 1️⃣ **Memoization**: Store previously computed results to avoid redundant calculations.
     * 2️⃣ Use a `dp` array to store the maximum amount robbed starting from each index.
     * 
     * Time Complexity: O(n) 🕒 (each subproblem is solved once).
     * Space Complexity: O(n) 🧠 (due to the dp array and recursion stack).
     */
    int solveUsingMemo(vector<int>& nums, int size, int index, vector<int>& dp) {
        if (index >= size) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int option1 = nums[index] + solveUsingMemo(nums, size, index + 2, dp);
        int option2 = solveUsingMemo(nums, size, index + 1, dp);

        dp[index] = max(option1, option2);

        return dp[index];
    }

    /**
     * 🌟 Tabulation Solution (Bottom-Up Dynamic Programming):
     * 
     * 1️⃣ **Goal**: Build a `dp` array such that `dp[i]` contains the maximum amount that can be robbed from house `i` to the end.
     * 2️⃣ **Transition**:
     *      - Include the current house `i` and skip the next one (`i+2`).
     *      - Skip the current house and take the next one (`i+1`).
     * 3️⃣ Start filling the dp array from the last house back to the first.
     * 
     * Time Complexity: O(n) 🕒
     * Space Complexity: O(n) 🧠
     */
    int solveUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // DP array to store maximum amounts
        vector<int> dp(n, 0);

        dp[n-1] = nums[n-1]; // Base case, last house is the only option
        for(int index = n-2; index >= 0; index--) {
            // Option 1: Rob the current house and move to index+2
            int include = nums[index] + (index+2 < n ? dp[index+2] : 0);

            // Option 2: Skip the current house and move to index+1
            int exclude = dp[index+1];

            // Store the maximum of the two options in dp array
            dp[index] = max(include, exclude);
        }

        return dp[0]; // The maximum amount robbed starting from the first house
    }

    /**
     * 🌟 Space Optimized Tabulation Solution:
     * Uses only two variables (`prev` and `next`) instead of a full dp array, thus reducing space complexity to O(1).
     * 
     * Time Complexity: O(n) 🕒
     * Space Complexity: O(1) 🧠
     */
    int solveUsingTabulationSO(vector<int>& nums) {
      int n = nums.size();
      if (n == 0) return 0;
      if (n == 1) return nums[0];

      int prev = nums[n-1];  // Max if we rob the last house
      int next = 0;  // No house beyond the last one, so next is 0
      int curr = 0;  // Current house calculation

      for(int index = n-2; index >= 0; index--) {
          int include = nums[index] + next;  // Rob current house, add `next`
          int exclude = prev;  // Skip current house

          curr = max(include, exclude);
          next = prev;  // Update next to be previous
          prev = curr;  // Move current to previous for the next iteration
      }

      return prev;  // Final answer is in prev
    }


    /**
     * 🌟 Driver Function:
     * 
     * Calls the tabulation solution and returns the result.
     * 
     * Time Complexity: O(n) 🕒
     * Space Complexity: O(n) 🧠
     */
    int rob(vector<int>& nums) {
        return solveUsingTabulationSO(nums);
    }
};

// 🌟 Driver Code for Local Execution
int main() {
    Solution solution;
    vector<int> houses = {2, 7, 9, 3, 1};  // Example input array representing house values

    // 🛠 Calling the rob function
    int maxRobbedAmount = solution.rob(houses);

    // 🎉 Print the result
    cout << "Maximum amount that can be robbed: " << maxRobbedAmount << endl;

    return 0;
}

/**
 * Example Output:
 * Maximum amount that can be robbed: 12
 * 
 * Explanation of Output:
 * By robbing houses 1 and 3 (values 7 and 9), the maximum amount is 12.
 */

// Time Complexity 🕒: O(n) as each house is processed once.
// Space Complexity 🧠: O(n) due to the dp array.
