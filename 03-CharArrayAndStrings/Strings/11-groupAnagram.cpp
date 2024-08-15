#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        for (auto str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> result = solution.groupAnagrams(strs);
    
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

/* TEST CASES
  1.vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Grouped Anagrams:
    [ bat ]
    [ eat tea ate ]
    [ tan nat ]
*/