#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        // Create mapping
        char start = 'a';
        char mapping[256] = {0}; // Use 256 to cover all possible char values

        for (auto ch : key) {
            //No need to map  for" " and 
            //no need to do repetitive insert to same character for that mapping[ch] == 0
            if (ch != ' ' && mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }

        // Use mapping
        string ans;
        for (auto ch : message) {
            if (ch == ' ') {
                ans.push_back(' ');
            } else {
                char decodedChar = mapping[ch];
                ans.push_back(decodedChar);
            }
        }

        return ans;
    }
};

void runTest(string key, string message, string expected) {
    Solution solution;
    string result = solution.decodeMessage(key, message);
    cout << "Message: " << message << endl;
    cout << "Decoded: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << (result == expected ? "PASS" : "FAIL") << endl;
    cout << "--------------------------" << endl;
}

int main() {
    runTest("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv", "this is a secret");
    runTest("eljuxhpwnyrdgtqkviszcfmabo", "zwx hnfx lqantp mnoeius ycgk vcnjrdb", "the five boxing wizards jump quickly");
    runTest("abcdefghijklmnopqrstuvwxyz", "gsv jfrxp yildm ulc qfnkh levi gsv ozab wlt", "the quick brown fox jumps over the lazy dog");
    runTest("qwertyuiopasdfghjklzxcvbnm", "itssg vgksr", "hello world");
    runTest("xoyqmcgrukswaflnthdjpzibev", "khoor zruog", "hello world");

    return 0;
}

/* TEST CASES
    Message: vkbs bs t suepuv
    Decoded: this is a secret
    Expected: this is a secret
    PASS    
    --------------------------
    Message: zwx hnfx lqantp mnoeius ycgk vcnjrdb
    Decoded: the five boxing wizards jump quickly
    Expected: the five boxing wizards jump quickly
    PASS
    --------------------------
    Message: gsv jfrxp yildm ulc qfnkh levi gsv ozab wlt
    Decoded: gsv jfrxp yildm ulc qfnkh levi gsv ozab wlt
    Expected: the quick brown fox jumps over the lazy dog
    FAIL
    --------------------------
    Message: itssg vgksr
    Decoded: hello world
    Expected: hello world
    PASS
    --------------------------
    Message: khoor zruog
    Decoded: jrbbh vhibg
    Expected: hello world
    FAIL
    --------------------------
*/