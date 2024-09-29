#include <iostream>
using namespace std;

// 🌳 Structure of the Binary Tree Node
struct Node {
    int key;
    Node *left, *right;
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * Algorithm to find the Predecessor and Successor in a BST 🌿
     * 1️⃣ If the root node’s value matches the key:
     *     - Find the maximum value in the left subtree (predecessor) 🍃.
     *     - Find the minimum value in the right subtree (successor) 🌿.
     * 2️⃣ If the key is smaller than the current node’s key:
     *     - The current node could be the successor, so store it 📝.
     *     - Move to the left subtree and continue searching 🍃.
     * 3️⃣ If the key is larger than the current node’s key:
     *     - The current node could be the predecessor, so store it 📝.
     *     - Move to the right subtree and continue searching 🌿.
     * 
     * Time Complexity: O(h), where h is the height of the BST 🕒.
     * Space Complexity: O(h) for recursive stack, where h is the height of the BST 🧠.
     */

    // 🌿 Function to find the predecessor and successor of the key in BST
    void findPredecessorAndSuccessor(Node* root, Node*& predecessor, Node*& successor, int key) {
        if (!root) return;  // Base case 🍂

        if (root->key == key) {
            // 🌟 Found the node with the key
            
            // 🍃 Find the maximum value in the left subtree (predecessor)
            if (root->left) {
                Node* temp = root->left;
                while (temp->right) temp = temp->right;
                predecessor = temp;
            }
            
            // 🌿 Find the minimum value in the right subtree (successor)
            if (root->right) {
                Node* temp = root->right;
                while (temp->left) temp = temp->left;
                successor = temp;
            }
            return;
        }
        
        if (key < root->key) {
            // 🌳 If key is smaller, move left and update successor
            successor = root;  // Current node could be successor
            findPredecessorAndSuccessor(root->left, predecessor, successor, key);
        } else {
            // 🌳 If key is larger, move right and update predecessor
            predecessor = root;  // Current node could be predecessor
            findPredecessorAndSuccessor(root->right, predecessor, successor, key);
        }
    }
};

// 🌟 Driver code to test the function
int main() {
    // Creating a simple binary search tree 🌳
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    // 🌟 Create an instance of Solution class
    Solution sol;

    // Variables to store predecessor and successor
    Node* predecessor = nullptr;
    Node* successor = nullptr;

    // 🌿 Key to find predecessor and successor
    int key = 65;

    // 🌟 Finding the predecessor and successor
    sol.findPredecessorAndSuccessor(root, predecessor, successor, key);

    if (predecessor)
        cout << "Predecessor of " << key << " is " << predecessor->key << endl;
    else
        cout << "Predecessor does not exist" << endl;

    if (successor)
        cout << "Successor of " << key << " is " << successor->key << endl;
    else
        cout << "Successor does not exist" << endl;

    return 0;
}

/**
 * Output Explanation 🌟:
 * Given the binary search tree, the key to search is 65.
 * In this BST, 60 is the predecessor (largest smaller than 65) and 70 is the successor (smallest larger than 65).
 * Hence, the output will be:
 * "Predecessor of 65 is 60"
 * "Successor of 65 is 70"
 */

// Time Complexity: O(h), where h is the height of the BST 🕒.
// Space Complexity: O(h) due t
