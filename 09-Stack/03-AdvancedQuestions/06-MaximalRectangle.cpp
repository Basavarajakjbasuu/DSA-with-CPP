#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

    // Find the previous smaller element for each index
    vector<int> findPreviousSmaller(vector<int>& heights) {
        vector<int> previousSmaller(heights.size());
        stack<int> indexStack;
        indexStack.push(-1); // Sentinel for no previous element

        // Loop through each height in the array
        for (int i = 0; i < heights.size(); i++) {
            int currentHeight = heights[i];

            // Pop elements from the stack until we find a smaller element
            while (indexStack.top() != -1 && heights[indexStack.top()] >= currentHeight) {
                indexStack.pop();
            }

            // Store the index of the previous smaller element
            previousSmaller[i] = indexStack.top();
            indexStack.push(i); // Push current index onto stack
        }

        return previousSmaller;
    }

    // Find the next smaller element for each index
    vector<int> findNextSmaller(vector<int>& heights) {
        vector<int> nextSmaller(heights.size());
        stack<int> indexStack;
        indexStack.push(-1); // Sentinel for no next element

        // Loop through each height in reverse
        for (int i = heights.size() - 1; i >= 0; i--) {
            int currentHeight = heights[i];

            // Pop elements from the stack until we find a smaller element
            while (indexStack.top() != -1 && heights[indexStack.top()] >= currentHeight) {
                indexStack.pop();
            }

            // Store the index of the next smaller element
            nextSmaller[i] = indexStack.top();
            indexStack.push(i); // Push current index onto stack
        }

        return nextSmaller;
    }

    // Calculate the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        // Find previous and next smaller elements for each bar
        vector<int> previousSmaller = findPreviousSmaller(heights);
        vector<int> nextSmaller = findNextSmaller(heights);

        int maxRectangleArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];

            // If there is no next smaller element, assume it to be the end of the array
            if (nextSmaller[i] == -1) {
                nextSmaller[i] = heights.size();
            }

            // Calculate width as the distance between previous and next smaller elements
            int width = nextSmaller[i] - previousSmaller[i] - 1;

            // Calculate the area for the current height and width
            int currentArea = height * width;
            maxRectangleArea = max(maxRectangleArea, currentArea);
        }

        return maxRectangleArea;
    }

public:
    // Function to calculate the maximal rectangle area from a binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> heightMatrix(rows, vector<int>(cols, 0));

        // Convert matrix from '0'/'1' to integer heights
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                heightMatrix[i][j] = matrix[i][j] - '0';
            }
        }

        // Calculate the largest rectangle area for the first row
        int maxArea = largestRectangleArea(heightMatrix[0]);

        // Update height matrix and calculate area for each row
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (heightMatrix[i][j] != 0) {
                    heightMatrix[i][j] += heightMatrix[i - 1][j];
                } else {
                    heightMatrix[i][j] = 0; // Reset if it's a '0'
                }
            }
            // Update the maximum area after processing each row
            maxArea = max(maxArea, largestRectangleArea(heightMatrix[i]));
        }

        return maxArea;
    }
};

int main() {
    Solution solution;

    // Test case: 2D matrix with '0' and '1'
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    // Output the maximal rectangle area
    cout << "Maximal Rectangle Area: " << solution.maximalRectangle(matrix) << endl;

    return 0;
}

/*
Time Complexity:
- `largestRectangleArea`: O(n), where n is the number of bars in the histogram.
- `maximalRectangle`: O(m * n), where m is the number of rows and n is the number of columns in the matrix.

Space Complexity:
- O(m * n) for the height matrix and the stack used in finding previous/next smaller elements.

Example Output:
Maximal Rectangle Area: 6
*/
