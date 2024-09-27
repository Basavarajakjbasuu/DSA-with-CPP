#include <iostream>
#include <utility>
using namespace std;

// 🌳 Definition for the binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 🌟 Algorithm to calculate the sum of the longest root-to-leaf path:
     * 1️⃣ Define a helper function `calculateHeightAndSum(Node* root)` that recursively calculates the height of the tree and the sum of the longest root-to-leaf path.
     * 2️⃣ If the node is NULL, return {0, 0}, representing the height and sum.
     * 3️⃣ Recursively calculate the height and sum of the left (`leftSubtree`) and right (`rightSubtree`) subtrees.
     * 4️⃣ Compare the heights:
     *    a) If the heights are equal, add the maximum sum of the left and right subtree to the current node's value.
     *    b) If one is taller, add that subtree's sum to the current node's value.
     * 5️⃣ Return a pair containing the updated height and the computed sum.
     * 6️⃣ In `sumOfLongestRootToLeafPath`, call the helper function and return the sum from the result.
     */

    pair<int, int> calculateHeightAndSum(Node* root) {
        if (!root) return {0, 0};  // 🛑 Base case: No node means height 0 and sum 0.

        // 🌱 Recursively calculate the height and sum of the left subtree.
        pair<int, int> leftSubtree = calculateHeightAndSum(root->left);

        // 🌱 Recursively calculate the height and sum of the right subtree.
        pair<int, int> rightSubtree = calculateHeightAndSum(root->right);

        int currentSum = root->data;  // 🌟 Initialize the sum as the current node's value.

        // 🔄 If the left and right subtrees have the same height, choose the subtree with the larger sum.
        if (leftSubtree.first == rightSubtree.first) {
            currentSum += max(leftSubtree.second, rightSubtree.second);
        }
        // 🔄 If the left subtree is taller, add its sum to the current node's value.
        else if (leftSubtree.first > rightSubtree.first) {
            currentSum += leftSubtree.second;
        }
        // 🔄 Otherwise, the right subtree is taller, so add its sum to the current node's value.
        else {
            currentSum += rightSubtree.second;
        }

        // 📏 Return the updated height and the computed sum.
        return {max(leftSubtree.first, rightSubtree.first) + 1, currentSum};
    }

    // 🌟 Function to find the sum of the longest root-to-leaf path.
    int sumOfLongestRootToLeafPath(Node* root) {
        return calculateHeightAndSum(root).second;  // 🎯 Return the sum from the result.
    }
};

// 🚀 Local execution example:
int main() {
    Solution solution;

    // 🏗️ Construct a sample binary tree:
    /*
         4        
       /   \       
      2     5      
     / \   / \     
    7   1 2   3  
       /
      6
    
    */
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(3);

    // 🧪 Call the function and print the result:
    int result = solution.sumOfLongestRootToLeafPath(root);
    cout << "Sum of the longest root-to-leaf path: " << result << endl;

    return 0;
}

/**
 * Output Example:
 * Sum of the longest root-to-leaf path: 13
 *
 * 🧠 Time Complexity: O(n) – Where n is the number of nodes in the tree (we visit each node once).
 * 🧠 Space Complexity: O(h) – Where h is the height of the tree (due to recursion stack).
 */
