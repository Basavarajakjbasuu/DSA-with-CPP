#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Custom comparator function to determine the order of strings
    // We compare concatenated results of a+b and b+a to decide the order
    static bool myComp(string a, string b) {
        string t1 = a + b; // Concatenate a followed by b
        string t2 = b + a; // Concatenate b followed by a
        return t1 > t2;    // Return true if t1 is greater, ensuring a should come before b
    }

    // Function to create the largest possible number from an array of integers
    string largestNumber(vector<int>& nums) {
        vector<string> strs; // Vector to store the numbers as strings
        
        // Convert each integer to a string and store it in the vector
        for(auto n: nums) {
            strs.push_back(to_string(n));
        }

        // Sort the vector of strings using the custom comparator function
        sort(strs.begin(), strs.end(), myComp);

        // If the largest number is "0", return "0" (this handles cases like [0, 0])
        if(strs[0] == "0") 
            return "0";
        
        // Concatenate all strings in the sorted vector to form the largest number
        string ans = "";
        for(auto str: strs) {
            ans += str;
        }

        return ans; // Return the final concatenated string as the result
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Example input
    vector<int> nums = {3, 30, 34, 5, 9};

    // Call the largestNumber function and print the result
    cout << "The largest number is: " << solution.largestNumber(nums) << endl;

    return 0;
}

/** TEST CASES
 *  1.vector<int> nums = {3, 30, 34, 5, 9}; 
 *    The largest number is: 9534330
 */