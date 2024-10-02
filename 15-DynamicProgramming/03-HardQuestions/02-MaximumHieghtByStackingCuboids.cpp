#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 📝 Class Solution that finds the maximum height for stacked cuboids
class Solution {
public:
    // 🧩 Function to check if a cuboid can be placed on top of another
    // Algorithm:
    // 1️⃣ The current cuboid (`curr`) can be placed on top of the previous cuboid (`prev`)
    //    if all its dimensions are smaller or equal to the previous cuboid.
    // 2️⃣ Specifically, the width, depth, and height of the `curr` cuboid must be less than
    //    or equal to those of the `prev` cuboid for stacking.
    bool canStack(vector<int>& curr, vector<int>& prev) {
        return prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2];
    }

    // 🔄 Function to solve using space-optimized tabulation (bottom-up DP)
    // Algorithm:
    // 1️⃣ Sort each cuboid to ensure width ≤ depth ≤ height for proper stacking.
    // 2️⃣ Use dynamic programming to calculate the maximum stack height.
    // 3️⃣ Iterate from the last cuboid to the first and check if it can be placed on
    //     the previous cuboid.
    // 4️⃣ For each cuboid, we either include it in the stack (and add its height) or
    //     exclude it.
    // 5️⃣ The result is stored in `nextRow`, representing the max height at each index.
    int solveUsingTabSO(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<int> currRow(n + 1, 0); // Current row for DP
        vector<int> nextRow(n + 1, 0); // Next row for DP

        // Iterate through all cuboids in reverse order
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                int include = 0, exclude = 0; // Initialize choices

                // Check if current cuboid can be placed on previous one
                if (prevIndex == -1 || canStack(cuboids[currIndex], cuboids[prevIndex])) {
                    int heightToAdd = cuboids[currIndex][2]; // Add current cuboid's height
                    include = heightToAdd + nextRow[currIndex + 1]; // Include current cuboid
                }
                exclude = nextRow[prevIndex + 1]; // Exclude current cuboid
                
                // Take the maximum of including or excluding the cuboid
                currRow[prevIndex + 1] = max(include, exclude);
            }
            nextRow = currRow; // Move to the next row for next iteration
        }
        return nextRow[0]; // Return the maximum height for stacking
    }

    // 📏 Main function to compute the maximum height for stacked cuboids
    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort each cuboid to ensure width ≤ depth ≤ height for proper stacking
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        // Sort all cuboids based on their dimensions to ensure correct stacking order
        sort(cuboids.begin(), cuboids.end());

        // Call the space-optimized DP function to get the result
        return solveUsingTabSO(cuboids);
    }
};

// 🏁 Main function for testing the solution
int main() {
    Solution solution;

    // 🧪 Example test case: Find the maximum stack height
    vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}}; // Input cuboids
    int maxHeight = solution.maxHeight(cuboids); // Calculate maximum height

    // 📜 Output the maximum stack height
    cout << "Maximum Stack Height: " << maxHeight << endl; // Display result

    return 0; // Indicate that the program ended successfully
}

/*
⏳ Time Complexity:
- O(n^2) due to the double loop that checks all cuboids with respect to each other for stacking.
- O(n log n) for sorting the cuboids based on their dimensions.

💾 Space Complexity:
- O(n) for storing the DP array `currRow` and `nextRow`.

📊 Example Output:
If the input cuboids are {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}}, the output will be:
Maximum Stack Height: 190

Explanation:
1. After sorting the cuboids, the optimal stack consists of all three cuboids.
2. The maximum height is 190 (i.e., the sum of heights of all stacked cuboids).
*/
