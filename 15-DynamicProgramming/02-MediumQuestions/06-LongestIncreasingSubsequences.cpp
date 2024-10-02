#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 📝 Class Solution containing methods to find the length of the longest increasing subsequence
class Solution {
public:
    // 🔄 Function to solve using recursion
    // Algorithm:
    // 1️⃣ If the current index is out of bounds, return 0 (base case).
    // 2️⃣ Initialize include and exclude counts to 0.
    // 3️⃣ If the current number can be included (greater than previous), 
    //    recursively call with the current index included.
    // 4️⃣ Exclude the current number and call recursively.
    // 5️⃣ Return the maximum of include and exclude counts.
    int solveUsingRecursion(vector<int>& nums, int prevIndex, int currIndex) {
        if (currIndex >= nums.size()) {
            return 0; // Base case: Out of bounds
        }

        int include = 0, exclude = 0; // Initialize counts

        // Check if current number can be included
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            include = 1 + solveUsingRecursion(nums, currIndex, currIndex + 1); // Include current number
        }
        exclude = solveUsingRecursion(nums, prevIndex, currIndex + 1); // Exclude current number

        return max(include, exclude); // Return max of both counts
    }

    // 🔄 Function to solve using memoization
    // Algorithm:
    // 1️⃣ Similar to recursion but use a DP table to store results.
    // 2️⃣ Check if the result is already computed to avoid recalculations.
    // 3️⃣ Return the maximum of include and exclude counts.
    int solveUsingMem(vector<int>& nums, int prevIndex, int currIndex, vector<vector<int>>& dp) {
        if (currIndex >= nums.size()) {
            return 0; // Base case: Out of bounds
        }

        // Check memoization table for previously computed results
        if (prevIndex != -1 && dp[currIndex][prevIndex + 1] != -1) {
            return dp[currIndex][prevIndex + 1]; // Return cached result
        }

        int include = 0, exclude = 0; // Initialize counts

        // Check if current number can be included
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            include = 1 + solveUsingMem(nums, currIndex, currIndex + 1, dp); // Include current number
        }
        exclude = solveUsingMem(nums, prevIndex, currIndex + 1, dp); // Exclude current number

        dp[currIndex][prevIndex + 1] = max(include, exclude); // Cache the result
        return dp[currIndex][prevIndex + 1]; // Return result
    }

    // 🔄 Function to solve using tabulation (bottom-up approach)
    int solveUsingTab(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // DP table initialization

        // Fill the DP table
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                int include = 0, exclude = 0; // Initialize counts

                // Check if current number can be included
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
                    include = 1 + dp[currIndex + 1][currIndex + 1]; // Include current number
                }
                exclude = dp[currIndex + 1][prevIndex + 1]; // Exclude current number

                dp[currIndex][prevIndex + 1] = max(include, exclude); // Cache result
            }
        }
        return dp[0][0]; // Return final result
    }

    // 🔄 Function to solve using space-optimized tabulation
    int solveUsingTabSO(vector<int>& nums) {
        int n = nums.size();
        vector<int> currRow(n + 1, 0); // Current row
        vector<int> nextRow(n + 1, 0); // Next row

        // Fill the DP rows
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                int include = 0, exclude = 0; // Initialize counts

                // Check if current number can be included
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
                    include = 1 + nextRow[currIndex + 1]; // Include current number
                }
                exclude = nextRow[prevIndex + 1]; // Exclude current number

                currRow[prevIndex + 1] = max(include, exclude); // Cache result
            }
            nextRow = currRow; // Move to next row
        }
        return nextRow[0]; // Return final result
    }

    // 🔄 Function to solve using binary search
    int solveUsingBS(vector<int>& nums) {
        vector<int> ans; // Store the longest increasing subsequence

        for (int i = 0; i < nums.size(); i++) {
            if (ans.empty() || nums[i] > ans.back()) {
                ans.push_back(nums[i]); // Add to subsequence
            } else {
                // Find the position to replace
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i]; // Replace the number
            }
        }

        return ans.size(); // Return length of the longest increasing subsequence
    }

    // 📏 Main function to find length of longest increasing subsequence
    int lengthOfLIS(vector<int>& nums) {
        // Uncomment the method you want to use
        // return solveUsingRecursion(nums, -1, 0); // Recursive solution
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1)); // DP initialization for memoization
        // return solveUsingMem(nums, -1, 0, dp); // Memoization solution
        // return solveUsingTab(nums); // Tabulation solution
        // return solveUsingTabSO(nums); // Space-optimized tabulation solution

        return solveUsingBS(nums); // Binary search solution
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case: Find the length of the longest increasing subsequence
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18}; // Input array
    int length = solution.lengthOfLIS(nums); // Calculate the length of LIS

    // 📜 Output the length of the longest increasing subsequence
    cout << "Length of Longest Increasing Subsequence: " << length << endl; // Display result

    return 0; // Indicate that the program ended successfully
}

/*
⏳ Time Complexity:
- O(n^2) for recursion with memoization and tabulation methods due to nested loops.
- O(n log n) for binary search solution due to binary search in a sorted array.

💾 Space Complexity:
- O(n) for memoization and tabulation methods due to DP tables.
- O(1) for the binary search method as it uses a fixed size array for storing the results.

📊 Example Output:
If the input array is {10, 9, 2, 5, 3, 7, 101, 18}, the output will be:
Length of Longest Increasing Subsequence: 4

Explanation:
1. The longest increasing subsequence in the array is {2, 3, 7, 101}.
2. The length of this subsequence is 4.
*/
