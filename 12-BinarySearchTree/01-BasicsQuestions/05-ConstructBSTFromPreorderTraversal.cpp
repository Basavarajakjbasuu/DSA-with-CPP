#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 🌳 Definition of the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * Algorithm for building a BST from preorder traversal 🌟:
     * 1️⃣ Initialize an index `i` to track the current node in the preorder list.
     * 2️⃣ Create a recursive function `buildBST`:
     *     - Check if the current node's value fits within the bounds [min, max].
     *     - If valid, create a new node with the current value from preorder.
     *     - Recursively build the left subtree with the updated range (min, node's value).
     *     - Recursively build the right subtree with the updated range (node's value, max).
     * 3️⃣ Return the root node when the tree is built.
     * 
     * Time Complexity: O(n), where n is the number of nodes 🕒.
     * Space Complexity: O(n) due to recursion depth and tree construction 🧠.
     */
    
    // 🌿 Recursive helper function to build the BST from preorder
    TreeNode* buildBST(int &index, int minVal, int maxVal, vector<int>& preorder) {
        // 🍂 Base case: when index exceeds the size of the preorder list
        if (index >= preorder.size()) return nullptr;

        TreeNode* node = nullptr;

        // 🌟 Check if the current node value lies within valid bounds
        if (preorder[index] > minVal && preorder[index] < maxVal) {
            node = new TreeNode(preorder[index++]);  // 🌱 Create the node and increment index
            node->left = buildBST(index, minVal, node->val, preorder);  // 🍃 Build the left subtree
            node->right = buildBST(index, node->val, maxVal, preorder);  // 🌿 Build the right subtree
        }

        return node;
    }

    // 🌟 Main function to start the BST construction from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;  // Starting index
        return buildBST(index, INT_MIN, INT_MAX, preorder);
    }
};

// 🌟 Utility function to print inorder traversal of the BST (for testing)
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// 🌟 Driver function to execute the solution
int main() {
    Solution solution;

    // 🌳 Example preorder traversal
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // 🌿 Build the BST from the preorder traversal
    TreeNode* bstRoot = solution.bstFromPreorder(preorder);

    // 🌟 Output the inorder traversal to verify correctness
    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(bstRoot);
    cout << endl;

    return 0;
}

/**
 * Output Explanation 🌟:
 * For the given preorder traversal {8, 5, 1, 7, 10, 12}, the resulting BST will have:
 *   - 8 as the root, 
 *   - 5 as the left child, 
 *   - 10 as the right child, 
 *   - 1 and 7 as the left and right children of 5, 
 *   - 12 as the right child of 10.
 * 
 * The inorder traversal of the constructed BST will be: 1 5 7 8 10 12.
 */

// Time Complexity: O(n), where n is the number of nodes in the BST 🕒.
// Space Complexity: O(n) due to recursion depth and tree construction 🧠.
