#include <iostream>
#include <vector>
#include <queue>
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
    // 📝 Algorithm explanation:
    // This function performs a zigzag level order traversal (BFS) of a binary tree. 
    // It alternates between left-to-right and right-to-left traversal at each level.
    // 
    // 🕒 Time Complexity: O(N), where N is the number of nodes in the tree, since we visit each node once.
    // 🗂️ Space Complexity: O(N), for the queue and result storage.

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;  // Final result to store the zigzag level order traversal
        if (!root) return result;    // If the tree is empty, return an empty result

        bool isLeftToRight = true;   // Flag to track direction of traversal
        queue<TreeNode*> q;          // Queue for BFS traversal
        q.push(root);                // Start with the root node in the queue

        while (!q.empty()) {
            int width = q.size();                // Number of nodes in the current level
            vector<int> levelOrder(width);       // Vector to store nodes at the current level

            for (int i = 0; i < width; i++) {
                TreeNode* front = q.front(); q.pop();  // Get the front node in the queue
                int index = isLeftToRight ? i : (width - i - 1);  // Determine insertion index based on direction
                levelOrder[index] = front->val;        // Store the node value in the correct position

                // Push the left and right children of the current node (if they exist) into the queue
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }

            // Toggle the direction for the next level
            isLeftToRight = !isLeftToRight;

            // Add the current level's nodes to the result
            result.push_back(levelOrder);
        }

        return result;  // Return the final zigzag traversal result
    }
};

// Example main function to test zigzag level order traversal
int main() {
    // Example binary tree construction for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    // Output the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Sample Input:
    Tree structure:
          3
         / \
        9  20
           / \
          15  7

Sample Output:
3 
20 9 
15 7 
*/
