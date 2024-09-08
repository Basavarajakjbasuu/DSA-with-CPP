#include <iostream> 
using namespace std; 

// Function to shift all negative numbers to one side using the two-pointer approach.
void shiftNegativeOneSide(int arr[], int size) { 
    int negativePointer = 0;  // Points to where the next negative number should be placed.

    // Iterate through the array
    for (int i = 0; i < size; i++) { 
        // If the current element is negative, swap it with the element at negativePointer.
        if (arr[i] < 0) { 
            swap(arr[i], arr[negativePointer]); 
            negativePointer++;  // Move the negativePointer to the next position.
        } 
    } 
} 

// Helper function to print the contents of the array.
void outputArray(int arr[], int n) { 
    cout << "Displaying array: "; 
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
} 

int main() { 
    int arr[9] = {7, -6, 4, 5, -6, 7, 3, 5, -3};  // Example input array.
    int size = 9;  // Size of the array.

    // Call the function to shift negative numbers to one side.
    shiftNegativeOneSide(arr, size); 

    // Output the modified array.
    outputArray(arr, size); 
    return 0; 
} 

/*
Example Output:
Displaying array: -6 -6 -3 5 4 7 3 5 7
*/