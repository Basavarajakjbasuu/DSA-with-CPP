#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 🌀 Recursive solution to calculate the minimum cost for tickets
    // Algorithm:
    // 1️⃣ If we are at the last day, return 0 (no more days left to travel).
    // 2️⃣ We have three ticket options:
    //     - 1-day pass: Add the cost of a 1-day pass and recursively calculate the cost for the next day.
    //     - 7-day pass: Find the next day after 7 days and recursively calculate the cost starting from there.
    //     - 30-day pass: Find the next day after 30 days and recursively calculate the cost starting from there.
    // 3️⃣ Return the minimum of these three options.
    int solveUsingRecursion(vector<int>& days, vector<int>& costs, int i) {
        // BASE CASE: No more travel days
        if (i >= days.size())
            return 0;

        // 1-day pass cost
        int cost1 = costs[0] + solveUsingRecursion(days, costs, i + 1);

        // 7-day pass cost
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + solveUsingRecursion(days, costs, j);

        // 30-day pass cost
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost30 = costs[2] + solveUsingRecursion(days, costs, j);

        // Return the minimum cost among 1-day, 7-day, and 30-day passes
        return min(cost1, min(cost7, cost30));
    }

    // 🧠 Memoized solution (top-down dynamic programming)
    // Algorithm:
    // 1️⃣ Same as the recursive approach, but store results in a `dp` array to avoid redundant calculations.
    // 2️⃣ This ensures that we compute the cost for each starting day only once.
    int solveUsingMem(vector<int>& days, vector<int>& costs, int i, vector<int>& dp) {
        // BASE CASE: No more travel days
        if (i >= days.size())
            return 0;

        // Return memoized result if available
        if (dp[i] != -1)
            return dp[i];

        // 1-day pass cost
        int cost1 = costs[0] + solveUsingMem(days, costs, i + 1, dp);

        // 7-day pass cost
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + solveUsingMem(days, costs, j, dp);

        // 30-day pass cost
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost30 = costs[2] + solveUsingMem(days, costs, j, dp);

        // Memoize the minimum cost
        dp[i] = min(cost1, min(cost7, cost30));
        return dp[i];
    }

    // 🔄 Tabulation (bottom-up dynamic programming) approach
    // Algorithm:
    // 1️⃣ Create a DP array where `dp[i]` stores the minimum cost to travel starting from day `i`.
    // 2️⃣ Iterate from the last travel day to the first, filling the DP array by checking the costs for 1-day, 7-day, and 30-day passes.
    int solveUsingTab(vector<int>& days, vector<int>& costs, int n) {
        vector<int> dp(n + 1, 0); // DP array initialized to 0
        dp[n] = 0; // No cost for days beyond the last travel day

        for (int i = n - 1; i >= 0; i--) {
            // 1-day pass cost
            int cost1 = costs[0] + dp[i + 1];

            // 7-day pass cost
            int passEndDay = days[i] + 7 - 1;
            int j = i;
            while (j < n && days[j] <= passEndDay) {
                j++;
            }
            int cost7 = costs[1] + dp[j];

            // 30-day pass cost
            passEndDay = days[i] + 30 - 1;
            j = i;
            while (j < n && days[j] <= passEndDay) {
                j++;
            }
            int cost30 = costs[2] + dp[j];

            // Store the minimum cost in dp[i]
            dp[i] = min(cost1, min(cost7, cost30));
        }

        return dp[0]; // Return the result starting from day 0
    }

    // 🔥 Main function to find the minimum cost of tickets
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        // Uncomment one of the solutions below to test different approaches

        // Recursive approach (inefficient for large inputs)
        // return solveUsingRecursion(days, costs, 0);

        // Memoized approach
        vector<int> dp(n, -1);
        return solveUsingMem(days, costs, 0, dp);

        // Tabulation approach (most efficient for large inputs)
        // return solveUsingTab(days, costs, n);
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case
    vector<int> days = {1, 4, 6, 7, 8, 20}; // Travel days
    vector<int> costs = {2, 7, 15}; // Ticket costs (1-day, 7-day, 30-day)
    
    // Calculate the minimum cost
    int result = solution.mincostTickets(days, costs);
    
    // 📜 Output the result
    cout << "Minimum cost for tickets: " << result << endl; // Display result

    return 0;
}

/*
⏳ Time Complexity:
- Recursive approach: O(2^n), where `n` is the number of travel days. Exponential due to multiple recursive calls.
- Memoized approach: O(n) where `n` is the number of travel days.
- Tabulation approach: O(n) where `n` is the number of travel days.

💾 Space Complexity:
- Recursive approach: O(n) due to recursion stack.
- Memoized approach: O(n) for the DP array.
- Tabulation approach: O(n) for the DP array.

📊 Example Output:
If days = {1, 4, 6, 7, 8, 20} and costs = {2, 7, 15}, the output will be:
Minimum cost for tickets: 11

Explanation:
- You can choose the 7-day pass on day 1, which covers days 1, 4, 6, 7, and 8.
- Then, you can choose the 1-day pass on day 20.
- Total cost = 7 + 2 = 11.
*/
