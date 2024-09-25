#include<iostream>
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
    1️⃣ The function `isSameTree()` recursively compares two binary trees.
    2️⃣ If both nodes `p` and `q` are `nullptr`, the trees at that point are considered the same.
    3️⃣ If both nodes are non-null, their values are compared.
    4️⃣ Recursively check the left subtree of both nodes and the right subtree of both nodes.
    5️⃣ If both the left and right subtrees match and the current node values are equal, the trees are the same.
    6️⃣ If one of the nodes is `nullptr` while the other is not, the trees are not the same.
    */

    // 📝 Function to check if two binary trees are identical
    // Time Complexity: O(n) where n is the number of nodes in the smaller tree.
    // Space Complexity: O(h) where h is the height of the tree (due to recursion stack).
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both trees are empty
        if (!p && !q) {
            return true;
        }

        // Both nodes exist, compare values and recursively check left and right subtrees
        if (p && q) {
            return (p->val == q->val) &&
                   isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        }

        // One of the trees is empty, so they are not the same
        return false;
    }
};

// 📝 Helper function to create a sample tree for testing
TreeNode* createSampleTree1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

// 📝 Helper function to create another sample tree for testing
TreeNode* createSampleTree2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

int main() {
    // Create two sample trees for testing
    TreeNode* tree1 = createSampleTree1();
    TreeNode* tree2 = createSampleTree2();
    
    Solution solution;
    
    // 📝 Output the result of comparing two trees
    if (solution.isSameTree(tree1, tree2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    return 0;
}

/*
Sample Output:
The trees are identical.
*/

