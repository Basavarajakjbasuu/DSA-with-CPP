#include <iostream>
#include <vector>
using namespace std;

// 🌟 Class to calculate Fibonacci number using Top-Down and Bottom-Up DP approaches
class Solution {
public:
    const int MOD = 1e9 + 7;  // MOD constant to handle large numbers

    /**
     * 🌟 Top-Down Approach (Memoization):
     * 1️⃣ Base case: If n == 0 or n == 1, return n (Fibonacci values for 0 and 1).
     * 2️⃣ Use a DP array to store results of subproblems and avoid recalculations.
     * 3️⃣ If the Fibonacci number for n is already calculated (dp[n] != -1), return it.
     * 4️⃣ Recursively calculate the Fibonacci number using the relation:
     *      F(n) = F(n-1) + F(n-2), with modulo applied at each step.
     *
     * Time Complexity: O(n) 🕒 (linear, due to memoization avoiding redundant calls).
     * Space Complexity: O(n) 🧠 (due to the recursion stack and DP array).
     */
    long long int getFiboTopDown(int n, vector<long long int>& dp) {
        if (n == 0 || n == 1) {
            return n;  // Base cases
        }
        
        // 🟡 Return already computed result from dp array
        if (dp[n] != -1) {
            return dp[n];
        }
        
        // 🟢 Compute and store result in dp array
        dp[n] = (getFiboTopDown(n-1, dp) + getFiboTopDown(n-2, dp)) % MOD;
        return dp[n];
    }
    
    // 🚀 Function to compute Fibonacci using the Top-Down approach
    long long int topDownFibonacci(int n) {
        if (n <= 1) return n;  // Base case
        vector<long long int> dp(n + 1, -1);  // DP array initialized to -1
        return getFiboTopDown(n, dp);
    }

    /**
     * 🌟 Bottom-Up Approach (Tabulation):
     * 1️⃣ Initialize a DP array where dp[0] = 0 and dp[1] = 1.
     * 2️⃣ For each i from 2 to n, compute:
     *      dp[i] = dp[i-1] + dp[i-2], with modulo applied at each step.
     *
     * Time Complexity: O(n) 🕒 (linear traversal).
     * Space Complexity: O(n) 🧠 (DP array of size n).
     */
    long long int bottomUpFibonacci(int n) {
        if (n <= 1) return n;  // Base case
        vector<long long int> dp(n + 1, 0);  // DP array
        
        dp[0] = 0;  // Fibonacci of 0
        dp[1] = 1;  // Fibonacci of 1
        
        // 🔵 Fill the DP array iteratively
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;  // Apply modulo at each step
        }
        
        return dp[n];  // Return the Fibonacci value for n
    }
};

// 🌟 Driver code for local execution
int main() {
    Solution solution;
    
    int n = 10;  // Fibonacci number to compute

    // 🛠 Using Top-Down approach (Memoization)
    long long int topDownResult = solution.topDownFibonacci(n);
    cout << "Top-Down Fibonacci result for " << n << ": " << topDownResult << endl;

    // 🛠 Using Bottom-Up approach (Tabulation)
    long long int bottomUpResult = solution.bottomUpFibonacci(n);
    cout << "Bottom-Up Fibonacci result for " << n << ": " << bottomUpResult << endl;

    return 0;
}

/**
 * Example Output:
 * Top-Down Fibonacci result for 10: 55
 * Bottom-Up Fibonacci result for 10: 55
 * 
 * Explanation of Output:
 * The 10th Fibonacci number is 55, and both the Top-Down (Memoization) and Bottom-Up
 * (Tabulation) approaches return the same result.
 */

// Time Complexity: O(n) 🕒 for both top-down and bottom-up approaches.
// Space Complexity: O(n) 🧠 for both approaches due to the use of a DP array.
