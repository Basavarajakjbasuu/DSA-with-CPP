#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// 📝 Class to solve the "Word Break II" problem
class Solution {
public:
    // 🌀 Recursive solution to generate all possible segmentations
    // Algorithm:
    // 1️⃣ Starting from index `i`, form words character by character.
    // 2️⃣ If the formed word is found in the dictionary, recursively solve for the remaining string.
    // 3️⃣ Combine the current word with the valid segmentations of the remaining string.
    // 4️⃣ Base case: If we reach the end of the string, return an empty string as a valid segmentation.

    vector<string> solveUsingRecursion(string& s, unordered_map<string, bool>& dict, int startIndex) {
        if (startIndex == s.size()) return {""}; // Base case: end of string reached

        vector<string> result; // Store valid segmentations
        string currentWord;

        // Try forming words starting from the current index
        for (int j = startIndex; j < s.size(); j++) {
            currentWord.push_back(s[j]); // Add character to form the current word

            // If the current word is not in the dictionary, skip
            if (dict.find(currentWord) == dict.end()) continue;

            // Recursively solve for the remaining string
            auto rightPartSegmentations = solveUsingRecursion(s, dict, j + 1);

            // Combine the current word with valid segmentations of the rest of the string
            for (auto& eachRightPart : rightPartSegmentations) {
                string combined = currentWord + (eachRightPart.empty() ? "" : " " + eachRightPart);
                result.push_back(combined); // Add combined result
            }
        }

        return result;
    }

    // 🧠 Memoized solution to avoid recalculating results for the same start index
    // Algorithm:
    // 1️⃣ Use a `dp` map where `dp[i]` stores all valid segmentations starting from index `i`.
    // 2️⃣ Recursively calculate and store results to prevent redundant calculations.

    vector<string> solveUsingMemo(string& s, unordered_map<string, bool>& dict, int startIndex, unordered_map<int, vector<string>>& memo) {
        if (startIndex == s.size()) return {""}; // Base case: end of string reached

        // Check if the result for this start index is already computed
        if (memo.find(startIndex) != memo.end()) return memo[startIndex];

        vector<string> result;
        string currentWord;

        // Try forming words starting from the current index
        for (int j = startIndex; j < s.size(); j++) {
            currentWord.push_back(s[j]); // Add character to form the current word

            // If the current word is not in the dictionary, skip
            if (dict.find(currentWord) == dict.end()) continue;

            // Recursively solve for the remaining string
            auto rightPartSegmentations = solveUsingMemo(s, dict, j + 1, memo);

            // Combine the current word with valid segmentations of the rest of the string
            for (auto& eachRightPart : rightPartSegmentations) {
                string combined = currentWord + (eachRightPart.empty() ? "" : " " + eachRightPart);
                result.push_back(combined); // Add combined result
            }
        }

        return memo[startIndex] = result; // Store the result in the memoization map
    }

    // 🌟 Main function to solve the "Word Break II" problem
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Create a dictionary (unordered_map) for quick lookups
        unordered_map<string, bool> dict;
        for (auto& word : wordDict) dict[word] = true;

        // Uncomment the approach you want to test:
        // return solveUsingRecursion(s, dict, 0);  // Recursive solution

        // Memoization approach
        unordered_map<int, vector<string>> memo;
        return solveUsingMemo(s, dict, 0, memo); // Use the memoized solution
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case
    string s = "catsanddog"; // Input string
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"}; // Dictionary of valid words

    // Calculate all possible segmentations
    vector<string> result = solution.wordBreak(s, wordDict);

    // 📜 Output the result
    cout << "All possible segmentations of \"" << s << "\":" << endl;
    for (const string& segmentation : result) {
        cout << segmentation << endl;
    }

    return 0;
}

/*
⏳ Time Complexity:
- Recursive approach: O(2^n) in the worst case due to trying all possible segmentations.
- Memoized approach: O(n^2 * m), where n is the length of the string, and m is the average length of the words in the dictionary.

💾 Space Complexity:
- Recursive approach: O(n) for the recursion stack.
- Memoized approach: O(n^2) for the dp array storing all segmentations.

📊 Example Output:
If the input string is "catsanddog" and the word dictionary is {"cat", "cats", "and", "sand", "dog"}, the output will be:
All possible segmentations of "catsanddog":
cats and dog
cat sand dog
*/

