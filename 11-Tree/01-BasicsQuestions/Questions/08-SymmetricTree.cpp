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

class Solution {
public:
    /**
     * Algorithm:
     * 1. The binary tree is symmetric if the left and right subtrees are mirrors of each other.
     * 2. To check this, we can recursively compare two subtrees:
     *    - The left subtree of the left node with the right subtree of the right node.
     *    - The right subtree of the left node with the left subtree of the right node.
     * 3. If both subtrees are mirrors, the tree is symmetric.
     * 
     * Time Complexity: O(n) 
     * - We traverse each node once in the tree.
     * 
     * Space Complexity: O(h) 
     * - This is due to the recursive call stack, where 'h' is the height of the tree. In the worst case, the height could be 'n' (skewed tree).
     */

    bool isMirror(TreeNode* p, TreeNode* q) {
        // If both nodes are null, they are mirrors.
        if (!p && !q) {
            return true;
        }

        // If both nodes are non-null, compare values and check mirror symmetry of subtrees.
        if (p && q) {
            return (p->val == q->val) && 
                    isMirror(p->left, q->right) && 
                    isMirror(p->right, q->left);
        }

        // One of the nodes is null, the other isn't, hence not mirrors.
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        // The root tree is symmetric if its left and right subtrees are mirrors of each other.
        return isMirror(root->left, root->right);
    }
};

int main() {
    // Example usage:
    // Create a binary tree manually for testing or add user input logic.
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    bool isSym = solution.isSymmetric(root);

    if (isSym) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}

/*
 Sample Input:
 Tree: [1,2,2,3,4,4,3]

 Sample Output:
 The tree is symmetric.

 Time Complexity: O(n)
 Space Complexity: O(h)
 */
