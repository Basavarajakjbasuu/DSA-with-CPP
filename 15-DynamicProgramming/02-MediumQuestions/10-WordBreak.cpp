#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 📝 Class to solve the "Word Break" problem
class Solution {
public:
    // 🔍 Helper function to check if a word exists in the dictionary
    bool isThereInDict(vector<string>& wordDict, string& word) {
        for(auto str : wordDict) {
            if (word == str) return true; // If word matches a dictionary entry
        }
        return false; // If word is not found
    }

    // 🌀 Recursive solution to check if the string can be segmented
    // Algorithm:
    // 1️⃣ Try forming words starting from the current `start` position.
    // 2️⃣ If a valid word is found in the dictionary, recursively check the remaining string.
    // 3️⃣ If the string is successfully segmented, return true.
    // 4️⃣ Base case: If the `start` index reaches the end of the string, it means the string is fully segmented.

    bool solveUsingRecursion(string& s, vector<string>& wordDict, int start) {
        // ✅ Base case: If we've reached the end of the string, return true
        if (start == s.size()) return true;

        // Form words incrementally starting from index `start`
        string word = "";
        bool canBreak = false; // Flag to track if valid partition found
        for (int i = start; i < s.size(); i++) {
            word += s[i]; // Add the current character to the word

            // Check if the formed word is in the dictionary
            if (isThereInDict(wordDict, word)) {
                // Recursively check the rest of the string after the current word
                canBreak = canBreak || solveUsingRecursion(s, wordDict, i + 1);
            }
        }

        return canBreak;
    }

    // 🧠 Memoized solution to store intermediate results
    // Algorithm:
    // 1️⃣ Use a `dp` array where `dp[start]` stores whether the string starting at `start` can be segmented.
    // 2️⃣ This avoids recalculating results for the same subproblems.

    bool solveUsingMemo(string& s, vector<string>& wordDict, int start, vector<int>& dp) {
        // ✅ Base case: If we've reached the end of the string, return true
        if (start == s.size()) return true;

        // If the result for this start index is already computed, return it
        if (dp[start] != -1) {
            return dp[start];
        }

        // Form words incrementally starting from index `start`
        string word = "";
        bool canBreak = false;
        for (int i = start; i < s.size(); i++) {
            word += s[i];

            // Check if the word exists in the dictionary
            if (isThereInDict(wordDict, word)) {
                // Recursively check and store the result in `dp`
                canBreak = canBreak || solveUsingMemo(s, wordDict, i + 1, dp);
            }
        }

        return dp[start] = canBreak; // Store the result for future reference
    }

    // 🔄 Tabulation (bottom-up DP) approach
    // Algorithm:
    // 1️⃣ Create a `dp` array where `dp[start]` indicates if the string from `start` can be segmented.
    // 2️⃣ Iterate from the end of the string to the beginning, checking each possible partition.

    bool solveUsingTab(string& s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, false); // DP array
        dp[s.size()] = true; // Base case: empty string can always be segmented

        // Process the string from right to left
        for (int start = s.size() - 1; start >= 0; start--) {
            string word = "";
            bool canBreak = false;

            // Check all possible words starting from the current `start` index
            for (int i = start; i < s.size(); i++) {
                word += s[i];

                // If the word exists in the dictionary and the rest of the string can be segmented
                if (isThereInDict(wordDict, word)) {
                    canBreak = canBreak || dp[i + 1];
                }
                dp[start] = canBreak; // Update DP table
            }
        }

        return dp[0]; // Return the result for the full string
    }

    // 🌟 Main function to solve the "Word Break" problem
    bool wordBreak(string s, vector<string>& wordDict) {
        // Uncomment the approach you want to test:
        // return solveUsingRecursion(s, wordDict, 0);  // Recursive solution

        // Memoization approach
        // vector<int> dp(s.size(), -1);
        // return solveUsingMemo(s, wordDict, 0, dp);

        // Tabulation approach
        return solveUsingTab(s, wordDict); // Space-efficient tabulation solution
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case
    string s = "leetcode"; // Input string
    vector<string> wordDict = {"leet", "code"}; // Dictionary of valid words

    bool result = solution.wordBreak(s, wordDict); // Calculate result

    // 📜 Output the result
    cout << "Can the string \"" << s << "\" be segmented? " << (result ? "Yes" : "No") << endl;

    return 0;
}

/*
⏳ Time Complexity:
- Recursive approach: O(2^n), where n is the length of the string. Exponential due to checking all partitions.
- Memoized approach: O(n * m), where n is the length of the string, and m is the length of the dictionary.
- Tabulation approach: O(n * m), same as memoization.

💾 Space Complexity:
- Recursive approach: O(n) for recursion stack.
- Memoized approach: O(n) for the dp array.
- Tabulation approach: O(n) for the dp array.

📊 Example Output:
If the input string is "leetcode" and the word dictionary is {"leet", "code"}, the output will be:
Can the string "leetcode" be segmented? Yes
*/

