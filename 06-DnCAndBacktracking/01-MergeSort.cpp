#include<iostream>
using namespace std;

/*
🔎 merge function:
- Merges two sorted sub-arrays into one sorted array.
- Uses a two-pointer approach to merge the left and right sub-arrays.

⏳ Time Complexity: O(n), where n is the size of the sub-arrays combined.
💾 Space Complexity: O(n), for the temporary left and right arrays.
*/

void merge(int arr[], int startIndex, int endIndex) {
    int mid = (startIndex + endIndex) / 2;

    int lenLeftArray = mid - startIndex + 1;
    int lenRightArray = endIndex - mid;

    // Create left and right temporary arrays
    int *leftArray = new int[lenLeftArray];
    int *rightArray = new int[lenRightArray];

    // Copy values from original array to left array
    int k = startIndex;
    for (int i = 0; i < lenLeftArray; i++) {
        leftArray[i] = arr[k++];
    }

    // Copy values from original array to right array
    k = mid + 1;
    for (int i = 0; i < lenRightArray; i++) {
        rightArray[i] = arr[k++];
    }

    // Two-pointer approach for merging sorted arrays
    int leftIndex = 0, rightIndex = 0, mainArrayIndex = startIndex;

    // Merge the two sub-arrays into the original array
    while (leftIndex < lenLeftArray && rightIndex < lenRightArray) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[mainArrayIndex++] = leftArray[leftIndex++];
        } else {
            arr[mainArrayIndex++] = rightArray[rightIndex++];
        }
    }

    // If there are remaining elements in the left array
    while (leftIndex < lenLeftArray) {
        arr[mainArrayIndex++] = leftArray[leftIndex++];
    }

    // If there are remaining elements in the right array
    while (rightIndex < lenRightArray) {
        arr[mainArrayIndex++] = rightArray[rightIndex++];
    }

    // Free the temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

/*
🔎 mergeSort function:
- Recursively divides the array into two halves and sorts them using the merge function.

⏳ Time Complexity: O(n log n), where n is the number of elements in the array.
💾 Space Complexity: O(n), due to the recursion stack and temporary arrays.
*/

void mergeSort(int arr[], int startIndex, int endIndex) {
    // Base case: If the array has one or no elements, it is already sorted
    if (startIndex >= endIndex) {
        return;
    }

    // Calculate the middle index
    int mid = (startIndex + endIndex) / 2;

    // Recursively sort the left and right halves
    mergeSort(arr, startIndex, mid);
    mergeSort(arr, mid + 1, endIndex);

    // Merge the sorted halves
    merge(arr, startIndex, endIndex);
}

int main() {
    // Test array
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call mergeSort on the entire array
    mergeSort(arr, 0, n - 1);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
⏳ Time Complexity for main: O(n log n), due to merge sort.
💾 Space Complexity for main: O(n), for the array storage.

output:
  Original array: 38 27 43 3 9 82 10 
  Sorted array: 3 9 10 27 38 43 82
*/

