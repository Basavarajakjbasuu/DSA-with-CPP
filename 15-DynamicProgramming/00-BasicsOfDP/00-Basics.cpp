#include <iostream>
#include <vector>
using namespace std;

// 🌟 Solution class to calculate Fibonacci number using various DP approaches
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
    long long int getFibo(int n, vector<long long int>& dp) {
        if (n == 0 || n == 1) {
            return n;  // Base cases
        }
        
        // 🟡 Return already computed result from dp array
        if (dp[n] != -1) {
            return dp[n];
        }
        
        // 🟢 Compute and store result in dp array
        dp[n] = (getFibo(n-1, dp) + getFibo(n-2, dp)) % MOD;
        return dp[n];
    }

    // 🚀 Top-Down Fibonacci function
    long long int topDown(int n) {
        if (n <= 1) return n;  // Base case
        vector<long long int> dp(n + 1, -1);  // DP array initialized to -1
        return getFibo(n, dp);  // Start recursion with memoization
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
    long long int bottomUp(int n) {
        if (n <= 1) return n;  // Base case
        vector<long long int> dp(n + 1, -1);  // DP array
        
        dp[0] = 0;  // Fibonacci of 0
        dp[1] = 1;  // Fibonacci of 1
        
        // 🔵 Fill the DP array iteratively
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;  // Apply modulo at each step
        }
        
        return dp[n];  // Return the Fibonacci value for n
    }

    /**
     * 🌟 Bottom-Up Space Optimized Approach:
     * 1️⃣ Instead of using a full DP array, maintain only two variables to store previous values.
     * 2️⃣ Iteratively compute the Fibonacci number, keeping track of the last two values.
     *
     * Time Complexity: O(n) 🕒 (linear traversal).
     * Space Complexity: O(1) 🧠 (constant space used by two variables).
     */
    long long int bottomUpSpaceOptimised(int n) {
        if (n <= 1) return n;  // Base case

        int prev = 0;  // Previous Fibonacci number (F(n-2))
        int curr = 1;  // Current Fibonacci number (F(n-1))
        int ans = 0;   // To store the current Fibonacci number
        
        // 🟢 Iteratively compute Fibonacci numbers while maintaining only two variables
        for (int i = 2; i <= n; i++) {
            ans = (prev + curr) % MOD;  // Compute current Fibonacci
            prev = curr;  // Move curr to prev
            curr = ans;   // Update curr to the new ans
        }
        
        return ans;  // Return the nth Fibonacci number
    }
};

// 🌟 Driver code for local execution
int main() {
    Solution solution;

    int n = 10;  // Fibonacci number to compute

    // 🛠 Using Top-Down approach (Memoization)
    long long int topDownResult = solution.topDown(n);
    cout << "Top-Down Fibonacci result for " << n << ": " << topDownResult << endl;

    // 🛠 Using Bottom-Up approach (Tabulation)
    long long int bottomUpResult = solution.bottomUp(n);
    cout << "Bottom-Up Fibonacci result for " << n << ": " << bottomUpResult << endl;

    // 🛠 Using Bottom-Up Space Optimized approach
    long long int bottomUpOptResult = solution.bottomUpSpaceOptimised(n);
    cout << "Bottom-Up Space Optimized Fibonacci result for " << n << ": " << bottomUpOptResult << endl;

    return 0;
}

/**
 * Example Output:
 * Top-Down Fibonacci result for 10: 55
 * Bottom-Up Fibonacci result for 10: 55
 * Bottom-Up Space Optimized Fibonacci result for 10: 55
 * 
 * Explanation of Output:
 * The 10th Fibonacci number is 55, and all three approaches return the same result: 55.
 */

// Time Complexity 🕒:
// - Top-Down (Memoization): O(n)
// - Bottom-Up (Tabulation): O(n)
// - Bottom-Up Space Optimized: O(n)

// Space Complexity 🧠:
// - Top-Down (Memoization): O(n) due to DP array and recursion stack
// - Bottom-Up (Tabulation): O(n) due to DP array
// - Bottom-Up Space Optimized: O(1) due to constant space usage
