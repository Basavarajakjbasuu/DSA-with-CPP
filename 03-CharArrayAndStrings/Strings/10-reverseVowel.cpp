#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        int low = 0, high = s.size() - 1;

        while (low < high) {
            if (isVowel(s[low]) && isVowel(s[high])) {
                swap(s[low], s[high]);
                low++;
                high--;
            } else if (!isVowel(s[low])) { 
                low++;
            } else {
                high--;
            }
        }

        return s;
    }
};

int main() {
    Solution solution;
    string s = "hello";
    cout << solution.reverseVowels(s) << endl;  // Output: "holle"

    s = "leetcode";
    cout << solution.reverseVowels(s) << endl;  // Output: "leotcede"

    return 0;
}
