#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find if there are any two distinct pairs (a, b) and (c, d)
    // in the array such that a + b == c + d
    bool findPairs(vector<int>& arr) {
        // Hash map to store sums of pairs and whether they have been encountered
        unordered_map<int, bool> sumMap;

        // Traverse all pairs in the array
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                int currentSum = arr[i] + arr[j]; // Calculate sum of the pair

                // Check if this sum has been encountered before
                if (sumMap.find(currentSum) != sumMap.end()) {
                    return true; // If yes, return true as a pair with the same sum exists
                } else {
                    sumMap[currentSum] = true; // Otherwise, store this sum in the map
                }
            }
        }

        return false; // Return false if no such pairs were found
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5};

    // Call the function and print the result
    bool hasPairsWithEqualSum = solution.findPairs(arr);
    cout << (hasPairsWithEqualSum ? "Pairs with equal sum found." : "No pairs with equal sum.") << endl;

    return 0;
}

/*
⏳ Time Complexity:
- O(n^2), where n is the number of elements in the array. We are checking every pair of elements.

💾 Space Complexity:
- O(n), where n is the number of possible distinct sums. In the worst case, we store all the sums of pairs.

📊 Example Output:
- No pairs with equal sum.
*/
