#include <iostream>
#include <stack>
#include <string>

using namespace std;


class Solution {
  public:
    // Function to check if brackets are balanced or not.
    // Time Complexity: O(n), where n is the length of the string `x`.
    // Space Complexity: O(n), because the worst case is all opening brackets being pushed onto the stack.
    bool isValidParentheses(string x) {
        stack<char> st;  // Stack to keep track of opening brackets
        
        // Traverse through each character of the input string
        for (int i = 0; i < x.length(); i++) {
            char ch = x[i];  // Current character
            
            // If the character is an opening bracket, push it onto the stack
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);   
            } else {  // If the character is a closing bracket
                
                // If the stack is not empty, check for matching brackets
                if (!st.empty()) {
                    // Check if the top of the stack matches with the current closing bracket
                    if (st.top() == '(' && ch == ')') {
                        st.pop();
                    } else if (st.top() == '[' && ch == ']') {
                        st.pop();
                    } else if (st.top() == '{' && ch == '}') {
                        st.pop();
                    } else {
                        return false;  // Mismatched bracket found
                    }
                } else {
                    return false;  // Closing bracket encountered without a corresponding opening bracket
                }
            }
        }
        
        // If the stack is empty, all brackets were matched, otherwise, unbalanced
        return st.empty();
    }
};

// Sample usage (not part of the Solution class)
int main() {
    Solution sol;
    string input = "{[()]}";  // Example: balanced string
    bool result = sol.isValidParentheses(input);
    
    if (result) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    
    return 0;
}

/*1.
  string input = "{[()]}";
  Balanced

 */