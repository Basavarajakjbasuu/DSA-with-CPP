#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
  Write a function to find the longest common prefix string amongst an array of strings.

  If there is no common prefix, return an empty string "".

  Example 1:

  Input: strs = ["flower","flow","flight"]
  Output: "fl"
  Example 2:

  Input: strs = ["dog","racecar","car"]
  Output: ""
  Explanation: There is no common prefix among the input strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i = 0;
        while (true) {
            char currentChar = 0;
            for (auto str : strs) {

                if (i >= str.size()) {
                    // Out of bounds
                    currentChar = 0;
                    break;
                }

                // Just traversing
                if (currentChar == 0) {
                    currentChar = str[i];
                } else if (str[i] != currentChar) {
                    currentChar = 0;
                    break;
                }
            }

            if (currentChar == 0)
                break;

            ans.push_back(currentChar);
            i++;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    // vector<string> strs = {"flower", "flow", "flight"};
    vector<string> strs = {"dog","racecar","car"};
    string result = solution.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}

/*
  Longest Common Prefix: fl

  Longest Common Prefix: 
*/