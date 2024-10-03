#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 🔍 Helper function to check if a substring is a palindrome
    // Algorithm:
    // 1️⃣ Compare characters from the start and end of the substring.
    // 2️⃣ Move towards the center until the characters do not match or all have been checked.
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false; // Mismatch found
            }
            start++, end--; // Move towards the center
        }
        return true; // All characters matched
    }

    // 🌀 Naive approach to find the longest palindromic substring
    // Algorithm:
    // 1️⃣ Check all substrings using two nested loops.
    // 2️⃣ Use isPalindrome function to verify each substring.
    // 3️⃣ Track the longest palindromic substring found.
    string longestPalindromenp(string s) {
        string ans = ""; // To store the longest palindrome

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (isPalindrome(s, i, j)) { // Check if current substring is a palindrome
                    string t = s.substr(i, j - i + 1); // Get the substring
                    ans = t.size() > ans.size() ? t : ans; // Update longest palindrome
                }
            }
        }

        return ans; // Return the longest palindromic substring
    }

    // 🏆 Dynamic Programming approach to find the longest palindromic substring
    // Algorithm:
    // 1️⃣ Create a DP table to store palindrome status for substrings.
    // 2️⃣ Initialize for single characters and two-character palindromes.
    // 3️⃣ Fill the table for substrings longer than 2 based on previously computed values.
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return ""; // Return empty if input is empty
        if (n == 1) return s; // Return the string itself if it's a single character

        vector<vector<bool>> dp(n, vector<bool>(n, false)); // DP table
        string ans = ""; // To store the longest palindrome

        // Base cases for single characters
        for (int i = 0; i < n; i++) {
            dp[i][i] = true; // Single characters are palindromes
            ans = s[i]; // Initialize the answer with the first character
        }

        // Base cases for two-character palindromes
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = (s[i] == s[i + 1]); // Check for two-character palindromes
            if (dp[i][i + 1]) {
                ans = s.substr(i, 2); // Update answer if we find a two-character palindrome
            }
        }

        // Fill the DP table for substrings longer than 2
        for (int length = 3; length <= n; length++) { // Length of substring
            for (int i = 0; i < n - length + 1; i++) { // Starting index
                int j = i + length - 1; // Ending index
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1]; // Check palindrome
                if (dp[i][j] && length > ans.size()) {
                    ans = s.substr(i, length); // Update answer if it's the longest
                }
            }
        }

        return ans; // Return the longest palindromic substring
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case
    string s = "babad"; // Input string
    
    // Calculate the longest palindromic substring
    string result = solution.longestPalindrome(s);
    
    // 📜 Output the result
    cout << "Longest palindromic substring: " << result << endl; // Display result

    return 0;
}

/*
⏳ Time Complexity:
- Naive approach: O(n^3), where `n` is the length of the string due to nested loops and palindrome checks.
- Dynamic Programming approach: O(n^2), where `n` is the length of the string. The DP table is filled in a quadratic manner.

💾 Space Complexity:
- Naive approach: O(1) since no extra space is used apart from variables.
- Dynamic Programming approach: O(n^2) for the DP table used to track palindrome status.

📊 Example Output:
If s = "babad", the output could be:
Longest palindromic substring: "bab" or "aba"

Explanation:
Both "bab" and "aba" are valid longest palindromic substrings of "babad".
*/
