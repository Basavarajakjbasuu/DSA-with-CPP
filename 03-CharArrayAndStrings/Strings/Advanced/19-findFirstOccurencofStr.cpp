#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(); // Size of the haystack (main string)
        int m = needle.size();   // Size of the needle (substring to search)

        // Loop through the haystack up to the point where the needle can fit
        for (int i = 0; i <= n - m; i++) {
            // Check if the substring starting at position 'i' matches the needle
            for (int j = 0; j < m; j++) {
                // If any character doesn't match, break out of the inner loop
                if (needle[j] != haystack[i + j]) {
                    break;
                }

                // If we have compared all characters and they match, return the start index
                if (j == m - 1)
                    return i;
            }
        }

        // If no match is found, return -1
        return -1;
    }
};

int main() {
    Solution solution;

    // Example usage:
    string haystack = "hello";
    string needle = "ll";

    int result = solution.strStr(haystack, needle);

    if (result != -1) {
        cout << "Needle found at index: " << result << endl;
    } else {
        cout << "Needle not found." << endl;
    }

    return 0;
}

/** TEST CASES
 * 1. string haystack = "hello";
 *    string needle = "ll";
 *    Needle found at index: 2
 */