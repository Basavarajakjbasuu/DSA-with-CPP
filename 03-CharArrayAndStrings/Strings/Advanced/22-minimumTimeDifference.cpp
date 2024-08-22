#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Function to convert time in "HH:MM" format to minutes since midnight
    int convertToMins(string& time) {
        int hr = stoi(time.substr(0, 2)); // Extract hours and convert to integer
        int min = stoi(time.substr(3, 2)); // Extract minutes and convert to integer
        return hr * 60 + min; // Return total minutes since midnight
    }

    // Function to find the minimum time difference between any two time points
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;

        // Convert all time points to minutes and store in 'mins' vector
        for (auto time : timePoints) {
            mins.push_back(convertToMins(time));
        }

        // Sort the time points in ascending order
        sort(mins.begin(), mins.end());

        // Initialize the minimum time difference with a very large value
        int minTime = INT_MAX;

        // Calculate the minimum difference between consecutive time points
        for (int i = 0; i < mins.size() - 1; i++) {
            minTime = min(minTime, mins[i + 1] - mins[i]);
        }

        // Check the difference between the last and the first time points
        // (considering the time difference across midnight)
        int lastDiff = mins[0] + 1440 - mins[mins.size() - 1]; // 1440 minutes in a day
        minTime = min(minTime, lastDiff); // Update the minimum time difference if needed

        return minTime;
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<string> timePoints = {"00:00","23:59","00:00"};
    
    // Find and print the minimum time difference
    cout << "Minimum time difference: " << sol.findMinDifference(timePoints) << " minutes" << endl;
    
    return 0;
}

/** TEST CASES
 * 1. vector<string> timePoints = {"23:59", "00:00","12:34"};
 *    Minimum time difference: 1 minutes
 * 2. vector<string> timePoints = {"00:00","23:59","00:00"};
 *    Minimum time difference: 0 minutes
 * 
 */