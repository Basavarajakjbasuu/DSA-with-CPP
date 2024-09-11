#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Function to check if the given string is valid based on the given rules.
    bool isValid(string str) {
        // If the first character is not 'a', the string cannot be valid.
        if (str[0] != 'a') return false;

        stack<char> charStack;  // Stack to track 'a' and 'b' characters.

        // Iterate over each character in the string.
        for (char currentChar : str) {

            // If the current character is 'a', push it onto the stack.
            if (currentChar == 'a') {
                charStack.push(currentChar);

            // If the current character is 'b', check if the top of the stack is 'a'.
            } else if (currentChar == 'b') {
                if (!charStack.empty() && charStack.top() == 'a') {
                    charStack.push(currentChar);
                } else {
                    return false;  // Invalid sequence.
                }

            // If the current character is 'c', check if the top of the stack is 'b'.
            } else {
                // The character is 'c', so check if the top is 'b'.
                if (!charStack.empty() && charStack.top() == 'b') {
                    charStack.pop();  // Remove 'b'.

                    // Now check if the next top of the stack is 'a'.
                    if (!charStack.empty() && charStack.top() == 'a') {
                        charStack.pop();  // Remove 'a'.
                    } else {
                        return false;  // Invalid sequence.
                    }
                } else {
                    return false;  // Invalid sequence.
                }
            }
        }

        // If the stack is empty, the string is valid.
        return charStack.empty();
    }
};

// Main function to test the Solution class.
int main() {
    Solution sol;

    string testStr = "aabcbc";  // Example input
    if (sol.isValid(testStr)) {
        cout << "The string is valid.\n";
    } else {
        cout << "The string is invalid.\n";
    }

    return 0;
}

/*
Time Complexity: O(n)
- We iterate through the string once, performing constant time operations for each character.
- n is the length of the input string.

Space Complexity: O(n)
- In the worst case, the stack could hold up to n characters if the string consists of alternating 'a' and 'b'.

Example output for the string "aabcbc":
The string is valid.
*/
