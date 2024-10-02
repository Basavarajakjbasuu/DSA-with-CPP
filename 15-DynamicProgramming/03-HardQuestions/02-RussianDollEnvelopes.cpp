#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 📝 Class Solution for solving the Russian Doll Envelopes problem
class Solution {
public:
    // 🧩 Function to check if one envelope can fit into another
    // Algorithm:
    // 1️⃣ The current envelope (`curr`) can be placed inside the previous envelope (`prev`)
    //    if both its width and height are strictly greater than the previous envelope.
    bool canFit(vector<int>& curr, vector<int>& prev) {
        return prev[0] < curr[0] && prev[1] < curr[1];
    }

    // 🔄 Function to solve using space-optimized tabulation (bottom-up DP)
    // Algorithm:
    // 1️⃣ Sort the envelopes based on width and height.
    // 2️⃣ Iterate over each envelope and use dynamic programming to find the maximum number
    //     of envelopes that can be nested inside each other.
    // 3️⃣ For each envelope, decide whether to include it in the stack or exclude it.
    // 4️⃣ Store results in the `currRow` and `nextRow` arrays for space optimization.
    int solveUsingTabSO(vector<vector<int>>& env) {
        int n = env.size();
        vector<int> currRow(n + 1, 0); // Current row for DP
        vector<int> nextRow(n + 1, 0); // Next row for DP

        // Iterate through all envelopes in reverse order
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                int include = 0, exclude = 0; // Initialize choices

                // Check if current envelope can fit inside the previous one
                if (prevIndex == -1 || canFit(env[currIndex], env[prevIndex])) {
                    include = 1 + nextRow[currIndex + 1]; // Include current envelope
                }
                exclude = nextRow[prevIndex + 1]; // Exclude current envelope

                // Take the maximum of including or excluding the envelope
                currRow[prevIndex + 1] = max(include, exclude);
            }
            nextRow = currRow; // Move to the next row for the next iteration
        }
        return nextRow[0]; // Return the maximum number of envelopes that can be nested
    }

    // ⚡ Function to solve using binary search (efficient approach)
    // Algorithm:
    // 1️⃣ Sort envelopes based on width in ascending order.
    //    - If two envelopes have the same width, sort them by height in descending order.
    // 2️⃣ Use dynamic programming with binary search to find the longest increasing subsequence
    //     based on height.
    // 3️⃣ The length of the longest subsequence will be the maximum number of envelopes that
    //     can be nested.
    int solveUsingBS(vector<vector<int>>& envelopes) {
        // Sort envelopes: width in ascending order, height in descending for same widths
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        vector<int> dp; // Store the heights for the longest increasing subsequence

        // Iterate through each envelope and apply binary search
        for (const auto& envelope : envelopes) {
            int height = envelope[1];
            // Use binary search to find the insertion point for the current height
            auto it = lower_bound(dp.begin(), dp.end(), height);
            
            // If the height is greater than all elements in dp, append it
            if (it == dp.end()) {
                dp.push_back(height);
            } else {
                // Replace the found position with the current height to maintain the sequence
                *it = height;
            }
        }

        // Return the size of dp, which represents the maximum number of nested envelopes
        return dp.size();
    }

    // 📏 Main function to compute the maximum number of nested envelopes
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Uncomment the tabulation approach if needed
        // return solveUsingTabSO(envelopes);

        // Use the binary search approach for an optimized solution
        return solveUsingBS(envelopes);
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case: Find the maximum number of envelopes that can be nested
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}}; // Input envelopes
    int maxEnvelopesCount = solution.maxEnvelopes(envelopes); // Calculate the result

    // 📜 Output the maximum number of nested envelopes
    cout << "Maximum number of nested envelopes: " << maxEnvelopesCount << endl; // Display result

    return 0; // Indicate that the program ended successfully
}

/*
⏳ Time Complexity:
- Binary Search Approach: O(n log n), where n is the number of envelopes.
  - Sorting the envelopes takes O(n log n).
  - Finding the longest increasing subsequence using binary search takes O(n log n).

- Tabulation Approach: O(n^2) due to the double loop that checks all envelopes.

💾 Space Complexity:
- Binary Search Approach: O(n) for the dp array storing the longest increasing subsequence.
- Tabulation Approach: O(n) for the space-optimized dp array (`currRow` and `nextRow`).

📊 Example Output:
If the input envelopes are {{5, 4}, {6, 4}, {6, 7}, {2, 3}}, the output will be:
Maximum number of nested envelopes: 3

Explanation:
1. After sorting, the envelopes are {{2, 3}, {5, 4}, {6, 4}, {6, 7}}.
2. The maximum number of envelopes that can be nested is 3: {{2, 3}}, {{5, 4}}, {{6, 7}}.
*/
