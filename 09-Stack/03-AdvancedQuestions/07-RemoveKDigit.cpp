#include <iostream>
#include <stack>
#include <algorithm> // For reverse
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        stack<char> st;

        // Traverse each digit in the number 💻
        for (auto digit : num) {

            // Remove elements from the stack while the top is larger than current digit and `k` is still positive ⬇️
            while (!st.empty() && st.top() > digit && k > 0) {
                st.pop();
                k--;
            }

            // Push the current digit onto the stack 🧱
            st.push(digit);
        }

        // If there are still digits to remove, pop remaining digits from the stack ⬇️
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        // Build the result string by reversing the stack 🔄
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        // Remove leading zeros 🚫0️⃣
        while (result.size() > 0 && result.back() == '0') {
            result.pop_back();
        }

        // Reverse the result to get the correct order 🔄
        reverse(result.begin(), result.end());

        // Return "0" if the result is empty 🆘
        return result.empty() ? "0" : result;
    }
};

// Function to run the code locally
int main() {
    Solution sol;

    string num = "1432219";  // Example input
    int k = 3;

    // Output the result
    cout << "Result after removing " << k << " digits: " << sol.removeKdigits(num, k) << endl;

    return 0;
}

/*
    Time Complexity: O(n)
    - We traverse the string `num` once (O(n)) and perform push/pop operations on the stack which are O(1).
    - Reversing the result string and removing leading zeros are also O(n) operations.

    Space Complexity: O(n)
    - We use a stack to store the digits, and in the worst case, we might push all `n` digits onto the stack.

    Output:
      Result after removing 3 digits: 1219
*/
