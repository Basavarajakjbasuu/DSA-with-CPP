#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroidStack;

        // 🚀 Iterate through each asteroid in the input vector
        for (int currentAsteroid : asteroids) {
            bool isDestroyed = false;

            // 👉 If the current asteroid is moving right (positive), push it onto the stack
            if (currentAsteroid > 0) {
                asteroidStack.push(currentAsteroid);
            } else {
                // 💥 Handle collision cases when the current asteroid is moving left (negative)

                // 💥💥 While there are positive asteroids on the stack, simulate collisions
                while (!asteroidStack.empty() && asteroidStack.top() > 0) {
                    // 🔄 Check if the current left-moving asteroid and top right-moving asteroid have the same size
                    if (abs(currentAsteroid) == asteroidStack.top()) {
                        isDestroyed = true;
                        asteroidStack.pop();  // ❌ Both asteroids are destroyed
                        break;
                    } 
                    // 🔼 If the current left-moving asteroid is larger, destroy the top right-moving asteroid
                    else if (abs(currentAsteroid) > asteroidStack.top()) {
                        asteroidStack.pop();
                    } 
                    // 🔽 If the top right-moving asteroid is larger, the current asteroid is destroyed
                    else {
                        isDestroyed = true;
                        break;
                    }
                }

                // ✔️ If the current asteroid wasn't destroyed in a collision, push it onto the stack
                if (!isDestroyed) {
                    asteroidStack.push(currentAsteroid);
                }
            }
        }

        // 🔄 Transfer stack contents to the result vector in reverse order
        vector<int> result(asteroidStack.size());
        for (int i = asteroidStack.size() - 1; i >= 0; i--) {
            result[i] = asteroidStack.top();
            asteroidStack.pop();
        }

        return result;
    }
};

int main() {
    Solution solution;

    // 🧪 Example test case
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = solution.asteroidCollision(asteroids);

    // 📤 Output the resulting state of asteroids after collisions
    cout << "Resulting asteroids: ";
    for (int ast : result) {
        cout << ast << " ";
    }
    cout << endl;

    return 0;
}

/*
⏳ Time Complexity:
- The time complexity is O(n), where n is the number of asteroids. Each asteroid is pushed and popped from the stack at most once.

💾 Space Complexity:
- The space complexity is O(n), where n is the number of asteroids. In the worst case, all asteroids could be stored in the stack.

📊 Example Output:
Resulting asteroids: 5 10
*/
