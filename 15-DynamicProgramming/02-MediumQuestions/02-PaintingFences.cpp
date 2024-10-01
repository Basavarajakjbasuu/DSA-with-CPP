#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long MOD = 1000000007;

    /**
     * 🌀 Recursive Approach:
     * 
     * 1️⃣ **Base Case**:
     *      - If `n == 1`, return `k` (since there's only one way to paint 1 post).
     *      - If `n == 2`, return the number of ways to paint 2 posts, which is `k + k*(k-1)`.
     * 2️⃣ **Recursive Formula**:
     *      - For `n > 2`, calculate the number of ways to paint using the result of the previous two posts.
     *      - Multiply the result by `(k-1)` to ensure adjacent posts don't have the same color.
     * 
     * Time Complexity 🕒: O(2^n) in the worst case (due to recursion).
     * Space Complexity 🧠: O(n) for the recursion stack.
     */
    long long usingRecursion(int posts, int colors) {
        if (posts == 1) return colors;
        if (posts == 2) return (colors + colors * (colors - 1)) % MOD;

        long long result = (usingRecursion(posts - 1, colors) + usingRecursion(posts - 2, colors)) * (colors - 1) % MOD;
        return result;
    }

    /**
     * 🧠 Memoization Approach:
     * 
     * 1️⃣ **Base Case**:
     *      - If `n == 1`, return `k`.
     *      - If `n == 2`, return `k + k*(k-1)`.
     * 2️⃣ **Memoization**:
     *      - Use a `dp` array to store results of subproblems, avoiding redundant calculations.
     * 3️⃣ **Recursive Formula**:
     *      - Similar to the recursive approach, but store results in `dp` to optimize.
     * 
     * Time Complexity 🕒: O(n) due to memoization.
     * Space Complexity 🧠: O(n) for the `dp` array.
     */
    long long getCountWaysWithMem(long long posts, long long colors, vector<long long>& dp) {
        if (posts == 1) return colors % MOD;
        if (posts == 2) return (colors + colors * (colors - 1)) % MOD;

        if (dp[posts] != -1) return dp[posts];

        dp[posts] = ((getCountWaysWithMem(posts - 1, colors, dp) + getCountWaysWithMem(posts - 2, colors, dp)) * (colors - 1)) % MOD;
        return dp[posts];
    }

    /**
     * 📊 Tabulation Approach (Bottom-up Dynamic Programming):
     * 
     * 1️⃣ **Base Case**:
     *      - Use an array `dp` to store the number of ways for each `n` starting from the smallest.
     *      - For `n == 1`, `dp[1] = k`.
     *      - For `n == 2`, `dp[2] = k + k * (k - 1)`.
     * 2️⃣ **Iterative Calculation**:
     *      - For each `n > 2`, calculate the number of ways using the values for `n-1` and `n-2`.
     * 
     * Time Complexity 🕒: O(n) (iterating from 1 to `n`).
     * Space Complexity 🧠: O(n) for the `dp` array.
     */
    long long getCountWaysWithTab(long long posts, long long colors) {
        vector<long long> dp(posts + 1, -1);
        dp[1] = colors;
        dp[2] = (colors + colors * (colors - 1)) % MOD;

        for (int i = 3; i <= posts; i++) {
            dp[i] = ((dp[i - 1] + dp[i - 2]) * (colors - 1)) % MOD;
        }

        return dp[posts];
    }

    /**
     * 💡 Space Optimized Tabulation:
     * 
     * 1️⃣ **Reduce Space**:
     *      - Instead of using a full `dp` array, use just three variables to keep track of previous results.
     * 2️⃣ **Iterative Calculation**:
     *      - Start from the base cases and iteratively compute the result with reduced space usage.
     * 
     * Time Complexity 🕒: O(n)
     * Space Complexity 🧠: O(1) (only three variables used).
     */
    long long getCountWaysWithTabSO(long long posts, long long colors) {
        long long prev1 = colors;
        long long prev2 = (colors + colors * (colors - 1)) % MOD;
        long long current = 0;

        for (int i = 3; i <= posts; i++) {
            current = ((prev1 + prev2) * (colors - 1)) % MOD;
            prev1 = prev2;
            prev2 = current;
        }

        return current;
    }

    /**
     * 🚀 Main function to calculate the number of ways to paint `n` posts using `k` colors:
     * Calls the tabulation method to get the result.
     */
    long long countWays(int posts, int colors) {
        return getCountWaysWithTab(posts, colors);
    }
};

// 🏁 Driver code to test the solution
int main() {
    Solution solution;
    int posts = 5;
    int colors = 3;

    // 📤 Call the function and print the result
    cout << "Number of ways to paint the fence: " << solution.countWays(posts, colors) << endl;

    return 0;
}

/*
⏳ Time Complexity:
- O(n) for both tabulation and memoization approaches.

💾 Space Complexity:
- O(n) for tabulation and memoization, and O(1) for space-optimized tabulation.

📊 Example Output:
/*
Explanation of Output for n = 5 and k = 3:
We are given:
  - n = 5 (number of fence posts)
  - k = 3 (number of available colors)

We need to ensure no two adjacent posts have the same color.

1️⃣ **Base Cases**:
   - For `n = 1`, there are exactly `k = 3` ways to paint the first post, as any of the 3 colors can be chosen.
   - For `n = 2`, we have:
     - 3 ways to paint the first post.
     - For the second post, it must be a different color from the first one, so there are `k-1 = 2` choices.
     - Total for two posts: `3 * 2 = 6`.

2️⃣ **Recursive Case for n > 2**:
   - From the third post onwards, the total number of ways depends on how the previous posts were painted:
     - For each new post, we can either:
       a) Paint it the same color as the `n-2` post (since adjacent posts can't be the same).
       b) Paint it a different color from the `n-1` post.
     - This leads to the formula: `(ways to paint n-1 posts + ways to paint n-2 posts) * (k-1)`.

3️⃣ **Step-by-Step Calculation**:
   For `n = 1`:
     - There are exactly `3` ways to paint the first post.
   
   For `n = 2`:
     - There are `3 * 2 = 6` ways to paint two posts.

   For `n = 3`:
     - The number of ways to paint 3 posts is `(6 + 3) * (k - 1) = (6 + 3) * 2 = 18`.

   For `n = 4`:
     - The number of ways to paint 4 posts is `(18 + 6) * 2 = 48`.

   For `n = 5`:
     - The number of ways to paint 5 posts is `(48 + 18) * 2 = 132`.

4️⃣ **Correct Answer (180)**:
   However, there is a slight adjustment. For `n = 2`, the formula for painting 2 posts is actually:
     - `k + k * (k-1) = 3 + 3 * 2 = 9` ways.
   
   So the calculations should be:
   - For `n = 3`: `(9 + 3) * 2 = 24`
   - For `n = 4`: `(24 + 9) * 2 = 66`
   - For `n = 5`: `(66 + 24) * 2 = 180`

Thus, for `n = 5` fence posts and `k = 3` colors, the total number of ways to paint them is **180**.
*/
