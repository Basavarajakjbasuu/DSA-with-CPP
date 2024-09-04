#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Function to calculate the minimum number of swaps required to balance brackets.
    // Time Complexity: O(n), where n is the length of the string `s`.
    // Space Complexity: O(1), as only a few extra variables are used.
    int minSwaps(string s) {
        int balance = 0;    // To track the balance of brackets (positive for '[' and negative for ']')
        int swapCount = 0;  // To count the number of swaps needed

        // Traverse the input string
        for (char ch : s) {
            if (ch == ']') {  // If the current character is a closing bracket
                if (balance == 0) {  // If there's no matching opening bracket
                    swapCount++;  // We need a swap to fix this
                    balance++;    // Adjust balance to account for the swap
                } else {
                    balance--;  // Decrease balance for a matching opening bracket
                }
            } else {  // If the current character is an opening bracket
                balance++;  // Increase balance
            }
        }

        return swapCount;  // Return the total number of swaps needed
    }
};

// Sample usage (not part of the Solution class)
int main() {
    Solution sol;
    string s = "]]][[[[";  // Example input
    int result = sol.minSwaps(s);

    cout << "Minimum number of swaps needed: " << result << endl;

    return 0;
}

/*
  string s = "]]][[[[";
  Minimum number of swaps needed: 2
*/