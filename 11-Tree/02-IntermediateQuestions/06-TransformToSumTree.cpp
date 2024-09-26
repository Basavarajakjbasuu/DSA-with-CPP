#include <iostream>
using namespace std;

// A binary tree node definition
struct Node {
    int data;        // Data of the current node
    Node* left;      // Pointer to the left child
    Node* right;     // Pointer to the right child
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 🌳✨ Algorithm to convert binary tree to sum tree 🌳✨
    // This function computes the sum of all nodes under a given root
    // and updates the node's data with the sum of its left and right children.
    int convertToSumTree(Node* root) {
        // Base Case: If the node is null, return 0
        if (!root) return 0;

        // Step 1️⃣: Recurse on the left subtree
        int leftSubtreeSum = convertToSumTree(root->left);

        // Step 2️⃣: Recurse on the right subtree
        int rightSubtreeSum = convertToSumTree(root->right);

        // Step 3️⃣: Store the current node's data before modification
        int originalValue = root->data;

        // Step 4️⃣: Update the current node's data with the sum of left and right subtrees
        root->data = leftSubtreeSum + rightSubtreeSum;

        // Step 5️⃣: Return the sum of the current node's original value
        // and the sum of its children
        return originalValue + root->data;
    }

    // Wrapper function to convert a tree to a sum tree.
    void toSumTree(Node* root) {
        convertToSumTree(root);
    }
};

/* 🌟 Time Complexity Analysis 🌟:
 * - Each node is visited once, making the time complexity O(n), where n is the total number of nodes.
 * 
 * 🌟 Space Complexity Analysis 🌟:
 * - Space complexity is O(h), where h is the height of the tree, due to recursive stack space.
 */

// Helper function to print the tree in order for result verification
void inOrderPrint(Node* root) {
    if (root == nullptr) return;
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

// Sample Test Case
int main() {
    // Create a sample tree:
    //        10
    //       /  \
    //     -2    6
    //    /  \  / \
    //   8   -4 7  5
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    Solution solution;
    solution.toSumTree(root);  // Convert the tree to a sum tree

    // In-order traversal to check the result
    cout << "In-order traversal of the sum tree: ";
    inOrderPrint(root);  // Expected output: 0 0 4 0 0 0 0
    cout << endl;

    return 0;
}

/*
📝 Expected Output: 
In-order traversal of the sum tree: 0 0 4 0 0 0 0 

*/
