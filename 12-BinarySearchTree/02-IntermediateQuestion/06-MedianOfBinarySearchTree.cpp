#include <iostream>
using namespace std;

// 🌳 Definition for the Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// 🌟 Class to find the median of a Binary Search Tree (BST)
class Solution {
public:
    /**
     * 🌟 Algorithm to find the number of nodes in the BST:
     * 1️⃣ Use Morris traversal (threaded binary tree) to traverse the tree without recursion or stack.
     * 2️⃣ Count the nodes while performing the traversal.
     * 
     * Time Complexity: O(n) 🕒 (linear traversal of the tree).
     * Space Complexity: O(1) 🧠 (only a few auxiliary variables are used).
     */
    int countNodes(Node* root) {
        int nodeCount = 0;
        Node* currentNode = root;

        while (currentNode) {
            if (currentNode->left == NULL) {
                // Visit the current node and move to the right subtree
                ++nodeCount;
                currentNode = currentNode->right;
            } else {
                // Find the inorder predecessor of current node
                Node* predecessor = currentNode->left;
                while (predecessor->right != currentNode && predecessor->right) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == NULL) {
                    // Create a thread (temporary link) to return later
                    predecessor->right = currentNode;
                    currentNode = currentNode->left;
                } else {
                    // Remove the thread and move to the right subtree
                    predecessor->right = NULL;
                    ++nodeCount;
                    currentNode = currentNode->right;
                }
            }
        }

        return nodeCount;
    }

    /**
     * 🌟 Algorithm to find the median of the BST:
     * 1️⃣ Perform Morris traversal to locate the median position(s).
     * 2️⃣ If the number of nodes is odd, return the middle node's value.
     * 3️⃣ If the number of nodes is even, return the average of the two middle nodes' values.
     * 
     * Time Complexity: O(n) 🕒 (linear traversal of the tree).
     * Space Complexity: O(1) 🧠 (no extra space except variables).
     */
    float findMedian(Node* root, int totalNodes) {
        int currentIndex = 0;
        int oddMiddleIdx = (totalNodes + 1) / 2, oddValue = -1;
        int evenFirstIdx = totalNodes / 2, evenValue1 = -1;
        int evenSecondIdx = (totalNodes / 2) + 1, evenValue2 = -1;
        Node* currentNode = root;

        while (currentNode) {
            if (currentNode->left == NULL) {
                ++currentIndex;
                if (currentIndex == oddMiddleIdx) oddValue = currentNode->data;
                if (currentIndex == evenFirstIdx) evenValue1 = currentNode->data;
                if (currentIndex == evenSecondIdx) evenValue2 = currentNode->data;
                currentNode = currentNode->right;
            } else {
                Node* predecessor = currentNode->left;
                while (predecessor->right != currentNode && predecessor->right) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == NULL) {
                    predecessor->right = currentNode;
                    currentNode = currentNode->left;
                } else {
                    predecessor->right = NULL;
                    ++currentIndex;
                    if (currentIndex == oddMiddleIdx) oddValue = currentNode->data;
                    if (currentIndex == evenFirstIdx) evenValue1 = currentNode->data;
                    if (currentIndex == evenSecondIdx) evenValue2 = currentNode->data;
                    currentNode = currentNode->right;
                }
            }
        }

        if (totalNodes % 2 == 0) {
            return (evenValue1 + evenValue2) / 2.0;  // 🧮 For even number of nodes, return the average of two middle values
        } else {
            return oddValue;  // 🧮 For odd number of nodes, return the middle value
        }
    }

    // Main function to compute the median
    float computeBSTMedian(Node* root) {
        int totalNodes = countNodes(root);  // 🌟 Step 1: Count the number of nodes
        return findMedian(root, totalNodes);  // 🌟 Step 2: Find and return the median value
    }
};

// 🌟 Driver code for local execution
int main() {
    Solution solution;

    // 🌳 Example tree (BST)
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(1);
    root->right->right = new Node(30);

    // 🛠 Find the median of the BST
    float median = solution.computeBSTMedian(root);

    // 📝 Print the median (expected: 10, as the tree is [1, 5, 10, 20, 30])
    cout << "Median of the BST is: " << median << endl;

    return 0;
}

/**
 * Example Output:
 * Median of the BST is: 10
 * 
 * Explanation of Output:
 * - The BST has 5 nodes: [1, 5, 10, 20, 30].
 * - The median is the middle element in the sorted order, which is 10.
 */

// Time Complexity: O(n) 🕒 (for counting nodes and finding the median via Morris traversal).
// Space Complexity: O(1) 🧠 (Morris traversal uses constant space with no extra space for recursion or stacks).
