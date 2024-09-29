#include <iostream>
#include <vector>
using namespace std;

// 🌳 Definition for the binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * 🌟 Algorithm for balancing a Binary Search Tree (BST):
     * 1️⃣ Perform an in-order traversal of the BST and store the nodes' values in a sorted array.
     * 2️⃣ Build a balanced BST from this sorted array:
     *     - Pick the middle element as the root to ensure balance.
     *     - Recursively repeat the process for the left and right halves of the array to build left and right subtrees.
     * 3️⃣ Return the root of the balanced BST.
     *
     * Time Complexity: O(n) 🕒 (n for in-order traversal and n for building the balanced tree).
     * Space Complexity: O(n) 🧠 (to store the in-order traversal and for recursion stack).
     */

    // 🔍 In-order traversal (LNR: Left, Node, Right)
    void inorderTraversal(TreeNode* currentNode, vector<int> &sortedValues) {
        if (!currentNode) return;  // 🌿 Base case: if the node is NULL, return
        
        inorderTraversal(currentNode->left, sortedValues);  // 🌱 Visit left subtree
        sortedValues.push_back(currentNode->val);           // 🌟 Visit node
        inorderTraversal(currentNode->right, sortedValues); // 🌿 Visit right subtree
    }

    // 🌳 Build a balanced BST from a sorted array of values
    TreeNode* buildBalancedTree(vector<int> &sortedValues, int startIdx, int endIdx) {
        if (startIdx > endIdx) return NULL;  // 🍂 Base case: if indices are invalid, return NULL
        
        int midIdx = (startIdx + endIdx) / 2;  // 📏 Pick the middle element to ensure balance
        TreeNode* newRoot = new TreeNode(sortedValues[midIdx]);  // 🌱 Create new root
        
        newRoot->left = buildBalancedTree(sortedValues, startIdx, midIdx - 1);  // 🌿 Build left subtree
        newRoot->right = buildBalancedTree(sortedValues, midIdx + 1, endIdx);   // 🍃 Build right subtree
        
        return newRoot;  // 🌳 Return the newly built balanced tree
    }

    // 🌟 Main function to balance a BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedValues;  // 🌟 Vector to store in-order traversal
        inorderTraversal(root, sortedValues);  // 📝 Fill the vector with the sorted values

        return buildBalancedTree(sortedValues, 0, sortedValues.size() - 1);  // 🌳 Build and return the balanced tree
    }
};

// 🌟 Driver code for local execution
int main() {
    Solution solution;

    // 🌳 Example tree (unbalanced BST)
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(1);
    root->right->right = new TreeNode(30);

    // 🛠 Balance the BST
    TreeNode* balancedRoot = solution.balanceBST(root);

    // 📝 Print the root of the balanced tree (expected balanced root: 10)
    cout << "Root of the balanced BST is: " << balancedRoot->val << endl;

    return 0;
}

/**
 * Example Output:
 * Root of the balanced BST is: 10
 * 
 * Explanation of Output:
 * - The original BST was unbalanced, so after performing the in-order traversal and building the balanced BST,
 *   the tree becomes balanced with the root remaining the same in this case.
 */

// Time Complexity: O(n) 🕒 (for in-order traversal and building the balanced tree).
// Space Complexity: O(n) 🧠 (due to storing the in-order traversal and the recursion stack).
