#include <iostream>
using namespace std;

// 🌳 Structure of the Binary Tree Node
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    /**
     * Algorithm to find Inorder Successor in a BST 🌿
     * 1️⃣ Start from the root of the BST.
     * 2️⃣ If the current node's value is greater than the target node's value (x->data), 
     *     then the current node could be the successor, so store it and move to the left subtree 🌳.
     * 3️⃣ If the current node's value is less than or equal to the target node's value (x->data),
     *     move to the right subtree, as the successor will lie in that direction 🌿.
     * 4️⃣ Continue this process until the node is found or null is reached 🍃.
     * 5️⃣ Return the last stored node as the inorder successor.
     * 
     * Time Complexity: O(h) where h is the height of the BST 🕒.
     * Space Complexity: O(1) since no extra space apart from pointers is used 🧠.
     */
     
    // 🌿 Function to return the inorder successor of the Node 'target' in a BST (rooted at 'root')
    Node* findInorderSuccessor(Node* root, Node* targetNode) {
        Node* currentNode = root;
        Node* successor = nullptr; // Pointer to store the successor

        // 🌳 Traverse the tree to find the inorder successor
        while (currentNode) {
            if (currentNode->data > targetNode->data) {
                // If current node's value is greater, it could be a successor
                successor = currentNode;
                currentNode = currentNode->left;  // Move to left subtree 🌿
            } else {
                // Otherwise, move to right subtree 🌳
                currentNode = currentNode->right;
            }
        }
        return successor;
    }
};

// 🌟 Driver code to test the function
int main() {
    // Creating a simple binary search tree 🌳
    /*
           20
          / \
        10   30
       / \    \
      5   15   35    
    */
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(35);

    // 🌟 Create an instance of Solution class
    Solution sol;

    // 🌿 Node to find the successor of
    Node* targetNode = root->left->right; // Node with value 15

    // 🌟 Finding the inorder successor
    Node* successor = sol.findInorderSuccessor(root, targetNode);

    if (successor)
        cout << "Inorder Successor of " << targetNode->data << " is " << successor->data << endl;
    else
        cout << "Inorder Successor does not exist" << endl;

    return 0;
}

/**
 * Output Explanation 🌟:
 * 
 * Given the binary search tree, the inorder traversal would be: 5, 10, 15, 20, 30, 35.
 * The inorder successor of node with value 15 is 20, since 20 comes immediately after 15 in the traversal.
 * Hence, the output will be:
 * "Inorder Successor of 15 is 20"
 */
