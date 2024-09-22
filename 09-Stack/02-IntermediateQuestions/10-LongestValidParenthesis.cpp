#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    /*
      📝 Algorithm:
    1. Initialize a stack `st` with -1 to handle edge cases like the first valid parenthesis.
    2. Traverse the string `s` character by character:
        - If the character is '(', push its index onto the stack.
        - If the character is ')', pop the top of the stack.
          a. If the stack is empty after popping, push the current index.
          b. If the stack is not empty, calculate the length of the valid parentheses substring as `i - st.top()`. Update `maxLen` if this is the largest.
    3. Return the value of `maxLen`.
    */
    // 🧩 Function to find the longest valid parentheses substring
    int longestValidParentheses(string s) {
        stack<int> st;  // 🗂️ Stack to store indices of parentheses
        st.push(-1);    // 🔢 Push -1 to handle edge cases (when a valid substring starts from index 0)

        int maxLen = 0; // 📏 To track the maximum length of valid parentheses
        
        // 🚶 Traverse through the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);  // 🟢 Push the index of '(' onto the stack
            } else {
                st.pop();    // 🔴 Pop the top when encountering a ')'

                if (st.empty()) {
                    st.push(i);  // ⛔ If stack is empty, push the current index (to handle invalid substrings)
                } else {
                    maxLen = max(maxLen, i - st.top());  // 📏 Calculate the length of valid substring
                }
            }
        }

        return maxLen;  // 📏 Return the maximum length of valid parentheses
    }
};

// 🎯 Main function for local execution
int main() {
    Solution solution;

    string s = "(()))())(";  // Example test case
    cout << "Longest valid parentheses: " << solution.longestValidParentheses(s) << endl;

    return 0;
}

/**

 *
 * 📈 Time Complexity: O(n), where n is the length of the string.
 * - We traverse the string once, pushing and popping from the stack in constant time.
 *
 * 🧠 Space Complexity: O(n), for the stack used to store indices.
 * 
 * output: Longest valid parentheses: 4
 */
