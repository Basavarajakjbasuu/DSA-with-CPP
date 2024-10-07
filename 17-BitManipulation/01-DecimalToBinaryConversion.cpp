#include<iostream> 
#include<cstring> 
using namespace std; 

// Function to convert a decimal number to binary
string convertToBinary(int num) { 
    string res = ""; // Initialize an empty string to store the binary result
  
    // Loop until the number becomes 0
    while(num != 0) { 
        // If the number is odd, append '1', otherwise append '0'
        if(num % 2 == 1) 
            res += '1'; 
        else 
            res += '0'; 

        // Divide the number by 2 (shifting bits to the right)
        num /= 2; 
    } 

    // Now reverse the result as the bits are in reverse order
    int left = 0, right = res.length() - 1; 
    while (left < right) { 
        // Swap characters at positions 'left' and 'right'
        swap(res[left], res[right]); 
        left++; 
        right--; 
    } 

    return res; // Return the final binary representation
} 
  
int main() { 
    int deciNum = 0; // Variable to store the decimal number
  
    // Prompt the user to enter a decimal number
    cout << "Enter decimal Num: "; 
    cin >> deciNum; // Read user input
  
    // Display the binary equivalent of the entered number
    cout << "Binary equivalent of " << deciNum << " is: " << convertToBinary(deciNum) << endl; 
    return 0; // End of the program
} 

/* 
   Time Complexity (TC): O(log2 N) 
   Space Complexity (SC): O(log2 N) 

   Sample Input/Output:
   --------------------
   Enter decimal Num: 13 
   Binary equivalent of 13 is: 1101 
  
   Enter decimal Num: 15 
   Binary equivalent of 15 is: 1111 
  
   Enter decimal Num: 1024 
   Binary equivalent of 1024 is: 10000000000 
*/