#include <iostream>
#include <vector>
using namespace std;

// 📝 Class to solve the Dice Roll Simulation problem
class Solution {
public:
    // Constant MOD for large numbers to avoid overflow
    const long long MOD = 1000000007;

    // 🌀 Recursive solution to calculate the number of ways to achieve the target sum
    // Algorithm:
    // 1️⃣ Base case: If `target` is 0 and `n` (number of dice left) is 0, return 1 (valid combination).
    // 2️⃣ If `target` is less than 0 or no dice left (`n == 0`), return 0 (invalid combination).
    // 3️⃣ For each dice face (from 1 to `k`), subtract the face value from the target and recursively calculate the answer for the remaining dice.
    int solveUsingRecursion(int n, int k, int target) {
        // Base case: Valid combination
        if (target == 0 && n == 0) return 1;
        // Invalid cases
        if (target < 0 || n == 0) return 0;

        int ans = 0;
        // Try all dice faces (from 1 to `k`)
        for (int i = 1; i <= k; i++) {
            int recAns = (solveUsingRecursion(n - 1, k, target - i)) % MOD;
            ans = (ans + recAns) % MOD; // Combine the results, modded by MOD
        }

        return ans;
    }

    // 🧠 Memoized solution (top-down dynamic programming)
    // Algorithm:
    // 1️⃣ Same as the recursive approach, but we store intermediate results in a DP table to avoid recalculating the same subproblems.
    int solveUsingMem(int n, int k, int target, vector<vector<int>>& dp) {
        // Base case: Valid combination
        if (target == 0 && n == 0) return 1;
        // Invalid cases
        if (target < 0 || n == 0) return 0;

        // Return memoized result if available
        if (dp[n][target] != -1) return dp[n][target];

        int ans = 0;
        // Try all dice faces (from 1 to `k`)
        for (int i = 1; i <= k; i++) {
            if (target - i >= 0) {
                int recAns = (solveUsingMem(n - 1, k, target - i, dp)) % MOD;
                ans = (ans % MOD + recAns % MOD) % MOD;
            }
        }

        return dp[n][target] = ans; // Store the result in DP table
    }

    // 🔄 Tabulation (bottom-up dynamic programming) approach
    // Algorithm:
    // 1️⃣ Create a DP table where `dp[dice][currSum]` stores the number of ways to form `currSum` using `dice` number of dice.
    // 2️⃣ Transition: For each dice, we add a dice face to the sum and calculate possible combinations.
    int solveUsingTab(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: 1 way to achieve a sum of 0 with 0 dice
        dp[n][target] = 1;

        // Fill the DP table
        for (int dice = n - 1; dice >= 0; dice--) {
            for (int currSum = target; currSum >= 0; currSum--) {
                int ans = 0;
                // Try all dice faces (from 1 to `k`)
                for (int face = 1; face <= k; face++) {
                    if (currSum + face <= target) {
                        int recAns = (dp[dice + 1][currSum + face]) % MOD;
                        ans = (ans + recAns) % MOD;
                    }
                }
                dp[dice][currSum] = ans;
            }
        }

        return dp[0][0]; // Result is stored in dp[0][0]
    }

    // ♻️ Space-optimized tabulation
    // Algorithm:
    // 1️⃣ Instead of using a 2D DP table, we use two 1D arrays (`curr` and `next`) to reduce space complexity to O(target).
    int solveUsingTabSO(int n, int k, int target) {
        vector<int> curr(target + 1, 0); // Current row of DP
        vector<int> next(target + 1, 0); // Next row of DP

        // Base case: 1 way to achieve the target sum with no dice left
        next[target] = 1;

        // Fill the DP arrays
        for (int dice = n - 1; dice >= 0; dice--) {
            for (int currSum = target; currSum >= 0; currSum--) {
                int ans = 0;
                // Try all dice faces (from 1 to `k`)
                for (int face = 1; face <= k; face++) {
                    if (currSum + face <= target) {
                        int recAns = (next[currSum + face]) % MOD;
                        ans = (ans + recAns) % MOD;
                    }
                }
                curr[currSum] = ans;
            }
            next = curr; // Move to the next row
        }

        return next[0]; // Result is in `next[0]`
    }

    // 🔥 Main function to calculate the number of ways to achieve the target sum using `n` dice with `k` faces
    int numRollsToTarget(int n, int k, int target) {
        // Uncomment one of the solutions below to test different approaches

        // Recursive approach (inefficient for large inputs)
        // return solveUsingRecursion(n, k, target);

        // Memoized approach
        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // return solveUsingMem(n, k, target, dp);

        // Tabulation approach
        // return solveUsingTab(n, k, target);

        // Space-optimized tabulation approach
        return solveUsingTabSO(n, k, target);
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case
    int n = 2, k = 6, target = 7; // Two dice, each with 6 faces, target sum is 7
    int ways = solution.numRollsToTarget(n, k, target); // Calculate the result

    // 📜 Output the result
    cout << "Number of ways to achieve target: " << ways << endl; // Display result

    return 0;
}

/*
⏳ Time Complexity:
- Recursive approach: O(k^n), where n is the number of dice and k is the number of faces. Exponential time due to recursive calls.
- Memoized approach: O(n * target * k), where n is the number of dice, target is the target sum, and k is the number of faces.
- Tabulation approach: O(n * target * k), same as memoized approach.
- Space-optimized tabulation: O(n * target * k) time, but O(target) space.

💾 Space Complexity:
- Recursive approach: O(n) for the recursive call stack.
- Memoized approach: O(n * target) for the DP table.
- Tabulation approach: O(n * target) for the DP table.
- Space-optimized tabulation: O(target) for the space-optimized DP arrays.

📊 Example Output:
If n = 2, k = 6, target = 7, the output will be:
Number of ways to achieve target: 6

Explanation:
1. We can achieve a sum of 7 using the following combinations:
   - (1, 6), (2, 5), (3, 4), (4, 3), (5, 2), (6, 1).
*/
