#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            // If there's only one row, return the string as it is
            return s;
        }
        
        // Create a vector of strings to represent each row
        vector<string> rows(min(numRows, int(s.size())));
        
        int currentRow = 0;
        bool down = false; // This flag helps us determine the direction
        
        // Traverse the string
        for (char c : s) {
            rows[currentRow] += c; // Add character to the current row
            
            // If we're at the first or last row, reverse the direction
            if (currentRow == 0 || currentRow == numRows - 1) {
                down = !down;
            }
            
            // Move to the next row based on the direction
            currentRow += down ? 1 : -1;
        }
        
        // Concatenate all rows to form the final string
        string result;
        for (string row : rows) {
            result += row;
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Input: " << s1 << " with " << numRows1 << " rows" << endl;
    cout << "Output: " << solution.convert(s1, numRows1) << endl;  // Expected: "PAHNAPLSIIGYIR"
    
    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << "Input: " << s2 << " with " << numRows2 << " rows" << endl;
    cout << "Output: " << solution.convert(s2, numRows2) << endl;  // Expected: "PINALSIGYAHRPI"
    
    string s3 = "A";
    int numRows3 = 1;
    cout << "Input: " << s3 << " with " << numRows3 << " row" << endl;
    cout << "Output: " << solution.convert(s3, numRows3) << endl;  // Expected: "A"
    
    return 0;
}

/* TEST CASES
  Input: PAYPALISHIRING with 3 rows
  Output: PAHNAPLSIIGYIR

  Input: PAYPALISHIRING with 4 rows
  Output: PINALSIGYAHRPI
  
  Input: A with 1 row
  Output: A
*/