#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Function to convert an integer to a Roman numeral
    string intToRoman(int num) {
        // Array of Roman numeral symbols in decreasing order of value
        string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        // Array of corresponding integer values for each Roman numeral symbol
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        // String to store the final Roman numeral result
        string ans = "";

        // Iterate over each value in the array of values
        for (int i = 0; i < 13; i++) {
            // For each value, subtract it from num and add the corresponding Roman numeral symbol
            // to the result string as long as num is greater than or equal to the current value
            while (num >= values[i]) {
                ans += romanSymbols[i];  // Append the Roman numeral symbol to the result
                num -= values[i];        // Subtract the value from num
            }
        }
        // Return the final Roman numeral string
        return ans;
    }
};

int main() {
    // Example usage of the intToRoman function
    Solution solution;
    
    int num = 1994;  // Example number to convert to Roman numerals
    string romanNumeral = solution.intToRoman(num);
    
    // Output the Roman numeral
    cout << "The Roman numeral for " << num << " is: " << romanNumeral << endl;

    return 0;
}

/* TEST CASES
  1.int num = 1987;
    The Roman numeral for 1987 is: MCMLXXXVII
  2.int num = 1994
    The Roman numeral for 1994 is: MCMXCIV
*/