#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    // Function to decode a string with encoded patterns like "3[a2[c]]".
    string decodeString(string encodedStr) {
        stack<string> stringStack;  // Stack to store substrings and numbers.

        for (char currentChar : encodedStr) {

            if (currentChar == ']') {
                string substringToRepeat = "";

                // Pop characters until we find the '['
                while (!stringStack.empty() && stringStack.top() != "[") {
                    substringToRepeat = stringStack.top() + substringToRepeat;
                    stringStack.pop();
                }
                stringStack.pop();  // Remove the '[' from the stack.

                string numberString = "";

                // Pop numbers and form the complete number string.
                while (!stringStack.empty() && isdigit(stringStack.top()[0])) {
                    numberString = stringStack.top() + numberString;
                    stringStack.pop();
                }
                
                int repeatCount = stoi(numberString);  // Convert the number string to integer.

                string decodedSubstring = "";

                // Repeat the substring 'repeatCount' times.
                while (repeatCount--) {
                    decodedSubstring = substringToRepeat + decodedSubstring;
                }

                stringStack.push(decodedSubstring);  // Push the decoded substring back onto the stack.

            } else {
                // Push individual characters onto the stack.
                stringStack.push(string(1, currentChar));
            }
        }

        string finalDecodedString = "";

        // Combine all substrings in the stack to form the final decoded string.
        while (!stringStack.empty()) {
            finalDecodedString = stringStack.top() + finalDecodedString;
            stringStack.pop();
        }

        return finalDecodedString;
    }
};

// Main function to test the Solution class.
int main() {
    Solution sol;

    string testStr = "3[a2[c]]";  // Example input
    cout << "Decoded string: " << sol.decodeString(testStr) << endl;

    return 0;
}

/*
Time Complexity: O(n)
- We iterate through each character in the string once, where n is the length of the input string.
- Each character is pushed and popped from the stack at most once.

Space Complexity: O(n)
- The stack can hold up to n characters in the worst case, where n is the length of the input string.
- This space is used to store substrings and numbers during processing.

Example:
For the input string "3[a2[c]]", the output will be "accaccacc".
*/
