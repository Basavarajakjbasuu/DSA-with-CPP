#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to build the simplified path from stack.
    void buildSimplifiedPath(stack<string>& directoryStack, string& resultPath) {
        if (directoryStack.empty()) return; // Base case: stack is empty.
        string currentDirectory = directoryStack.top();
        directoryStack.pop();
        buildSimplifiedPath(directoryStack, resultPath);
        resultPath += currentDirectory; // Append directories to result in correct order.
    }

    // Function to simplify the given Unix-style file path.
    string simplifyPath(string filePath) {
        stack<string> directoryStack; // Stack to store valid directory parts.
        int index = 0;

        while (index < filePath.size()) {
            int start = index;  // Mark start of a directory part.
            int end = index + 1; // Look for the next '/' character.

            // Find the next part of the path (between '/' characters).
            while (end < filePath.size() && filePath[end] != '/') {
                ++end;
            }

            // Extract the current directory part from the string.
            string currentDirectory = filePath.substr(start, end - start);
            index = end; // Move index to the next part.

            if (currentDirectory == "/" || currentDirectory == "/.") {
                // Ignore single '/' or current directory symbol '/.'.
                continue;
            }

            if (currentDirectory == "/..") {
                // Go back one directory if we encounter '/..'.
                if (!directoryStack.empty()) {
                    directoryStack.pop();
                }
            } else {
                // Push valid directory parts onto the stack.
                directoryStack.push(currentDirectory);
            }
        }

        // Construct the final simplified path.
        string simplifiedPath = directoryStack.empty() ? "/" : "";

        // Build the result by popping from the stack.
        buildSimplifiedPath(directoryStack, simplifiedPath);

        return simplifiedPath;
    }
};

// Main function to test the Solution class.
int main() {
    Solution solution;

    // Test case 1
    string filePath1 = "/home/../usr//local/./bin/";
    cout << "Simplified Path 1: " << solution.simplifyPath(filePath1) << endl;

    // Test case 2
    string filePath2 = "/a/./b/../../c/";
    cout << "Simplified Path 2: " << solution.simplifyPath(filePath2) << endl;

    return 0;
}

/*
Time Complexity: O(n)
- We traverse each character in the input string once, where n is the length of the path.
- Each directory is pushed and popped from the stack once.

Space Complexity: O(n)
- We use a stack to store directories, which can hold at most n parts in the worst case.

Example Output:
For the input "/home/../usr//local/./bin/", the output will be "/usr/local/bin".
For the input "/a/./b/../../c/", the output will be "/c".
*/
