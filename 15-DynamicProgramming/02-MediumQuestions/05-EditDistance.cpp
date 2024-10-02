#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // 📚 Algorithm: Minimum Edit Distance using Recursion
    // This function calculates how many operations are needed to convert word1 to word2 using recursion.
    // It checks if the characters at current positions are the same and explores three possible operations:
    // 1. Replace a character
    // 2. Remove a character
    // 3. Insert a character
    // Complexity: O(3^N) due to exploring all paths in the recursion tree.
    // Space Complexity: O(N) for the recursive call stack.
    int solveUsingRecursion(string &word1, string &word2, int i, int j) {
        // 🛑 Base case: If we have reached the end of word2, return the remaining length of word1 (deletions)
        if (j == word2.length()) {
            return word1.length() - i; // Remaining characters in word1 need to be deleted
        }

        // 🛑 Base case: If we have reached the end of word1, return the remaining length of word2 (insertions)
        if (i == word1.length()) {
            return word2.length() - j; // Remaining characters in word2 need to be inserted
        }

        // 📖 If the characters match, move to the next characters without any operation
        if (word1[i] == word2[j]) {
            return solveUsingRecursion(word1, word2, i + 1, j + 1); // No operation needed, move both pointers
        } else {
            // 💡 If characters don't match, calculate all possible operations:
            // 1. Replace the character
            int replace = 1 + solveUsingRecursion(word1, word2, i + 1, j + 1);
            // 2. Remove a character from word1
            int remove = 1 + solveUsingRecursion(word1, word2, i + 1, j);
            // 3. Insert a character into word1
            int insert = 1 + solveUsingRecursion(word1, word2, i, j + 1);

            // 🔍 Return the minimum of the three operations
            return min(replace, min(remove, insert));
        }
    }

    // 📚 Algorithm: Minimum Edit Distance using Memoization
    // This function improves the recursive approach by storing results of previous calculations in a 2D array (dp).
    // It helps avoid redundant calculations and speeds up the process.
    // Complexity: O(N * M) where N and M are the lengths of word1 and word2.
    // Space Complexity: O(N * M) for the dp array.
    int solveUsingMem(string &word1, string &word2, int i, int j, vector<vector<int>>& dp) {
        // 🛑 Base case: If we have reached the end of word2, return the remaining length of word1 (deletions)
        if (j == word2.length()) {
            return word1.length() - i; // Remaining characters in word1 need to be deleted
        }

        // 🛑 Base case: If we have reached the end of word1, return the remaining length of word2 (insertions)
        if (i == word1.length()) {
            return word2.length() - j; // Remaining characters in word2 need to be inserted
        }

        // 🔍 Check if we already computed the answer for this state
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return the stored result
        }

        // 📖 If the characters match, move to the next characters without any operation
        if (word1[i] == word2[j]) {
            return dp[i][j] = solveUsingMem(word1, word2, i + 1, j + 1, dp); // No operation needed
        } else {
            // 💡 If characters don't match, calculate all possible operations:
            // 1. Replace the character
            int replace = 1 + solveUsingMem(word1, word2, i + 1, j + 1, dp);
            // 2. Remove a character from word1
            int remove = 1 + solveUsingMem(word1, word2, i + 1, j, dp);
            // 3. Insert a character into word1
            int insert = 1 + solveUsingMem(word1, word2, i, j + 1, dp);

            // 🔍 Store the minimum of the three operations in dp and return
            return dp[i][j] = min(replace, min(remove, insert));
        }
    }

    // 📚 Algorithm: Minimum Edit Distance using Tabulation
    // This function builds a table (2D array) iteratively to find the minimum edit distance.
    // It fills up the dp array based on previously computed values.
    // Complexity: O(N * M) where N and M are the lengths of word1 and word2.
    // Space Complexity: O(N * M) for the dp array.
    int solveUsingTabulation(string &word1, string &word2) {
        // Create a dp table with dimensions (N+1) x (M+1) initialized to 0
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

        // 🛑 Fill the base cases for the last row and column
        for (int j = 0; j <= word2.length(); j++) {
            dp[word1.length()][j] = word2.length() - j; // All characters from word2 need to be inserted
        }

        for (int i = 0; i <= word1.length(); i++) {
            dp[i][word2.length()] = word1.length() - i; // All characters from word1 need to be deleted
        }

        // 💡 Build the dp table from the bottom up
        for (int i = word1.length() - 1; i >= 0; i--) {
            for (int j = word2.length() - 1; j >= 0; j--) {
                // 📖 If characters match, no operation is needed, move diagonally in the table
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    // 💡 Calculate the costs for the three possible operations
                    int replace = 1 + dp[i + 1][j + 1]; // Replace
                    int remove = 1 + dp[i + 1][j];     // Remove
                    int insert = 1 + dp[i][j + 1];     // Insert

                    // 🔍 Store the minimum cost in the dp table
                    dp[i][j] = min(replace, min(remove, insert));
                }
            }
        }

        // 📥 Return the minimum edit distance found at the top-left corner of the table
        return dp[0][0];
    }

    // 📚 Algorithm: Minimum Edit Distance using Space-Optimized Tabulation
    // This function reduces the space complexity by using only two arrays instead of a full table.
    // Complexity: O(N * M) where N and M are the lengths of word1 and word2.
    // Space Complexity: O(M) for using only two arrays.
    int solveUsingTabulationSO(string &word1, string &word2) {
        // Create two arrays for current and previous row results
        vector<int> curr(word1.length() + 1, 0);
        vector<int> prev(word1.length() + 1, 0);

        // 🛑 Fill the base cases for the previous row
        for (int i = 0; i <= word1.length(); i++) {
            prev[i] = word1.length() - i; // All characters from word1 need to be deleted
        }

        // 💡 Build the table iteratively
        for (int j = 0; j <= word2.length()-1; j++) {
            curr[word1.length()] = word2.length() - j; // All characters from word2 need to be inserted
            for (int i = word1.length() - 1; i >= 0; i--) {
                // 📖 If characters match, no operation is needed
                if (word1[i] == word2[j]) {
                    curr[i] = prev[i + 1]; // Move diagonally
                } else {
                    // 💡 Calculate the costs for the three possible operations
                    int replace = 1 + prev[i + 1]; // Replace
                    int remove = 1 + prev[i];      // Remove
                    int insert = 1 + curr[i + 1];  // Insert

                    // 🔍 Store the minimum cost in the current array
                    curr[i] = min(replace, min(remove, insert));
                }
            }
            // 🌀 Swap the arrays for the next iteration
            prev = curr; // Move current to previous for the next column
        }

        // 📥 Return the minimum edit distance found in the first position
        return prev[0];
    }

    // 🚀 Main function to execute and test the algorithms
    int minDistance(string word1, string word2) {
        // 🌟 Uncomment the desired method to test
        // return solveUsingRecursion(word1, word2, 0, 0); // Using Recursion
        // Initialize the dp array for memoization
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        // return solveUsingMem(word1, word2, 0, 0, dp); // Using Memoization
        // return solveUsingTabulation(word1, word2); // Using Tabulation
        return solveUsingTabulationSO(word1, word2); // Using Space-Optimized Tabulation
    }
};

// 🎉 Example usage of the Solution class
int main() {
    Solution sol; // Create an instance of the Solution class
    string word1 = "horse"; // Input word1
    string word2 = "ros";   // Input word2

    // 🔍 Call the minDistance function and print the result
    cout << "Minimum Edit Distance: " << sol.minDistance(word1, word2) << endl; // Output the result

    return 0; // Exit the program
}

/*
Example Output Explanation:
Given the words "horse" and "ros", the minimum edit distance is 3:
1. Replace 'h' with 'r' (horse -> rorse)
2. Remove 'e' (rorse -> rors)
3. Insert 'o' (rors -> ros)
Thus, it takes 3 operations to convert "horse" to "ros".
*/
