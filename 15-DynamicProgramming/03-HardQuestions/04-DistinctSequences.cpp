#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    // ✨ Algorithm explanation:
    // We are solving the "Distinct Subsequences" problem using three approaches: Recursion, Memoization, and Tabulation.
    // The task is to count how many distinct subsequences of string `s` match string `t`.

    // 🔄 Recursion Approach:
    // 1. If `t` is empty (j == t.size()), we've found a valid subsequence and return 1.
    // 2. If `s` is exhausted (i == s.size()), no more subsequences are possible, return 0.
    // 3. If characters match (s[i] == t[j]), we count subsequences where we include s[i] and exclude it.
    // 4. If they don't match, we simply skip s[i].

    // Time Complexity: O(2^n) (exponential) 🕒
    // Space Complexity: O(n + m) due to recursion stack 🛠️

    int solveUsingRecursion(string& s, string& t, int i, int j) {
        if (j == t.size())
            return 1; // Found valid subsequence 🎯
        if (i == s.size())
            return 0; // No more subsequences possible 🛑

        int ans = 0;
        if (s[i] == t[j]) {
            ans += solveUsingRecursion(s, t, i + 1, j + 1); // Move both pointers 👣
        }
        ans += solveUsingRecursion(s, t, i + 1, j); // Move only the pointer in `s` 🔄

        return ans;
    }

    // 🏗️ Memoization Approach:
    // This builds on the recursive approach but adds a `dp` table to store results of subproblems.
    
    // Time Complexity: O(n*m) 🕒
    // Space Complexity: O(n*m) 🛠️
    
    int solveUsingMem(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;

        if (dp[i][j] != -1) {
            return dp[i][j]; // Return cached result from dp 📦
        }

        int ans = 0;
        if (s[i] == t[j]) {
            ans += solveUsingMem(s, t, i + 1, j + 1, dp);
        }
        ans += solveUsingMem(s, t, i + 1, j, dp);

        return dp[i][j] = ans; // Store the result in dp before returning 💾
    }

    // 🏆 Tabulation Approach:
    // Use a bottom-up approach with a 2D dp array to solve the problem iteratively.
    
    // Time Complexity: O(n*m) 🕒
    // Space Complexity: O(n*m) 🛠️
    
    int solveUsingTab(string& s, string& t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        // Base case: if `t` is empty, there's 1 way to form an empty subsequence
        for (int i = 0; i <= s.size(); i++) {
            dp[i][t.size()] = 1; // If `t` is exhausted, 1 valid subsequence remains ✅
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = t.size() - 1; j >= 0; j--) {
                long long ans = 0;
                if (s[i] == t[j]) {
                    ans += dp[i + 1][j + 1]; // Move both indices if characters match 👣
                }
                ans += dp[i + 1][j]; // Move only `i` in `s` 🔄
                dp[i][j] = ans;
            }
        }

        return dp[0][0]; // The result is stored in dp[0][0] 🏆
    }

    // 🌟 Main function to initiate the approach
    int numDistinct(string s, string t) {
        // Example output explanation:
        // s = "rabbbit", t = "rabbit"
        // The number of distinct subsequences of "rabbbit" that equal "rabbit" is 3.
        
        // vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1)); // Memoization table
        // return solveUsingMem(s, t, 0, 0, dp); // Use Memoization

        return solveUsingTab(s, t); // Use Tabulation for optimal solution 🏆
    }
};

// 🏁 Example usage and output
int main() {
    Solution solution;
    string s = "rabbbit";
    string t = "rabbit";
    int result = solution.numDistinct(s, t);
    cout << "Number of distinct subsequences: " << result << endl;  // Output: 3
    return 0;
}

/*
📝 Output Explanation:
The string "rabbbit" contains 3 distinct subsequences that equal "rabbit":
1. r**a**b**b**b**i**t
2. r**a**b**b**b**i**t
3. r**a**b**b**i**t
The function calculates all possible subsequences and returns 3 as the answer. 🏆

Time Complexity for the Tabulation Approach: O(n*m) 🕒
Space Complexity: O(n*m) 🛠️
*/
