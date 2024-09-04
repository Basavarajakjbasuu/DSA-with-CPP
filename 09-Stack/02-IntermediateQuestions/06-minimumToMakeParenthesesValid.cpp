#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    // Function to find the minimum number of parentheses to add to make the string valid.
    // Time Complexity: O(n), where n is the length of the string `s`.
    // Space Complexity: O(n), due to the stack used for tracking unmatched '('.
    int minAddToMakeValid(string s) {
        stack<char> st;  // Stack to keep track of unmatched '('
        int unmatchedClose = 0;  // Counter for unmatched ')'

        // Traverse each character in the string
        for (auto ch : s) {
            if (ch == '(') {
                // Push opening brackets onto the stack
                st.push(ch);
            } else {
                // If current character is ')'
                if (!st.empty() && st.top() == '(') {
                    // If there is a matching '(' in the stack, pop it
                    st.pop();
                } else {
                    // No matching '(', increment unmatched close counter
                    unmatchedClose++;
                }
            }
        }

        // Total unmatched parentheses = unmatched close + unmatched open
        return unmatchedClose + st.size();
    }
};

// Sample usage (not part of the Solution class)
int main() {
    Solution sol;
    string s = "())"; // Example input
    int result = sol.minAddToMakeValid(s);

    cout << "Minimum number of parentheses to add: " << result << endl;

    return 0;
}

/*1.
  "()))((";
  Minimum number of parentheses to add: 4
  2.
  "())"; 
  Minimum number of parentheses to add: 1
*/