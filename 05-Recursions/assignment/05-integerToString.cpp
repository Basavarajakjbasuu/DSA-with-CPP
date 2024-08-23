#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // A vector of pairs containing number values and their corresponding word representations
    vector<pair<int, string>> numWordsMap= {
            { 1000000000, "Billion" },
            { 1000000, "Million" },
            { 1000, "Thousand" },
            { 100, "Hundred" },
            { 90, "Ninety" },
            { 80, "Eighty" },
            { 70, "Seventy" },
            { 60, "Sixty" },
            { 50, "Fifty" },
            { 40, "Forty" },
            { 30, "Thirty" },
            { 20, "Twenty" },
            { 19, "Nineteen" },
            { 18, "Eighteen" },
            { 17, "Seventeen" },
            { 16, "Sixteen" },
            { 15, "Fifteen" },
            { 14, "Fourteen" },
            { 13, "Thirteen" },
            { 12, "Twelve" },
            { 11, "Eleven" },
            { 10, "Ten" },
            { 9, "Nine" },
            { 8, "Eight" },
            { 7, "Seven" },
            { 6, "Six" },
            { 5, "Five" }, 
            { 4, "Four" },
            { 3, "Three" },
            { 2, "Two" },
            { 1, "One"}
        };

    // Function to convert a number into words
    string numberToWords(int num) {
        // BASE CASE: If the number is zero, return "Zero"
        if (num == 0) {
            return "Zero";
        }

        // Iterate over the map and check the appropriate place value for the number
        for (auto it : numWordsMap) {
            // If the number is greater than or equal to the current place value
            if (num >= it.first) {
                // `prefixWords` will hold the word for the prefix (e.g., "One", "Two", etc.)
                string prefixWords = "";

                // If the place value is 100 or greater, recursively convert the quotient part to words
                if (num >= 100) {
                    prefixWords = numberToWords(num / it.first) + " ";
                }

                // `currentPlaceValueWord` stores the word for the current place value (e.g., "Billion", "Hundred", etc.)
                string currentPlaceValueWord = it.second;

                // `suffixWords` will store the word for the remainder part, if any
                string suffixWords = "";
                
                // If there's a remainder, convert that part to words recursively
                if (num % it.first != 0) {
                    suffixWords = " " + numberToWords(num % it.first);
                }

                // Return the combination of prefix, place value word, and suffix
                return prefixWords + currentPlaceValueWord + suffixWords;
            }
        }

        // In case no conversion is needed, return an empty string
        return "";
    }
};

int main() {
    Solution solution;

    // Example input
    int number = 11;

    // Convert the number to words and print the result
    string result = solution.numberToWords(number);
    cout << result << endl;  // Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

    return 0;
}

/** TEST CASES
 * 1.int number = 1234567891;
 *    One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One
 * 
 * 2. int number = 89741;
 *    Eighty Nine Thousand Seven Hundred Forty One
 * 
 * 3. int number = 11;
 *    Eleven
 */