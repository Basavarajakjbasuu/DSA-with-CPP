#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 🌀 Recursive solution to find the minimum delete sum
    // Algorithm:
    // 1️⃣ If either string is empty, the cost is the sum of the ASCII values of the remaining characters in the other string.
    // 2️⃣ If characters match, move to the next characters in both strings.
    // 3️⃣ If characters don't match, consider deleting either character and find the minimum cost.
    int solveUsingRecursion(string& s1, string& s2, int i, int j) {
        int cost = 0;
        // BASE CASE: if either string is exhausted
        if (i == s1.size() || j == s2.size()) {
            for (int x = i; x < s1.size(); x++)
                cost += s1[x]; // Sum remaining characters in s1
            for (int y = j; y < s2.size(); y++)
                cost += s2[y]; // Sum remaining characters in s2
        } else if (s1[i] == s2[j]) {
            cost = solveUsingRecursion(s1, s2, i + 1, j + 1); // Move to next characters
        } else {
            // Cost of deleting either character
            int cost1 = s1[i] + solveUsingRecursion(s1, s2, i + 1, j); // Delete s1[i]
            int cost2 = s2[j] + solveUsingRecursion(s1, s2, i, j + 1); // Delete s2[j]
            cost = min(cost1, cost2); // Take the minimum cost
        }

        return cost; // Return the computed cost
    }

    // 🧠 Memoized solution (top-down dynamic programming)
    // Algorithm:
    // 1️⃣ Utilize a DP table to store already computed results.
    // 2️⃣ The logic is similar to the recursive approach but avoids redundant calculations.
    int solveUsingMem(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        int cost = 0;
        // Return memoized result if available
        if (dp[i][j] != -1)
            return dp[i][j];

        // BASE CASE: if either string is exhausted
        if (i == s1.size() || j == s2.size()) {
            for (int x = i; x < s1.size(); x++)
                cost += s1[x]; // Sum remaining characters in s1
            for (int y = j; y < s2.size(); y++)
                cost += s2[y]; // Sum remaining characters in s2
        } else if (s1[i] == s2[j]) {
            cost = solveUsingMem(s1, s2, i + 1, j + 1, dp); // Move to next characters
        } else {
            // Cost of deleting either character
            int cost1 = s1[i] + solveUsingMem(s1, s2, i + 1, j, dp); // Delete s1[i]
            int cost2 = s2[j] + solveUsingMem(s1, s2, i, j + 1, dp); // Delete s2[j]
            cost = min(cost1, cost2); // Take the minimum cost
        }

        return dp[i][j] = cost; // Store and return the computed cost
    }

    // 🔄 Tabulation (bottom-up dynamic programming) approach
    // Algorithm:
    // 1️⃣ Initialize a DP table where `dp[i][j]` stores the minimum delete sum for substrings s1[0...i-1] and s2[0...j-1].
    // 2️⃣ Fill the DP table based on the previously calculated values.
    int solveUsingTab(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // BASE CASE: Fill last row and last column for empty strings
        for (int i = m - 1; i >= 0; i--) {
            dp[i][n] = s1[i] + dp[i + 1][n]; // Remaining characters in s1
        }
        for (int j = n - 1; j >= 0; j--) {
            dp[m][j] = s2[j] + dp[m][j + 1]; // Remaining characters in s2
        }

        // Fill the DP table
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1]; // Characters match
                } else {
                    // Take minimum of deleting either character
                    int cost1 = s1[i] + dp[i + 1][j]; // Delete s1[i]
                    int cost2 = s2[j] + dp[i][j + 1]; // Delete s2[j]
                    dp[i][j] = min(cost1, cost2); // Store minimum cost
                }
            }
        }
        return dp[0][0]; // Return the minimum delete sum for the entire strings
    }

    // 🔥 Main function to find the minimum delete sum
    int minimumDeleteSum(string s1, string s2) {
        // Uncomment one of the solutions below to test different approaches

        // Recursive approach (inefficient for large inputs)
        // return solveUsingRecursion(s1, s2, 0, 0);

        // Memoized approach
        // vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        // return solveUsingMem(s1, s2, 0, 0, dp);

        // Tabulation approach (most efficient for large inputs)
        return solveUsingTab(s1, s2);
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case
    string s1 = "sea"; // First string
    string s2 = "eat"; // Second string
    
    // Calculate the minimum delete sum
    int result = solution.minimumDeleteSum(s1, s2);
    
    // 📜 Output the result
    cout << "Minimum delete sum: " << result << endl; // Display result

    return 0;
}

/*
⏳ Time Complexity:
- Recursive approach: O(2^(m+n)), where `m` and `n` are the lengths of the two strings. Exponential due to multiple recursive calls.
- Memoized approach: O(m*n) where `m` and `n` are the lengths of the two strings.
- Tabulation approach: O(m*n) where `m` and `n` are the lengths of the two strings.

💾 Space Complexity:
- Recursive approach: O(m+n) due to recursion stack.
- Memoized approach: O(m*n) for the DP table.
- Tabulation approach: O(m*n) for the DP table.

📊 Example Output:
If s1 = "sea" and s2 = "eat", the output will be:
Minimum delete sum: 231

Explanation:
- We can delete 's' from "sea" and 't' from "eat".
- The total cost (ASCII values) = 115 (ASCII of 's') + 116 (ASCII of 't') = 231.
*/
