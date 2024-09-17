#include <iostream>
#include <vector>
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
    // 🔍 Algorithm to find all paths with a given sum:
    // 1️⃣ Base Case: If the node is NULL, return.
    // 2️⃣ Add the current node's value to the running sum and path.
    // 3️⃣ If at a leaf node, check if the sum matches the target.
    //    - If it matches, store the current path in the result.
    //    - If it doesn't match, return.
    // 4️⃣ Recursively search the left and right subtrees.
    // 5️⃣ Backtrack by removing the current node from the path.

    void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> temp, int sum) {
        // Base case: if node is NULL, return
        if (root == NULL) return;

        // Add the current node's value to the sum and path
        sum += root->val;
        temp.push_back(root->val);

        // If it's a leaf node, check if the path sum matches the target
        if (root->left == NULL && root->right == NULL) {
            if (targetSum == sum) {
                // Store the valid path
                ans.push_back(temp);
            }
            return;
        }

        // Recursively search left and right subtrees
        solve(root->left, targetSum, ans, temp, sum);
        solve(root->right, targetSum, ans, temp, sum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, targetSum, ans, temp, sum);
        return ans;
    }
};

// 🧪 Example usage for testing
int main() {
    Solution solution;

    // Create a sample binary tree:
    //          5
    //         / \
    //        4   8
    //       /   / \
    //      11  13  4
    //     /  \       \
    //    7    2       1
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
    vector<vector<int>> result = solution.pathSum(root, targetSum);

    cout << "Paths with sum " << targetSum << ":\n";
    for (const auto& path : result) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

💾 Space Complexity:
- O(h), where h is the height of the tree due to recursion stack space.

📊 Example Output:
Paths with sum 22:
5 4 11 2 
5 8 4 1 
*/

