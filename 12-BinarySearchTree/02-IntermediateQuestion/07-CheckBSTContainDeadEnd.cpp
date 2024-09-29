#include <iostream>
#include <unordered_map>
using namespace std;

// 🌳 Definition for the Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// 🌟 Class to check if there is a dead-end in a Binary Search Tree (BST)
class Solution {
public:
    /**
     * 🌟 Algorithm to detect a dead-end in the BST:
     * 1️⃣ Use a recursive function to traverse the tree.
     * 2️⃣ Use a hashmap (unordered_map) to keep track of visited nodes.
     * 3️⃣ If a leaf node is found, check if both its neighbors (data+1, data-1) are visited.
     * 4️⃣ If both neighbors are visited, a dead-end exists at this node.
     * 
     * Time Complexity: O(n) 🕒 (linear traversal of the tree).
     * Space Complexity: O(n) 🧠 (hashmap to store node values).
     */
    void detectDeadEnd(Node* root, unordered_map<int, bool>& visitedNodes, bool& isDeadEnd) {
        if (!root) return;  // Base case: Null node, nothing to do
        
        // Mark the current node's data as visited
        visitedNodes[root->data] = true;

        // Check for leaf nodes and verify neighbors
        if (root->left == NULL && root->right == NULL) {
            int nextPlus1 = root->data + 1;   // Next data (+1)
            int nextMinus1 = root->data - 1 == 0 ? root->data : root->data - 1;  // Previous data (-1, handling root case)

            if (visitedNodes.find(nextPlus1) != visitedNodes.end() && visitedNodes.find(nextMinus1) != visitedNodes.end()) {
                isDeadEnd = true;  // Found dead-end, set the flag to true
                return;
            }
        }

        // Recursively check the left and right subtrees
        detectDeadEnd(root->left, visitedNodes, isDeadEnd);
        detectDeadEnd(root->right, visitedNodes, isDeadEnd);
    }

    // Function to check if the tree has a dead-end
    bool isDeadEnd(Node* root) {
        bool isDeadEnd = false;  // Flag to indicate dead-end detection
        unordered_map<int, bool> visitedNodes;  // Hashmap to track visited nodes
        detectDeadEnd(root, visitedNodes, isDeadEnd);  // Start the dead-end detection process

        return isDeadEnd;
    }
};

// 🌟 Driver code for local execution
int main() {
    Solution solution;

    // 🌳 Example tree (BST)
    /*
          10
         /  \
        5   20
       / \
      1   7
    */
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(1);
    root->left->right = new Node(7);

    // 🛠 Check if the BST has a dead-end
    bool result = solution.isDeadEnd(root);

    // 📝 Print the result (expected: false, as there is no dead-end in this tree)
    cout << "Is there a dead-end in the BST? " << (result ? "Yes" : "No") << endl;

    return 0;
}

/**
 * Example Output:
 * Is there a dead-end in the BST? No
 * 
 * Explanation of Output:
 * - The BST doesn't have any dead-end nodes where the neighbors are blocked by other nodes.
 */

// Time Complexity: O(n) 🕒 (linear traversal of the tree).
// Space Complexity: O(n) 🧠 (due to the hashmap used for tracking node values).
