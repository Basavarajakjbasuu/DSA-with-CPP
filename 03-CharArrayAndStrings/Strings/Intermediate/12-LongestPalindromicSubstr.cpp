#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string ans = "";
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (isPalindrome(s, i, j)) {
                    string t = s.substr(i, j - i + 1);
                    ans = t.size() > ans.size() ? t : ans;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = solution.longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}

/* TEST CASES
  1. Enter a string: babad
     Longest Palindromic Substring: bab
  2. Enter a string: cbbd
     Longest Palindromic Substring: bb
*/