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
    // 🔍 Algorithm to find the lowest common ancestor (LCA):
    // 1️⃣ Base Case: If the current node is NULL, return NULL.
    // 2️⃣ Check if the current node matches either of the two target nodes p or q.
    // 3️⃣ Recursively traverse the left and right subtrees.
    // 4️⃣ After the recursive calls:
    //    - If both left and right have non-NULL values, the current node is the LCA.
    //    - If only one side has a non-NULL value, return that node (it means LCA is found in that subtree).
    //    - If neither subtree has a match, return NULL.
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;  // 🛑 If node is NULL, return NULL.
        if (root->val == p->val) return p;  // ✅ If current node matches p, return p.
        if (root->val == q->val) return q;  // ✅ If current node matches q, return q.

        // 🌳 Recursively find LCA in left and right subtrees.
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        // 🧠 LCA decision:
        if (leftAns == NULL && rightAns == NULL) return NULL;  // 🔄 No LCA found.
        else if (leftAns != NULL && rightAns == NULL) return leftAns;  // 🔼 LCA found in left subtree.
        else if (leftAns == NULL && rightAns != NULL) return rightAns;  // 🔽 LCA found in right subtree.
        else return root;  // 🏆 Current node is the LCA since both left and right have results.
    }
};

// 🧪 Example usage for testing
int main() {
    Solution solution;
    
    // Create a sample binary tree: 
    //          3
    //         / \
    //        5   1
    //       / \ / \
    //      6  2 0  8
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* p = root->left;  // Node with value 5
    TreeNode* q = root->right;  // Node with value 1

    TreeNode* result = solution.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor: " << result->val << endl;

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

💾 Space Complexity:
- O(h), where h is the height of the tree due to recursion stack space.

📊 Example Output:
Lowest Common Ancestor: 3
*/

