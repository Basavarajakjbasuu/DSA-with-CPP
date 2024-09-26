#include<iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * Algorithm:
 * 🔄 1. We traverse each node of the tree recursively.
 * 🌀 2. For each node, we calculate the path sum starting from that node.
 * 🔄 3. Recursively check each node's left and right subtree.
 * ✨ 4. Count the number of paths that equal the target sum, using a helper function to calculate all valid paths.
 *
 * Time Complexity: O(N^2) in the worst case where N is the number of nodes. For each node, the function `pathSumFromRoot` might take O(N) time, resulting in an O(N^2) complexity.
 * Space Complexity: O(H) where H is the height of the tree, due to the recursion stack.
 */

class Solution {
public:
    int totalPaths = 0; // 📝 Renamed to better represent its purpose

    // Helper function to count paths that start from the current node and sum to targetSum
    void countPathsFromNode(TreeNode* node, long long remainingSum) {
        if (!node) return;

        // 🎯 If current node value matches remaining sum, we found a valid path
        if(remainingSum == node->val) {
            totalPaths++;
        }

        // 🌿 Recursively check left and right children
        countPathsFromNode(node->left, remainingSum - node->val);
        countPathsFromNode(node->right, remainingSum - node->val);
    }

    // Main function to calculate total path sum for the entire tree
    int pathSum(TreeNode* root, long long targetSum) {
        if (root) {
            countPathsFromNode(root, targetSum); // 💡 Count all paths starting from the current root
            pathSum(root->left, targetSum); // 🌿 Check left subtree
            pathSum(root->right, targetSum); // 🌿 Check right subtree
        }
        return totalPaths; // 📊 Return total number of valid paths
    }
};

// Function for local execution
int main() {
    // Creating a sample binary tree:
    //         10
    //        /  \
    //       5   -3
    //      / \    \
    //     3   2   11
    //    / \
    //   3  -2
    //        \
    //         1
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->left->right->right = new TreeNode(1);

    long long targetSum = 8;
    Solution solution;
    int result = solution.pathSum(root, targetSum);
    cout << "Total number of paths with sum " << targetSum << ": " << result << endl; // Expected output: 3

    return 0;
}

/*
Sample Output:
For root = [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1] and targetSum = 8:
Output = 3

For root = [5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1] and targetSum = 22:
Output = 3
*/

