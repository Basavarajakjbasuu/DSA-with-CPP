#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    // Helper function to recursively find the minimum number of perfect squares
    int numSquaresHelper(int n) {
        // BASE CASE: If n is zero, we have no more perfect squares to subtract
        if (n == 0) return 1;

        // Initialize variables
        int i = 1;
        int ans = INT_MAX; // Start with a large value for comparison
        int end = sqrt(n); // We only need to check perfect squares up to sqrt(n)
        
        // Iterate through all possible perfect squares <= n
        while (i <= end) {
            int perfectSquare = i * i; // Calculate the perfect square (i^2)
            // Recursively find the number of perfect squares required for the remaining value
            int numberOfPerfectSquares = 1 + numSquaresHelper(n - perfectSquare);

            // Update ans if we find a smaller number of perfect squares
            if (numberOfPerfectSquares < ans) 
                ans = numberOfPerfectSquares;
            
            ++i; // Move to the next perfect square
        }

        return ans; // Return the minimum number of perfect squares
    }

    // Main function to calculate the minimum number of perfect squares
    int numSquares(int n) {
        // Subtract 1 from the helper's return because we added 1 for base case
        return numSquaresHelper(n) - 1;
    }
};

int main() {
    Solution solution;
    int n;
    
    // Input the value for which we want to calculate the number of perfect squares
    cout << "Enter a number: ";
    cin >> n;
    
    // Output the minimum number of perfect squares required to sum up to n
    cout << "Minimum number of perfect squares for " << n << " is: " << solution.numSquares(n) << endl;
    
    return 0;
}

/* TEST CASES
  1. Enter a number: 12
     Minimum number of perfect squares for 12 is: 3
  2. Enter a number: 16
     Minimum number of perfect squares for 16 is: 1
  3. Enter a number: 17
     Minimum number of perfect squares for 17 is: 2  
*/
