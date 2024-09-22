#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /*
      * 🧠 Algorithm Explanation:
      * 1. We traverse the cars in reverse order, maintaining a stack of cars being processed.
      * 2. For each car, we pop slower cars from the stack (cars that will never collide with the current one).
      * 3. We calculate the time it would take for the current car to collide with the next car in the stack.
      * 4. We ensure the collision time is valid by checking if it occurs before the next car collides.
      * 5. The result for each car is stored in the `collisionTimes` vector.
    */
    // 🏎️ Function to calculate the time at which each car will collide with the next car.
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> collisionTimes(n, -1);  // ⏳ Initialize collision times with -1 (no collision initially)
        stack<int> st;  // 🗂️ Stack to keep track of cars being processed

        // 🚗 Traverse cars in reverse (starting from the last car)
        for (int i = n - 1; i >= 0; i--) {
            // 🗑️ Remove slower cars from the stack
            while (!st.empty() && cars[st.top()][1] >= cars[i][1]) {
                st.pop();
            }

            // 🕒 Calculate the collision time for car i with the next car in the stack
            while (!st.empty()) {
                double colTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
                
                // 🚧 Ensure the collision time is valid (before the next car collides)
                if (collisionTimes[st.top()] == -1 || colTime <= collisionTimes[st.top()]) {
                    collisionTimes[i] = colTime;
                    break;
                }

                st.pop(); // 🚗💨 Pop the car that would collide later
            }

            // 🆕 Push the current car onto the stack for future comparisons
            st.push(i);
        }

        return collisionTimes;
    }
};

// 🎯 Main function for local execution
int main() {
    Solution solution;

    // 🚗 Test Case: Each car represented by [position, speed]
    vector<vector<int>> cars = {{3, 4}, {5, 4}, {6, 3}, {9, 2}};

    // 🏎️ Get collision times for each car
    vector<double> result = solution.getCollisionTimes(cars);

    // 📊 Print the collision times
    for (double time : result) {
        cout << time << " ";
    }
    cout << endl;

    return 0;
}

/**
 * 📈 Time Complexity: O(n), where n is the number of cars.
 * - Each car is pushed and popped from the stack at most once.
 *
 * 🧠 Space Complexity: O(n), for storing the stack and collision times.
 * 
 * output: 3 1 3 -1
 */

