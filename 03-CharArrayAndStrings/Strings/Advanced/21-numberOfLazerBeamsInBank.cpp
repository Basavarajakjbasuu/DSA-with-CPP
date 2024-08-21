#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // For std::count

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result = 0;  // This will hold the final count of laser beams
        int prev = 0;    // Keeps track of the number of devices in the previous row

        // Iterate over each row in the bank
        for(auto& row : bank) {
            // Count the number of '1's in the current row (number of devices)
            int curr = count(row.begin(), row.end(), '1');

            // If there are no devices in the current row, skip to the next row
            if(curr == 0) continue;

            // Add the product of devices in the previous row and the current row to the result
            result += (prev * curr);

            // Update prev to be the number of devices in the current row
            prev = curr;
        }

        // Return the total number of laser beams
        return result;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<string> bank = {"011001", "000000", "010100", "001000"};
    
    int result = solution.numberOfBeams(bank);
    cout << "Number of laser beams: " << result << endl;  // Expected output: 8

    return 0;
}
