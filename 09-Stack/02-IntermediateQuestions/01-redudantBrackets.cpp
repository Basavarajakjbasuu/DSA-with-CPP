#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    // Function to check if there are any redundant parentheses in the expression.
    // Time Complexity: O(n), where n is the length of the string `s`.
    // Space Complexity: O(n), due to the stack usage.
    int checkRedundancy(string s) {
        stack<char> st;  // Stack to hold operators and parentheses

        // Traverse the input string
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];  // Current character

            // If the character is an opening parenthesis or an operator, push it onto the stack
            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                st.push(ch);
            } else if (ch == ')') {  // If the character is a closing parenthesis
                
                int operatorCount = 0;

                // Pop elements from the stack until an opening parenthesis is found
                while (!st.empty() && st.top() != '(') {
                    char temp = st.top();

                    // Check if the popped element is an operator
                    if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                        operatorCount++;
                    }

                    st.pop();
                }

                // Pop the opening parenthesis '('
                st.pop();

                // If no operators were found between the parentheses, then the parentheses are redundant
                if (operatorCount == 0) {
                    return true;
                }
            }
        }

        // Return false if no redundancy is found
        return false;
    }
};

// Sample usage (not part of the Solution class)
int main() {
    Solution sol;
    string expression = "(a+b+(c+d))";  // Example: contains redundant parentheses
    bool result = sol.checkRedundancy(expression);

    if (result) {
        cout << "Redundant parentheses found." << endl;
    } else {
        cout << "No redundant parentheses." << endl;
    }

    return 0;
}

/*1.string expression = "((a+b))"; 
  Redundant parentheses found.

  2.string expression = "(a+b+(c+d))";
  No redundant parentheses.

*/