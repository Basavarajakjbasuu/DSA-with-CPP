#include <iostream>
#include <vector>
#include <algorithm>  // Needed for the reverse function

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;   // 'index' will be used to track the position where we write in the array
        int count = 1;   // 'count' keeps track of the number of occurrences of the current character
        char prev = chars[0];  // 'prev' holds the previous character, starting with the first character
        
        // Iterate through the array starting from the second character
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == prev) {
                // If the current character matches the previous one, increment the count
                count++;
            } else {
                // If the current character is different, write the previous character to the array
                chars[index++] = prev;
                
                // If the count is greater than 1, write the count to the array
                if (count > 1) {
                    int start = index;  // 'start' will mark where the digits of the count start
                    while (count) {
                        chars[index++] = (count % 10) + '0';  // Write the last digit of count as a character
                        count /= 10;  // Remove the last digit from count
                    }
                    reverse(chars.begin() + start, chars.begin() + index);  // Reverse the digits to correct order
                }
                
                // Update 'prev' to the current character and reset count to 1
                prev = chars[i];
                count = 1;
            }
        }
        
        // After the loop, we need to handle the last group of characters
        chars[index++] = prev;  // Write the last character to the array
        if (count > 1) {
            int start = index;
            while (count) {
                chars[index++] = (count % 10) + '0';
                count /= 10;
            }
            reverse(chars.begin() + start, chars.begin() + index);  // Reverse to get the correct order
        }
        
        return index;  // The new length of the compressed array
    }
};

int main() {
    // Example usage
    vector<char> chars = {'a','a','b','b','c','c','c'};
    
    Solution sol;
    int newLength = sol.compress(chars);
    
    // Output the compressed result
    cout << "Compressed array: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i];
    }
    cout << endl;
    
    cout << "New length: " << newLength << endl;
    
    return 0;
}


/* TEST CASES
  1.vector<char> chars = {'a','a','b','b','c','c','c'}; 
    Compressed array: a2b2c3
*/
