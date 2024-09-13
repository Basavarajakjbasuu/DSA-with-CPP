#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string answer;
        stack<char> st;

        // 🚀 Iterate through each digit in the input string
        for (auto digit : num) {
            // 🔄 Remove larger digits from the stack if k > 0
            while (!st.empty() && st.top() > digit && k > 0) {
                st.pop();  // ❌ Pop the larger digit
                k--;       // ⬇️ Decrease k since we removed one digit
            }
            st.push(digit);  // 👉 Push the current digit onto the stack
        }

        // 🚨 If there are still digits left to remove (k > 0)
        while (k > 0 && !st.empty()) {
            st.pop();  // ❌ Remove extra digits
            k--;
        }

        // 📦 Build the final answer string from the stack
        while (!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }

        // 🧹 Remove leading zeros
        while (answer.size() > 0 && answer.back() == '0') {
            answer.pop_back();
        }

        reverse(answer.begin(), answer.end());  // 🔄 Reverse the string to correct order

        // 🏁 Return the result, or "0" if the answer is empty
        return answer.empty() ? "0" : answer;
    }
};

// 👨‍💻 Main function for testing the code locally
int main() {
    Solution solution;

    // 🧪 Example test case
    string num = "1432219";
    int k = 3;
    string result = solution.removeKdigits(num, k);

    // 📤 Output the result after removing k digits
    cout << "Resulting number: " << result << endl;

    return 0;
}

/*
⏳ Time Complexity:
- The time complexity is O(n), where n is the number of digits in the input string. Each digit is pushed and popped from the stack at most once.

💾 Space Complexity:
- The space complexity is O(n), where n is the number of digits in the input string, as we use a stack to store the digits.

📊 Example Output:
Resulting number: 1219
*/
