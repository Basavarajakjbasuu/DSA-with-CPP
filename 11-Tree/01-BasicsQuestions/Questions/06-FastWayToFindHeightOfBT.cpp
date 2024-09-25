#include<iostream>
#include<cmath>
using namespace std;

// Definition of the TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    // 📝 Algorithm Explanation:
    /*
    1️⃣ The function `isBalanced()` checks if a binary tree is height-balanced.
    2️⃣ It uses a helper function `height()` that recursively calculates the height of each subtree.
    3️⃣ During height calculation, the function also compares the heights of the left and right subtrees at each node.
    4️⃣ If at any node, the absolute difference between the left and right subtree heights exceeds 1, the tree is marked as unbalanced.
    5️⃣ The final result is determined by the global variable `isBalancedTree` after the `height()` function completes execution.
    */

    bool isBalancedTree = true;  // Global variable to track if the tree is balanced

    // 📝 Function to compute the height of the tree while checking balance
    // Time Complexity: O(n) where n is the number of nodes.
    // Space Complexity: O(h) where h is the height of the tree (due to recursion stack).
    int height(TreeNode* root) {
        if (!root) return 0;

        // Recursively calculate the height of left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // If the height difference is more than 1, mark the tree as unbalanced
        if (isBalancedTree && abs(leftHeight - rightHeight) > 1) {
            isBalancedTree = false;
        }

        // Return the height of the current node
        return max(leftHeight, rightHeight) + 1;
    }

    // 📝 Function to check if the tree is balanced
    // Time Complexity: O(n), Space Complexity: O(h) (n: number of nodes, h: height of the tree)
    bool isBalanced(TreeNode* root) {
        height(root);  // Compute the height and check if it's balanced
        return isBalancedTree;  // Return the final result
    }
};

// 📝 Function to create a simple tree for testing
TreeNode* createTree() {
    // Sample tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    return root;
}

int main() {
    // Create the tree and check if it's balanced
    TreeNode* root = createTree();
    Solution solution;
    
    // 📝 Output the result of checking balance
    if (solution.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}

/*
Sample Output:
The tree is balanced.
*/

