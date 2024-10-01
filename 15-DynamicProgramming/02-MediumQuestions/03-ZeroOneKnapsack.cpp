  #include <iostream>
  #include <vector>
  using namespace std;

  class Solution {
  public:
      /**
       * 🌟 Recursive Solution to 0/1 Knapsack:
       * 
       * 1️⃣ **Base Case**: If the current index exceeds the size or weight capacity `W` becomes 0, return 0.
       * 2️⃣ **Recursive Choices**:
       *      - Option 1: Include the current item (if its weight is less than or equal to `W`) and move to the next item.
       *      - Option 2: Exclude the current item and move to the next item.
       * 3️⃣ **Goal**: Return the maximum value that can be obtained by making the best choice at each step.
       * 
       * Time Complexity: O(2^n) 🕒 (exponential due to recursive branching).
       * Space Complexity: O(n) 🧠 (due to the recursion stack).
       */
      int usingRecursion(int W, vector<int>& wt, vector<int>& val, int index, int size) {
          if (index >= size || W <= 0) return 0;

          int include = 0;
          if (wt[index] <= W) {
              include = val[index] + usingRecursion(W - wt[index], wt, val, index + 1, size);
          }
          
          int exclude = usingRecursion(W, wt, val, index + 1, size);
          return max(include, exclude);
      }

      /**
       * 🌟 Memoization Solution to 0/1 Knapsack:
       * 
       * 1️⃣ **Memoization**: Store the maximum value for each item and weight combination to avoid redundant calculations.
       * 2️⃣ Use a `dp` array to store previously computed results.
       * 
       * Time Complexity: O(n * W) 🕒 (each subproblem is solved once).
       * Space Complexity: O(n * W) 🧠 (due to the dp array).
       */
      int usingMemoisation(int W, vector<int>& wt, vector<int>& val, int index, int size, vector<vector<int>>& dp) {
          if (index >= size || W <= 0) return 0;

          if (dp[W][index] != -1) return dp[W][index];

          int include = 0;
          if (wt[index] <= W) {
              include = val[index] + usingMemoisation(W - wt[index], wt, val, index + 1, size, dp);
          }

          int exclude = usingMemoisation(W, wt, val, index + 1, size, dp);
          dp[W][index] = max(include, exclude);
          return dp[W][index];
      }

      /**
       * 🌟 Tabulation Solution (Bottom-Up Dynamic Programming):
       * 
       * 1️⃣ **Goal**: Build a `dp` array such that `dp[i][w]` contains the maximum value for items 0 to `i` with a weight capacity `w`.
       * 2️⃣ **Transition**:
       *      - Include the current item if its weight `wt[i]` fits in the knapsack (add `val[i]` to the previous max value for weight `w - wt[i]`).
       *      - Exclude the current item and carry over the previous max value for the same weight.
       * 
       * Time Complexity: O(n * W) 🕒
       * Space Complexity: O(n * W) 🧠
       */
      int usingTabulation(int W, vector<int>& wt, vector<int>& val, int size) {
          vector<vector<int>> dp(size + 1, vector<int>(W + 1, 0));

          for (int i = 1; i <= size; i++) {
              for (int w = 0; w <= W; w++) {
                  dp[i][w] = dp[i - 1][w];  // Exclude the current item

                  if (wt[i - 1] <= w) {
                      dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);  // Include the current item
                  }
              }
          }
          return dp[size][W];
      }

      /**
       * 🌟 Space Optimized Tabulation Solution:
       * 
       * 1️⃣ **Goal**: Use only a 1D `dp` array to store the maximum value for each weight capacity `w`, reducing space complexity.
       * 2️⃣ **Transition**:
       *      - Iterate over the weight capacity backwards to ensure the current value doesn't interfere with calculations.
       * 
       * Time Complexity: O(n * W) 🕒
       * Space Complexity: O(W) 🧠
       */
      int usingTabulationSO(int W, vector<int>& wt, vector<int>& val, int size) {
          vector<int> dp(W + 1, 0);

          for (int i = 0; i < size; i++) {
              for (int w = W; w >= wt[i]; w--) {
                  dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
              }
          }
          return dp[W];
      }

      /**
       * 🌟 Driver Function:
       * 
       * Calls the space-optimized tabulation solution and returns the result.
       * 
       * Time Complexity: O(n * W) 🕒
       * Space Complexity: O(W) 🧠
       */
      int knapSack(int W, vector<int>& wt, vector<int>& val) {
          int size = wt.size();
          return usingTabulationSO(W, wt, val, size);
      }
  };

  // 🌟 Driver Code for Local Execution
  int main() {
      Solution solution;
      vector<int> wt = {10, 20, 30};  // Weights of the items
      vector<int> val = {60, 100, 120};  // Values of the items
      int W = 50;  // Maximum weight capacity of the knapsack

      // 🛠 Calling the knapSack function
      int maxProfit = solution.knapSack(W, wt, val);

      // 🎉 Print the result
      cout << "Maximum value that can be obtained: " << maxProfit << endl;

      return 0;
  }

  /**
   * Example Output:
   * Maximum value that can be obtained: 220
   * 
   * Explanation of Output:
   * By selecting items 1 and 2 (weights 20 and 30, values 100 and 120), 
   * the maximum value is 220 without exceeding the weight limit of 50.
   */

  // Time Complexity 🕒: O(n * W), where n is the number of items and W is the knapsack capacity.
  // Space Complexity 🧠: O(W) due to the space-optimized DP array.
