#include <iostream>
#include <vector>
using namespace std;

// 📝 Class to solve the Partition Equal Subset Sum problem
class Solution {
public:
    // 🌀 Recursive solution to check if it's possible to partition into subsets
    // Algorithm:
    // 1️⃣ Base case: If the `currentSum` exceeds the target, or we reach the end of the array without a match, return false.
    // 2️⃣ If `currentSum` equals `target`, return true (we found a valid partition).
    // 3️⃣ Recursive call: Explore both including the current element and excluding it from the subset.
    bool solveUsingRecursion(vector<int>& nums, int index, int target, int currentSum) {
        if (index >= nums.size()) return false; // If out of bounds
        if (currentSum > target) return false;  // If sum exceeds target
        if (currentSum == target) return true;  // If subset sum matches the target

        // Recursively check both options: include and exclude the current element
        bool include = solveUsingRecursion(nums, index + 1, target, currentSum + nums[index]);
        bool exclude = solveUsingRecursion(nums, index + 1, target, currentSum);

        return include || exclude; // Return true if any branch leads to a valid partition
    }

    // 🧠 Memoized solution (top-down approach)
    // Algorithm:
    // 1️⃣ Same as the recursive approach, but we use memoization to store intermediate results
    //    to avoid redundant calculations.
    // 2️⃣ Store results in a 2D array `dp[index][currentSum]`.
    bool solveUsingMem(vector<int>& nums, int index, int target, int currentSum, vector<vector<int>>& dp) {
        if (index >= nums.size()) return false;
        if (currentSum > target) return false;
        if (currentSum == target) return true;

        // If already computed, return the stored result
        if (dp[index][currentSum] != -1) return dp[index][currentSum];

        // Calculate results and store them in dp
        bool include = solveUsingMem(nums, index + 1, target, currentSum + nums[index], dp);
        bool exclude = solveUsingMem(nums, index + 1, target, currentSum, dp);

        return dp[index][currentSum] = include || exclude;
    }

    // 🔄 Tabulation (bottom-up DP) approach
    // Algorithm:
    // 1️⃣ Create a DP table where `dp[i][currentSum]` stores whether it's possible to form `currentSum` using the first `i` elements.
    // 2️⃣ Transition: Either include or exclude the current element in the sum.
    bool solveUsingTab(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: A sum of zero is always possible
        for (int row = 0; row <= n; row++) {
            dp[row][target] = true;
        }

        // Fill the DP table
        for (int index = n - 1; index >= 0; index--) {
            for (int currentSum = target; currentSum >= 0; currentSum--) {
                bool include = false;
                if (currentSum + nums[index] <= target)
                    include = dp[index + 1][currentSum + nums[index]];
                bool exclude = dp[index + 1][currentSum];
                dp[index][currentSum] = include || exclude;
            }
        }
        return dp[0][0]; // The answer is in the top-left cell (starting from 0 sum and first element)
    }

    // ♻️ Space-optimized tabulation
    // Algorithm:
    // 1️⃣ Use two 1D arrays (`curr` and `next`) to store results, reducing space complexity to O(target).
    bool solveUsingTabSO(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> curr(target + 1, 0); // Current row of DP
        vector<int> next(target + 1, 0); // Next row of DP

        // Base case: A sum of zero is always possible
        curr[target] = true;
        next[target] = true;

        // Fill the DP arrays
        for (int index = n - 1; index >= 0; index--) {
            for (int currentSum = target; currentSum >= 0; currentSum--) {
                bool include = false;
                if (currentSum + nums[index] <= target)
                    include = next[currentSum + nums[index]];
                bool exclude = next[currentSum];
                curr[currentSum] = (include || exclude);
            }
            next = curr; // Move to the next row
        }
        return next[0];
    }

    // 🔥 Main function to determine if array can be partitioned into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (auto num : nums) totalSum += num;

        // If the total sum is odd, we cannot split it into two equal subsets
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2; // We need to find a subset that sums to `target`

        // Uncomment to test other approaches
        // return solveUsingRecursion(nums, 0, target, 0);

        // Memoization approach
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        // return solveUsingMem(nums, 0, target, 0, dp);

        // Tabulation approach
        // return solveUsingTab(nums, target);

        // Space-optimized tabulation
        return solveUsingTabSO(nums, target);
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case
    vector<int> nums = {1, 5, 11, 5}; // Input array
    bool canPartition = solution.canPartition(nums); // Calculate the result

    // 📜 Output the result
    cout << "Can partition: " << (canPartition ? "Yes" : "No") << endl; // Display result

    return 0;
}

/*
⏳ Time Complexity:
- Recursive approach: O(2^n), where n is the number of elements. Exponential time due to the two recursive calls for each element.
- Memoized approach: O(n * target), where n is the number of elements and target is the sum we're aiming for.
- Tabulation approach: O(n * target), same as the memoized approach.
- Space-optimized tabulation: O(n * target) time, but O(target) space.

💾 Space Complexity:
- Recursive approach: O(n) for the recursive call stack.
- Memoized approach: O(n * target) for the memoization table.
- Tabulation approach: O(n * target) for the DP table.
- Space-optimized tabulation: O(target) for the space-optimized DP arrays.

📊 Example Output:
If the input array is {1, 5, 11, 5}, the output will be:
Can partition: Yes

Explanation:
1. The total sum of the array is 22, which is even.
2. We can partition it into two subsets with equal sum: {1, 5, 5} and {11}, both summing to 11.
*/
