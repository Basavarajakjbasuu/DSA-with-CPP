#include <iostream>
#include <vector>
using namespace std;

// 📝 Class to solve the "Distinct Subsequences" problem
class Solution {
public:
    // 🌀 Recursive solution to count distinct subsequences
    // Algorithm:
    // 1️⃣ Base case: If `j` equals the size of `t`, we found a valid subsequence.
    // 2️⃣ If `i` equals the size of `s`, no more subsequences can be formed.
    // 3️⃣ If characters match (s[i] == t[j]), we increment both indices.
    // 4️⃣ Otherwise, increment only `i` to explore excluding current character from `s`.

    // 🔄 Time Complexity: O(2^n) 🕒 (Exponential)
    // 💾 Space Complexity: O(n + m) due to recursion stack

    int solveUsingRecursion(string& s, string& t, int i, int j) {
        if (j == t.size()) return 1; // Valid subsequence found 🎯
        if (i == s.size()) return 0; // No subsequences left 🛑

        int count = 0;
        if (s[i] == t[j]) {
            count += solveUsingRecursion(s, t, i + 1, j + 1); // Include current char 👣
        }
        count += solveUsingRecursion(s, t, i + 1, j); // Exclude current char 🔄

        return count;
    }

    // 🧠 Memoized solution to store intermediate results
    // Algorithm:
    // 1️⃣ Use a 2D DP array to store results for subproblems (`dp[i][j]`).
    // 2️⃣ If already computed, return the stored result to avoid recalculating.

    // 🔄 Time Complexity: O(n * m) 🕒
    // 💾 Space Complexity: O(n * m) for DP table

    int solveUsingMem(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j]; // Return cached result 🗄️

        int count = 0;
        if (s[i] == t[j]) {
            count += solveUsingMem(s, t, i + 1, j + 1, dp); // Include current char
        }
        count += solveUsingMem(s, t, i + 1, j, dp); // Exclude current char

        return dp[i][j] = count; // Store result before returning 💾
    }

    // 🔄 Tabulation approach to solve problem bottom-up
    // Algorithm:
    // 1️⃣ Create a DP table with dimensions (s.size() + 1) x (t.size() + 1).
    // 2️⃣ Initialize the base case: If `t` is empty, there's one valid subsequence (empty subsequence).
    // 3️⃣ Fill the table using the recurrence relation derived from recursion.

    // 🔄 Time Complexity: O(n * m) 🕒
    // 💾 Space Complexity: O(n * m) for DP table

    int solveUsingTab(string& s, string& t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        // Base case: If `t` is empty, there's one valid subsequence
        for (int i = 0; i <= s.size(); i++) {
            dp[i][t.size()] = 1; // Subsequence found ✅
        }

        // Fill DP table from bottom-up
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = t.size() - 1; j >= 0; j--) {
                int count = 0;
                if (s[i] == t[j]) {
                    count += dp[i + 1][j + 1]; // Include current char 👣
                }
                count += dp[i + 1][j]; // Exclude current char 🔄
                dp[i][j] = count;
            }
        }

        return dp[0][0]; // Result is in dp[0][0] 🏆
    }

    // 🌟 Main function to call the preferred solution
    int numDistinct(string s, string t) {
        // Example output:
        // s = "rabbbit", t = "rabbit"
        // The number of distinct subsequences of "rabbbit" that equal "rabbit" is 3.

        // Uncomment to test other approaches
        // vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1)); // For memoization
        // return solveUsingMem(s, t, 0, 0, dp); // Memoization approach

        return solveUsingTab(s, t); // Use Tabulation by default
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case
    string s = "rabbbit";
    string t = "rabbit";
    int result = solution.numDistinct(s, t); // Calculate the result

    // 📜 Output the result
    cout << "Number of distinct subsequences: " << result << endl; // Output: 3

    return 0;
}

/*
⏳ Time Complexity:
- Recursive approach: O(2^n), due to exploring all subsequences.
- Memoized approach: O(n * m), where n is the length of `s` and m is the length of `t`.
- Tabulation approach: O(n * m), same as memoization.
 
💾 Space Complexity:
- Recursive approach: O(n + m) for the recursion stack.
- Memoized approach: O(n * m) for the DP table.
- Tabulation approach: O(n * m) for the DP table.

📊 Example Output:
Number of distinct subsequences: 3

Explanation:
In the string "rabbbit", there are 3 distinct subsequences that equal "rabbit":
1. r**a**b**b**b**i**t
2. r**a**b**b**b**i**t
3. r**a**b**b**i**t
*/
