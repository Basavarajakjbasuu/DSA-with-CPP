#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Two-pointer approach with a count vector to keep track of consecutive characters
        int i = 0, j = 0;
        int n = s.size();
        vector<int> count(n, 1);  // Vector to store counts of consecutive characters

        // Iterate through the string with j, and use i to build the final string
        while (j < n) {
            // Copy character from index j to index i
            s[i] = s[j];
            
            // Check if the current character matches the previous character
            if (i > 0 && s[i] == s[i - 1]) {
                // Increment the count for consecutive characters
                count[i] = count[i - 1] + 1;
            } else {
                // Reset the count to 1 if characters don't match
                count[i] = 1;
            }

            // If the count reaches k, remove the last k characters by moving i back
            if (count[i] == k) {
                i -= k;
            }

            // Increment both pointers
            ++i;
            ++j;
        }

        // Return the resulting string up to the valid index i
        return s.substr(0, i);
    }
};

int main() {
    Solution solution;

    // Example test case
    string s = "deeedbbcccbdaa";  // Input string
    int k = 3;  // Number of consecutive characters required for removal

    // Call the removeDuplicates function and store the result
    string result = solution.removeDuplicates(s, k);

    // Output the result
    cout << "Resulting string: " << result << endl;  // Expected output: "aa"

    return 0;
}

/** TEST CASES
 *  1.string s = "deeedbbcccbdaa"; 
 *    Resulting string: aa
 */