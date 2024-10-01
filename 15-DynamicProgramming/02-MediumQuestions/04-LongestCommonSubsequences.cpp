#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * 🌀 Recursive Solution for Longest Common Subsequence (LCS):
     * 
     * 1️⃣ **Base Case**: If either string has been fully traversed, return 0.
     * 2️⃣ **Recursive Choices**:
     *      - Option 1: If characters at the current indices match, include them and move both indices forward.
     *      - Option 2: If characters don't match, find the max LCS by either skipping one character in string `a` or `b`.
     * 3️⃣ **Goal**: Return the length of the longest common subsequence.
     * 
     * Time Complexity: O(2^n) 🕒 (due to the exponential number of recursive calls).
     * Space Complexity: O(n) 🧠 (due to the recursion stack).
     */
    int solveUsingRecursion(string a, string b, int i, int j) {
        // 🟢 Base case: if we've reached the end of either string
        if (i >= a.length() || j >= b.length()) {
            return 0;
        }

        int ans = 0;
        // 🟢 If characters match, include in LCS
        if (a[i] == b[j]) {
            ans = 1 + solveUsingRecursion(a, b, i + 1, j + 1);
        } else {
            // 🟢 If not, take the max by skipping a character from either string
            ans = 0 + max(solveUsingRecursion(a, b, i, j + 1),
                          solveUsingRecursion(a, b, i + 1, j));
        }

        return ans;
    }

    /**
     * 🌟 Memoization Solution for LCS:
     * 
     * 1️⃣ **Memoization**: Store results of previously computed subproblems in a dp table.
     * 2️⃣ Use a `dp` array where `dp[i][j]` represents the LCS length starting from `i` in string `a` and `j` in string `b`.
     * 
     * Time Complexity: O(n*m) 🕒 (each subproblem is solved once).
     * Space Complexity: O(n*m) 🧠 (due to the dp array and recursion stack).
     */
    int solveUsingmemo(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        // 🟢 Base case: if we've reached the end of either string
        if (i >= a.length() || j >= b.length()) {
            return 0;
        }

        // 🟢 Check if the result is already cached in dp array
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        // 🟢 If characters match, add to the LCS and move forward in both strings
        if (a[i] == b[j]) {
            ans = 1 + solveUsingmemo(a, b, i + 1, j + 1, dp);
        } else {
            // 🟢 If characters don't match, find the max by skipping a character from either string
            ans = 0 + max(solveUsingmemo(a, b, i, j + 1, dp),
                          solveUsingmemo(a, b, i + 1, j, dp));
        }

        // 🟢 Memoize the result for future calls
        dp[i][j] = ans;
        return dp[i][j];
    }

    /**
     * 🌟 Tabulation Solution (Bottom-Up Dynamic Programming):
     * 
     * 1️⃣ **Goal**: Build a `dp` table such that `dp[i][j]` contains the LCS length from `i` in string `a` and `j` in string `b`.
     * 2️⃣ **Transition**:
     *      - If the characters match, add to the LCS.
     *      - If not, take the maximum of skipping one character from either string.
     * 3️⃣ **Start**: Fill the dp table from the end of the strings to the start.
     * 
     * Time Complexity: O(n*m) 🕒
     * Space Complexity: O(n*m) 🧠
     */
    int solveUsingTab(string& a, string& b) {
        // 🟢 Create a dp table initialized with 0
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

        // 🟢 Fill the table from the bottom-right to the top-left
        for (int i_index = a.length() - 1; i_index >= 0; i_index--) {
            for (int j_index = b.length() - 1; j_index >= 0; j_index--) {
                int ans = 0;
                // 🟢 If characters match, include in LCS
                if (a[i_index] == b[j_index]) {
                    ans = 1 + dp[i_index + 1][j_index + 1];
                } else {
                    // 🟢 Otherwise, take the max LCS by skipping a character from either string
                    ans = 0 + max(dp[i_index][j_index+1], dp[i_index + 1][j_index]);
                }
                dp[i_index][j_index] = ans;
            }
        }
    
        // 🟢 Return the final result from dp[0][0]
        return dp[0][0];
    }

    /**
     * 🌟 Space-Optimized Tabulation Solution:
     * 
     * 1️⃣ **Optimization**: Instead of using a full 2D dp array, we can optimize space by using only two rows (`curr` and `next`).
     * 2️⃣ This reduces the space complexity from O(n*m) to O(min(n, m)).
     * 
     * Time Complexity: O(n*m) 🕒
     * Space Complexity: O(min(n, m)) 🧠
     */
    int solveUsingTabSO(string& a, string& b) {
        // 🟢 Create two 1D arrays to store the current and next row results
        vector<int> curr(a.length() + 1, 0);
        vector<int> next(a.length() + 1, 0);

        // 🟢 Fill the dp array from the bottom-right to the top-left
        for (int j_index = b.length() - 1; j_index >= 0; j_index--) {
            for (int i_index = a.length() - 1; i_index >= 0; i_index--) {
                int ans = 0;
                // 🟢 If characters match, include in LCS
                if (a[i_index] == b[j_index]) {
                    ans = 1 + next[i_index + 1];
                } else {
                    // 🟢 Otherwise, take the max LCS by skipping a character from either string
                    ans = 0 + max(next[i_index], curr[i_index + 1]);
                }
                curr[i_index] = ans;
            }
            // 🟢 Move current row to next for the next iteration
            next = curr;
        }
    
        // 🟢 Return the final result from next[0]
        return next[0];
    }

    /**
     * 🌟 Driver Function for Longest Common Subsequence:
     * 
     * Calls the space-optimized tabulation solution to compute the result.
     * 
     * Time Complexity: O(n*m) 🕒
     * Space Complexity: O(min(n, m)) 🧠
     */
    int longestCommonSubsequence(string text1, string text2) {
        return solveUsingTabSO(text1, text2);
    }
};

// 🌟 Driver Code for Local Execution
int main() {
    Solution solution;
    string text1 = "abcde";
    string text2 = "ace";

    // 🛠 Calling the LCS function
    int lcsLength = solution.longestCommonSubsequence(text1, text2);

    // 🎉 Print the result
    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;

    return 0;
}

/**
 * Example Output:
 * Length of Longest Common Subsequence: 3
 * 
 * Explanation of Output:
 * The longest common subsequence between "abcde" and "ace" is "ace", which has a length of 3.
 */

// Time Complexity 🕒: O(n*m) as we are processing both strings once.
// Space Complexity 🧠: O(min(n, m)) due to the space optimization.
