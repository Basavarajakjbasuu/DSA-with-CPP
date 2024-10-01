#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * 🚀 Space-Optimized Solution for Longest Common Subsequence (LCS):
     * 
     * Time Complexity: O(n * m) 🕒
     *    - We traverse each character of both strings once in nested loops.
     * 
     * Space Complexity: O(min(n, m)) 🧠
     *    - Uses two 1D arrays for storing intermediate results, reducing space usage.
     * 
     * Approach:
     * - We use two 1D arrays (`curr` and `next`) to store the current and next row results.
     * - This approach reduces space complexity compared to using a full 2D table.
     * 
     * 🟢 Matching Characters: 
     *   If the characters match, include them in the LCS by adding 1 to the diagonal value.
     * 
     * 🔁 Non-Matching Characters:
     *   Take the maximum LCS by either skipping a character from string `a` or `b`.
     */
    int solveUsingTabSO(string& a, string& b) {
        // 🌟 Create two arrays to store current and next row results
        vector<int> curr(a.length() + 1, 0);
        vector<int> next(a.length() + 1, 0);

        // 🔁 Traverse both strings from the end to the start
        for (int j_index = b.length() - 1; j_index >= 0; j_index--) {
            for (int i_index = a.length() - 1; i_index >= 0; i_index--) {
                int ans = 0;
                // 🟢 If characters match, add 1 to the result from the diagonal
                if (a[i_index] == b[j_index]) {
                    ans = 1 + next[i_index + 1];
                } else {
                    // 🔁 Otherwise, take the maximum of skipping either character
                    ans = max(next[i_index], curr[i_index + 1]);
                }
                curr[i_index] = ans; // Update the current row with the result
            }
            next = curr; // Shift the current row to next for the next iteration
        }
    
        // 🏆 Return the final result which is the LCS length
        return next[0];
    }

    /*
     * Time Complexity: O(n * m) 🕒
     * Space Complexity: O(min(n, m)) 🧠
     */
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(), a.end()); // 💡 Reverse string to compare with the original
        return solveUsingTabSO(s, a); // 🛠 Call the LCS function for the original and reversed string
    }
};

// 🌟 Driver Code
int main() {
    Solution solution;
    string s = "bbbab";  // Example input string

    // 🛠 Calling the longestPalindromeSubseq function
    int result = solution.longestPalindromeSubseq(s);

    // 🎉 Print the result
    cout << "Longest Palindromic Subsequence length: " << result << endl;

    return 0;
}

/*
 * Example Output:
 * Longest Palindromic Subsequence length: 4
 * 
 * Explanation of Output:
 * The longest palindromic subsequence is "bbbb" which has length 4.
 */
