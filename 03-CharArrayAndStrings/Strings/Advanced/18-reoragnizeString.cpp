#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};
        
        // Count frequencies of each character
        for (char c : s) {
            hash[c - 'a']++;
        }
        
        // Find the most frequent character
        int maxFrequency = 0;
        char maxFreqChar = 0;
        for (int i = 0; i < 26; i++) {
            if (hash[i] > maxFrequency) {
                maxFrequency = hash[i];
                maxFreqChar = i + 'a';
            }
        }
        
        // If the most frequent character exceeds the allowed frequency, return ""
        if (maxFrequency > (s.size() + 1) / 2) {
            return "";
        }
        
        // Place the most frequent character in even indices
        string result(s.size(), ' ');
        int index = 0;
        while (maxFrequency > 0) {
            result[index] = maxFreqChar;
            index += 2;
            maxFrequency--;
        }
        
        // Place the remaining characters
        for (int i = 0; i < 26; i++) {
            while (hash[i] > 0) {
                if (index >= s.size()) {
                    index = 1; // Switch to odd indices
                }
                result[index] = i + 'a';
                index += 2;
                hash[i]--;
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    string input = "aab";
    string output = solution.reorganizeString(input);
    cout << "Reorganized String: " << output << endl;
    return 0;
}

/**
 * 1.string input = "aab";
 *   Reorganized String: aba
 * 
 */