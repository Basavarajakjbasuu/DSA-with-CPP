#include <iostream>

using namespace std;

class Solution {
public:
    // Function to calculate the number of ways to climb 'n' stairs
    int climbStairs(int n) {
        // BASE CASE: If there are no stairs, there's only 1 way to stay at the ground
        if (n == 0) {
            return 1;
        }

        // BASE CASE: If there is 1 stair, there's only 1 way to climb it
        if (n == 1) {
            return 1;
        }

        // RECURSIVE STEP: The number of ways to climb 'n' stairs is the sum of the ways
        // to climb 'n-1' stairs and 'n-2' stairs
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main() {
    Solution solution;

    // Example input
    int n = 13;  // Number of stairs

    // Calculate and print the number of ways to climb 'n' stairs
    cout << "Number of ways to climb " << n << " stairs: " << solution.climbStairs(n) << endl;

    return 0;
}

/** TEST CASES
 * 1.  int n = 5;
 *    Number of ways to climb 5 stairs: 8
 * 2. int n = 3;
 *    Number of ways to climb 3 stairs: 3
 * 3. int n = 13
 *    Number of ways to climb 13 stairs: 377
 */