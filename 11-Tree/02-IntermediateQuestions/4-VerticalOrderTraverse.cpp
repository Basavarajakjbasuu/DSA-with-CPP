#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    // Pair structure to hold node value and its coordinates
    struct Pair {
        int val;
        int x; // Horizontal distance from the root
        int y; // Vertical distance from the root
        Pair(int v, int _x, int _y) : val(v), x(_x), y(_y) {}
    };

    // Custom comparator to sort the pairs in the priority queue
    struct Compare {
        bool operator() (const Pair& a, const Pair& b) {
            if (a.x != b.x) return a.x > b.x; // Sort by x-coordinate
            else if (a.y != b.y) return a.y > b.y; // Sort by y-coordinate
            else return a.val > b.val; // Sort by node value
        }
    };

    // 📝 Algorithm explanation: 
    // The function performs vertical traversal of the binary tree. 
    // A DFS is used to collect nodes in a priority queue sorted by their coordinates 
    // and values, and then organizes the output based on their x-coordinates.
    // 
    // 🕒 Time Complexity: O(N log N), where N is the number of nodes, due to sorting in the priority queue.
    // 🗂️ Space Complexity: O(N), for the priority queue and the result vector.

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        priority_queue<Pair, vector<Pair>, Compare> pq;
        dfs(root, 0, 0, pq); // Start DFS with root at (0, 0)

        // Grouping nodes by their x-coordinate
        while (!pq.empty()) {
            int curr_X = pq.top().x;
            vector<int> level;

            while (!pq.empty() && pq.top().x == curr_X) {
                level.push_back(pq.top().val);
                pq.pop();
            }

            result.push_back(level);
        }
        return result;
    }

    // DFS function to populate the priority queue with node data
    void dfs(TreeNode* root, int x, int y, priority_queue<Pair, vector<Pair>, Compare>& pq) {
        if (!root) return;

        pq.push(Pair(root->val, x, y)); // Store the current node
        dfs(root->left, x - 1, y + 1, pq); // Traverse left child
        dfs(root->right, x + 1, y + 1, pq); // Traverse right child
    }
};

// Example main function for testing
int main() {
    // Example tree construction for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution solution;
    vector<vector<int>> result = solution.verticalTraversal(root);

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
    Tree Structure:
          1
         / \
        2   3
       / \   \
      4   5   6

Sample Output:
4 
2 
1 5 
3 
6 
*/
