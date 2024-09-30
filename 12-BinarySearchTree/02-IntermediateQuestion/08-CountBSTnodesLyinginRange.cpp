#include <iostream>
using namespace std;

// 🌳 Definition for the Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// 🌟 Class to count the nodes in a range [l, h] in a Binary Search Tree (BST)
class Solution {
public:
    /**
     * 🌟 Algorithm to count nodes in a given range [l, h]:
     * 1️⃣ If the current node's value is within the range, increment the count.
     * 2️⃣ Traverse the left subtree only if the current node's value is greater than l (potential nodes in range).
     * 3️⃣ Traverse the right subtree only if the current node's value is less than h (potential nodes in range).
     * 4️⃣ Recursively apply the above steps to count all valid nodes.
     * 
     * Time Complexity: O(n) 🕒 (linear traversal of the tree).
     * Space Complexity: O(h) 🧠 (call stack for recursive function, where h is the height of the tree).
     */
    int countNodesInRange(Node* root, int low, int high) {
        if (!root) return 0;  // Base case: Null node

        int nodeCount = 0;  // Initialize the count

        // 🌿 Check if the current node's value is within the range
        if (root->data >= low && root->data <= high) {
            nodeCount = 1;
        }

        // 🌲 Traverse the left subtree if possible
        if (root->data > low) {
            nodeCount += countNodesInRange(root->left, low, high);
        }

        // 🌲 Traverse the right subtree if possible
        if (root->data < high) {
            nodeCount += countNodesInRange(root->right, low, high);
        }

        return nodeCount;  // Return the total count of nodes within the range
    }
};

// 🌟 Driver code for local execution
int main() {
    Solution solution;

    // 🌳 Example tree (BST)
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int low = 5, high = 45;

    // 🛠 Count the number of nodes within the range [5, 45]
    int result = solution.countNodesInRange(root, low, high);

    // 📝 Print the result (expected: 4, as nodes 5, 10, 40, and 50 are in the range)
    cout << "Number of nodes in the range [" << low << ", " << high << "]: " << result << endl;

    return 0;
}

/**
 * Example Output:
 * Number of nodes in the range [5, 45]: 4
 * 
 * Explanation of Output:
 * - The nodes 5, 10, 40, and 50 are within the range [5, 45].
 */

// Time Complexity: O(n) 🕒 (linear traversal of the tree).
// Space Complexity: O(h) 🧠 (where h is the height of the tree, due to the recursive call stack).
