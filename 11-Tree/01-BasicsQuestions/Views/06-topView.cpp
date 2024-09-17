#include <iostream>
#include <queue>
#include <map>

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
    // 🔍 Algorithm to print the top view of a binary tree:
    // 1️⃣ Use a level-order traversal approach (BFS) to ensure we visit nodes in level order.
    // 2️⃣ Track the horizontal distance (hd) from the root for each node.
    // 3️⃣ Store the first node encountered at each hd in a map.
    // 4️⃣ Finally, print the nodes from leftmost to rightmost horizontal distance.
    
    void printTopView(TreeNode* root) {
        if (root == NULL) return;  // 🛑 If the tree is empty, return.

        // 🗺️ Map to store the first node encountered at each horizontal distance.
        map<int, int> hdToNodeMap;
        
        // 📊 Queue for level-order traversal, storing nodes along with their horizontal distance.
        queue<pair<TreeNode*, int>> q;

        // 🌟 Start with the root node at horizontal distance 0.
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            pair<TreeNode*, int> temp = q.front();
            q.pop();

            TreeNode* currentNode = temp.first;
            int hd = temp.second;

            // If there is no entry for this horizontal distance, store the node value.
            if (hdToNodeMap.find(hd) == hdToNodeMap.end()) {
                hdToNodeMap[hd] = currentNode->val;
            }

            // 🚶 Traverse the left child with hd - 1.
            if (currentNode->left != NULL) {
                q.push(make_pair(currentNode->left, hd - 1));
            }

            // 🚶 Traverse the right child with hd + 1.
            if (currentNode->right != NULL) {
                q.push(make_pair(currentNode->right, hd + 1));
            }
        }

        // 🎯 Print the top view nodes in order of horizontal distance.
        cout << "Top View: ";
        for (auto it : hdToNodeMap) {
            cout << it.second << " ";
        }
        cout << endl;
    }
};

// 🧪 Example usage for testing
int main() {
    Solution solution;

    // Create a sample binary tree:
    //          10
    //         /  \
    //       20    30
    //      /  \     \
    //     40  50     60
    //         /        \
    //       70         90
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->right = new TreeNode(60);
    root->left->right->left = new TreeNode(70);
    root->right->right->right = new TreeNode(90);

    // Call the function to print the top view.
    solution.printTopView(root);

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

💾 Space Complexity:
- O(n), where n is the number of nodes, due to storing nodes in the queue and the map.

📊 Example Output:
Top View: 40 20 10 30 60 90
*/
