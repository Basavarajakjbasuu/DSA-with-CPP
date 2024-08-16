#include <iostream>
#include <string>
#include <climits> // For INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int num = 0;    // Variable to store the converted number
        int sign = 1;   // Variable to store the sign of the number (1 for positive, -1 for negative)
        int i = 0;      // Index to traverse the string

        // Handling leading white spaces
        while (i < s.size() && s[i] == ' ') {
            i++; // Skip all leading spaces
        }

        // Handling sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = s[i] == '+' ? 1 : -1; // Determine if the sign is positive or negative
            i++; // Move to the next character
        }

        // Convert the digits to an integer
        while (i < s.size() && isdigit(s[i])) {
            // Check for overflow and underflow before updating num
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
                // Return INT_MAX if the sign is positive, otherwise return INT_MIN
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num * 10 + (s[i] - '0'); // Update num with the current digit
            i++; // Move to the next character
        }

        return num * sign; // Apply the sign and return the final number
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter a string to convert to integer: ";
    cin >> input;

    int result = solution.myAtoi(input);
    cout << "Converted integer: " << result << endl;

    return 0;
}

/* TEST CASES
  1. Enter a string to convert to integer:     -42
     Converted integer: -42
  2. Enter a string to convert to integer: 1337a234
     Converted integer: 1337
  3. Enter a string to convert to integer: 0-1
     Converted integer: 0
  4. Enter a string to convert to integer: Bassu 0 123
     Converted integer: 0
  5. Enter a string to convert to integer:  -042 
     Converted integer: -42
*/