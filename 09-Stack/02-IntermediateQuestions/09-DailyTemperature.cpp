#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Initialize the answer vector with zeros for each day's wait time 🕰️
        vector<int> daysUntilWarmer(temperatures.size(), 0);
        stack<int> indexStack;  // Stack to store the indices of temperatures ❄️🌡️

        // Traverse each day's temperature 📅
        for (int currentDay = 0; currentDay < temperatures.size(); ++currentDay) {
            
            // Check if the current day's temperature is warmer than the day at the top of the stack ☀️
            while (!indexStack.empty() && temperatures[currentDay] > temperatures[indexStack.top()]) {
                int previousDay = indexStack.top();  // Get the day with a cooler temperature 🌡️
                indexStack.pop();
                
                // Calculate the difference in days for warmer temperature ⏳
                daysUntilWarmer[previousDay] = currentDay - previousDay;
            }

            // Push the current day's index to the stack for future comparisons 📥
            indexStack.push(currentDay);
        }

        return daysUntilWarmer;
    }
};


// Function to run the code locally
int main() {
    Solution sol;

    // Sample input: temperatures for a week
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    // Get the result of the daily temperature calculation
    vector<int> result = sol.dailyTemperatures(temperatures);

    // Output the result to the console
    cout << "Days to wait for a warmer temperature: ";
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}

/*
    Time Complexity: O(n) 
    - Each element is pushed and popped from the stack at most once.
    - The loop runs once through the temperatures array (n elements), so the overall complexity is O(n).

    Space Complexity: O(n)
    - We use a stack to store indices, and in the worst case, we could push all indices into the stack.
    - The answer array also takes O(n) space.

    Output:
      Days to wait for a warmer temperature: 1 1 4 2 1 1 0 0 
*/
