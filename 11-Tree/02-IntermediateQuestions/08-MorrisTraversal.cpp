#include<iostream>
#include<vector>

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
     * 🌳 Algorithm for Morris Inorder Traversal:
     * 1️⃣ Start from the root node and initialize 'curr' to the root.
     * 2️⃣ Traverse the tree iteratively:
     *     🔄 a) If the current node has no left child, add its value to the result and move to the right child.
     *     🔄 b) If the current node has a left child, find its inorder predecessor (rightmost node in the left subtree).
     *     🔄 c) If the predecessor's right is NULL, link it to the current node and move to the left child.
     *     🔄 d) If the predecessor's right is already pointing to the current node, remove the link, add the current node value to the result, and move to the right child.
     * 3️⃣ Continue until all nodes are processed.
     * 4️⃣ Return the result vector with the inorder traversal of the tree.
     *
     * 🧠 Time Complexity: O(n) – Each node is visited a constant number of times.
     * 🧠 Space Complexity: O(1) – No extra space, except the result vector.
     */

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;  // 🌟 Stores the final inorder traversal result.
        TreeNode* curr = root;  // 🌱 Start traversing from the root.

        while(curr) {  // 🔄 Loop until all nodes are visited.
            if (curr->left == NULL) {  // 🚫 If no left subtree, visit the node.
                result.push_back(curr->val);  // 📥 Add node value to result.
                curr = curr->right;  // 👉 Move to the right subtree.
            } else {
                TreeNode* pred = curr->left;  // 🔍 Find the inorder predecessor.
                while (pred->right != curr && pred->right) {  // 🔄 Traverse to the rightmost node.
                    pred = pred->right;
                }

                if (pred->right == NULL) {  // 🔗 Create a temporary link to the current node.
                    pred->right = curr;
                    curr = curr->left;  // 👈 Move to the left subtree.
                } else {  // 🔄 If link exists, remove it and visit the node.
                    pred->right = NULL;  // ❌ Remove the temporary link.
                    result.push_back(curr->val);  // 📥 Add node value to result.
                    curr = curr->right;  // 👉 Move to the right subtree.
                }
            }
        }

        return result;  // 🎯 Return the final inorder traversal.
    }
};

// Example Usage (Local Execution):
 int main() {
     Solution solution;
     TreeNode* root = new TreeNode(1);
     root->left = new TreeNode(2);
     root->right = new TreeNode(3);
     root->left->left = new TreeNode(4);
     root->left->right = new TreeNode(5);

     vector<int> result = solution.inorderTraversal(root);
     for (int val : result) {
         cout << val << " ";
     }
     return 0;
 }

/**
 * Output: 4 2 5 1 3
 * 
 * 🧠 Time Complexity: O(n) – Each node is visited twice, once for establishing a link and once for breaking it.
 * 🧠 Space Complexity: O(1) – No extra space required except for the output vector.
 */
