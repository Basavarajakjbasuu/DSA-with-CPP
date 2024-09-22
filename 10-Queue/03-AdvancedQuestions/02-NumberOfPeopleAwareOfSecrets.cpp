#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 📝 Algorithm:
    // 1. Initialize two queues: `forgetQ` to track people who will forget the secret and `delayQ` to track people who can start sharing the secret after a delay.
    // 2. For each day from 1 to `n`:
    //    - Remove people who forget the secret after the `forget` duration.
    //    - Add people who can start sharing the secret after the `delay` duration.
    //    - Update the total number of people aware of the secret.
    // 3. Return the total number of people who still remember the secret after `n` days.
    
    // Time Complexity:
    // - O(n) where `n` is the number of days.
    
    // Space Complexity:
    // - O(n) due to the use of two queues.
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int M = 1e9 + 7;  // Modulo value
        int cur = 0;  // Tracks the current number of people sharing the secret
        int ans = 1;  // Initial number of people aware of the secret
        queue<pair<int, int>> forgetQ, delayQ;  // Queues for tracking forget and delay times
        
        forgetQ.push({1, 1});  // Day 1: one person will forget after `forget` days
        delayQ.push({1, 1});   // Day 1: one person can start sharing after `delay` days

        for (int i = 1; i <= n; i++) {
            // 🧠 Remove people who forget the secret
            if (!forgetQ.empty() && forgetQ.front().first + forget <= i) {
                auto front = forgetQ.front();
                forgetQ.pop();
                auto no = front.second;
                ans = (ans - no + M) % M;  // Update the total number of people aware
                cur = (cur - no + M) % M;  // Update the number of current sharers
            }

            // ⏳ Add people who can start sharing the secret
            if (!delayQ.empty() && delayQ.front().first + delay <= i) {
                auto front = delayQ.front();
                delayQ.pop();
                cur = (cur + front.second) % M;  // Update the number of current sharers
            }

            // 📈 Add current sharers to the result
            if (cur > 0) {
                ans = (ans + cur) % M;
                forgetQ.push({i, cur});  // People will forget after `forget` days
                delayQ.push({i, cur});   // People will start sharing after `delay` days
            }
        }
        return ans;  // Return total people aware of the secret
    }
};

// Sample usage (for local execution)
int main() {
    Solution sol;
    int n = 6, delay = 2, forget = 4;
    cout << "People aware of the secret after " << n << " days: " << sol.peopleAwareOfSecret(n, delay, forget) << endl;
    return 0;
}

/*
Sample Output:
People aware of the secret after 6 days: 5
*/
