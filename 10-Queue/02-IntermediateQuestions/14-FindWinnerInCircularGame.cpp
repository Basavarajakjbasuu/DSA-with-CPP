#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    // 🚀 Iterative solution using a queue (Josephus problem simulation)
    int findTheWinnerIterative(int n, int k) {
        queue<int> q;

        // 🎯 Fill the queue with friends numbered from 1 to n
        for (int i = 1; i <= n; i++) 
            q.push(i);

        // 🔄 Eliminate every k-th friend until one is left
        while (q.size() > 1) {
            for (int i = 1; i < k; i++) {
                int front = q.front();
                q.pop();
                q.push(front); // 🚶 Move friend to the back
            }
            q.pop(); // 💥 Eliminate the k-th friend
        }

        // 🏆 The last remaining friend is the winner
        return q.front();
    }

    // 🧠 Recursive solution (Josephus problem)
    int findTheWinnerRecursive(int n, int k) {
        // 🛑 Base case: If only one person is left, they are the winner
        if (n == 1) return 1;

        // 🔄 Recursively reduce the number of friends
        return (findTheWinnerRecursive(n - 1, k) + k - 1) % n + 1;
    }
};

// 🚀 Main function for local execution
int main() {
    Solution solution;

    // 🧪 Test cases
    int n1 = 5, k1 = 2;
    int n2 = 6, k2 = 5;

    // 🏆 Test iterative solution
    cout << "Iterative solution:" << endl;
    cout << "Winner for n = " << n1 << ", k = " << k1 << ": " << solution.findTheWinnerIterative(n1, k1) << endl; // 📥 Should return 3
    cout << "Winner for n = " << n2 << ", k = " << k2 << ": " << solution.findTheWinnerIterative(n2, k2) << endl; // 📥 Should return 1

    // 🧠 Test recursive solution
    cout << "Recursive solution:" << endl;
    cout << "Winner for n = " << n1 << ", k = " << k1 << ": " << solution.findTheWinnerRecursive(n1, k1) << endl; // 📥 Should return 3
    cout << "Winner for n = " << n2 << ", k = " << k2 << ": " << solution.findTheWinnerRecursive(n2, k2) << endl; // 📥 Should return 1

    return 0;
}

/*
⏳ Time Complexity:
- Iterative solution: O(n * k), where n is the number of friends and k is the step size for elimination.
- Recursive solution: O(n), where n is the number of friends due to the recursion stack.

💾 Space Complexity:
- Iterative solution: O(n) due to the queue.
- Recursive solution: O(n) due to the recursion stack.

📊 Example Output:
Iterative solution:
Winner for n = 5, k = 2: 3
Winner for n = 6, k = 5: 1

Recursive solution:
Winner for n = 5, k = 2: 3
Winner for n = 6, k = 5: 1
*/
