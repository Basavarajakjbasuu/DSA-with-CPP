#include <iostream>
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
    // 🔍 Algorithm to check if there exists a root-to-leaf path with a given sum:
    // 1️⃣ Base Case: If the node is NULL, return false (no valid path).
    // 2️⃣ Add the current node's value to the running sum.
    // 3️⃣ If the node is a leaf (both left and right children are NULL), check if the sum matches the target sum.
    // 4️⃣ Recursively check the left and right subtrees for a valid path.
    // 5️⃣ If either subtree returns true, the target path exists.

    bool solve(TreeNode* root, int targetSum, int sum) {
        // 🛑 Base case: If the node is NULL, return false (no valid path exists).
        if (root == NULL) return false;

        // ➕ Add the current node's value to the running sum.
        sum += root->val;

        // 🌿 If the node is a leaf, check if the path sum matches the target sum.
        if (root->left == NULL && root->right == NULL) {
            return targetSum == sum;
        }

        // 🔄 Recursively check the left and right subtrees for a valid path.
        bool leftAns = solve(root->left, targetSum, sum);
        bool rightAns = solve(root->right, targetSum, sum);

        // 🔁 Return true if either subtree has a valid path.
        return leftAns || rightAns;
    }

    // 💡 Main function to initiate the path sum check.
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return solve(root, targetSum, sum);
    }
};

// 🧪 Example usage for testing.
int main() {
    Solution solution;

    // Create a sample binary tree:
    //       5
    //      / \
    //     4   8
    //    /   / \
    //   11  13  4
    //  /  \      \
    // 7    2      1

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    // 📤 Output the result of the path sum check.
    bool result = solution.hasPathSum(root, targetSum);
    cout << (result ? "Path with target sum exists!" : "No path with target sum.") << endl;

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the binary tree. Each node is visited once.

💾 Space Complexity:
- O(h), where h is the height of the tree. In the worst case (unbalanced tree), the space complexity is O(n). In the best case (balanced tree), it's O(log n) due to the recursive stack.

📊 Example Output:
Path with target sum exists!
*/

