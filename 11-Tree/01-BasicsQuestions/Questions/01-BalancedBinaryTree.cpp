#include <iostream>
#include <cmath> // for abs
using namespace std;

// 🚧 Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 🌳 Helper function to calculate the height of the binary tree
    // Algorithm:
    // 1️⃣ Recursively calculate the height of the left and right subtrees.
    // 2️⃣ The height of the current node is the max of left and right heights + 1.
    int height(TreeNode* root) {
        // 🛑 Base case: If the root is null, return height 0
        if (root == nullptr) {
            return 0;
        }

        // 🔄 Recursively calculate the height of the left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // 🎯 The height of the current node is the max height of its children + 1
        return max(leftHeight, rightHeight) + 1;
    }

    // ⚖️ Function to check if the tree is balanced
    // A tree is balanced if the height difference between left and right subtrees is <= 1.
    // Algorithm:
    // 1️⃣ Recursively check for each node if its left and right subtrees are balanced.
    // 2️⃣ Use the height function to calculate the heights of left and right subtrees.
    // 3️⃣ If the height difference between left and right subtrees is <= 1, it is balanced.
    // 4️⃣ Continue this check recursively for all nodes.
    bool isBalanced(TreeNode* root) {
        // 🛑 Base case: If the root is null, it's balanced
        if (root == nullptr) {
            return true;
        }

        // 🧮 Calculate the height of the left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // 📏 Calculate the difference in height
        int heightDifference = abs(leftHeight - rightHeight);

        // ✅ Check if the current node is balanced
        bool currentBalanced = (heightDifference <= 1);

        // 🔄 Recursively check the left and right subtrees
        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);

        // 🏆 Return true if both the left and right subtrees are balanced, and the current node is balanced
        return currentBalanced && leftBalanced && rightBalanced;
    }
};

// 🏁 Main function for testing
int main() {
    Solution solution;

    // 🧪 Example test case: Creating a balanced binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // 📤 Output whether the tree is balanced or not
    bool result = solution.isBalanced(root);
    cout << "Is the tree balanced? " << (result ? "Yes" : "No") << endl;

    return 0;
}

/*
⏳ Time Complexity:
- O(n^2) in the worst case, where n is the number of nodes. Each node's height is calculated repeatedly.

💾 Space Complexity:
- O(n) for the recursive stack in the worst case, where n is the height of the tree.

📊 Example Output:
Is the tree balanced? Yes
*/
