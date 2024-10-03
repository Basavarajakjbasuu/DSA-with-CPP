#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// 📝 Class to solve the Minimum Perfect Squares problem
class Solution {
public:
    // 🌀 Recursive solution to find the minimum number of perfect squares that sum up to `n`
    // Algorithm:
    // 1️⃣ Base case: If `n == 0`, return 1 (perfect sum found), and if `n < 0`, return 0 (invalid case).
    // 2️⃣ For each integer `i` such that `i * i` is less than or equal to `n`, recursively subtract the perfect square `i * i` from `n` and compute the result.
    // 3️⃣ Choose the minimum number of perfect squares required by keeping track of the smallest answer.
    int solveUsingRecursion(int n) {
        // Base case: Perfect sum found
        if (n == 0)
            return 1;
        // Invalid case
        if (n <= 0)
            return 0;

        int ans = INT_MAX;
        int i = 1, end = sqrt(n);
        // Try each perfect square less than or equal to `n`
        while (i <= end) {
            int perfectSquare = i * i;
            // Recursive call to check for remaining `n - perfectSquare`
            int numberOfPerfectSquares = 1 + solveUsingRecursion(n - perfectSquare);

            // Keep track of the minimum number of squares
            if (numberOfPerfectSquares < ans)
                ans = numberOfPerfectSquares;

            ++i;
        }

        return ans;
    }

    // 🧠 Memoized solution (top-down dynamic programming)
    // Algorithm:
    // 1️⃣ Same as the recursive approach, but we store intermediate results in a DP array to avoid recalculating the same subproblems.
    int solveUsingMem(int n, vector<int>& dp) {
        // Base case: Perfect sum found
        if (n == 0)
            return 1;
        // Invalid case
        if (n <= 0)
            return 0;

        // Return memoized result if available
        if (dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        int i = 1, end = sqrt(n);
        // Try each perfect square less than or equal to `n`
        while (i <= end) {
            int perfectSquare = i * i;
            // Recursive call with memoization
            int numberOfPerfectSquares = 1 + solveUsingMem(n - perfectSquare, dp);

            if (numberOfPerfectSquares < ans)
                ans = numberOfPerfectSquares;

            ++i;
        }

        dp[n] = ans; // Store the result in DP array
        return dp[n];
    }

    // 🔄 Tabulation (bottom-up dynamic programming) approach
    // Algorithm:
    // 1️⃣ Create a DP array where `dp[i]` stores the minimum number of perfect squares that sum up to `i`.
    // 2️⃣ For each number `i` from 1 to `n`, check all perfect squares less than or equal to `i` and update the DP array.
    int solveUsingTab(int n) {
        vector<int> dp(n + 1, INT_MAX);

        // Base case: 1 way to represent 0 (with no numbers)
        dp[0] = 1;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            int start = 1;
            // Try all perfect squares less than or equal to `i`
            while (start * start <= i) {
                int perfectSquare = start * start;
                if (i - perfectSquare >= 0) {
                    dp[i] = std::min(dp[i], 1 + dp[i - perfectSquare]);
                }
                ++start;
            }
        }

        return dp[n]; // Return the result for `n`
    }

    // 🔥 Main function to find the minimum number of perfect squares that sum up to `n`
    int numSquares(int n) {
        // Uncomment one of the solutions below to test different approaches

        // Recursive approach (inefficient for large inputs)
        // return solveUsingRecursion(n) - 1;

        // Memoized approach
        // vector<int> dp(n + 1, -1);
        // return solveUsingMem(n, dp) - 1;

        // Tabulation approach (most efficient for large inputs)
        return solveUsingTab(n) - 1;
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case
    int n = 12; // Input number
    int result = solution.numSquares(n); // Find the minimum number of perfect squares

    // 📜 Output the result
    cout << "Minimum number of perfect squares for " << n << " is: " << result << endl; // Display result

    return 0;
}

/*
⏳ Time Complexity:
- Recursive approach: O(2^n), where `n` is the input. Exponential time due to multiple recursive calls.
- Memoized approach: O(n * sqrt(n)), where `n` is the input and `sqrt(n)` represents the number of perfect squares less than or equal to `n`.
- Tabulation approach: O(n * sqrt(n)) for filling the DP table.

💾 Space Complexity:
- Recursive approach: O(n) due to recursive call stack.
- Memoized approach: O(n) for the DP array.
- Tabulation approach: O(n) for the DP array.

📊 Example Output:
If n = 12, the output will be:
Minimum number of perfect squares for 12 is: 3

Explanation:
1. We can form 12 using the following perfect squares:
   - 4 + 4 + 4 = 12, which consists of three perfect squares.
*/
