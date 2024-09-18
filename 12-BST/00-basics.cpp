#include<iostream>
#include<queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
public:
    // 🌱 Function to insert a new node into the BST.
    // 1️⃣ Base case: If the root is NULL, create a new node and return it.
    // 2️⃣ If the value to insert is greater than the root, move to the right subtree.
    // 3️⃣ If the value is smaller, move to the left subtree.
    Node* insertIntoBST(Node* root, int data) {
        if (root == NULL) {
            root = new Node(data);  // Create a new node if the tree is empty.
            return root;
        }

        if (data > root->data) {
            root->right = insertIntoBST(root->right, data);  // Insert in right subtree if value is greater.
        } else {
            root->left = insertIntoBST(root->left, data);  // Insert in left subtree if value is smaller.
        }

        return root;
    }

    // 🌳 Function to print the level-order traversal (breadth-first traversal) of the tree.
    // 1️⃣ We use a queue to track nodes level by level.
    // 2️⃣ For each level, we print the nodes and enqueue their children.
    // 3️⃣ NULL is used as a marker for the end of each level.
    void levelOrderTraversal(Node* root) {
        if (root == nullptr) return;  // 🛑 If the tree is empty, return.

        queue<Node*> q;  // Queue for BFS.
        q.push(root);
        q.push(nullptr);  // Null marker to indicate end of the current level.

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp == NULL) {
                cout << endl;  // Move to the next line for new level.
                if (!q.empty()) {
                    q.push(nullptr);  // Add a new level marker if more nodes are left.
                }
            } else {
                cout << temp->data << " ";  // Print current node's data.

                if (temp->left != nullptr)
                    q.push(temp->left);  // Enqueue left child.

                if (temp->right != nullptr)
                    q.push(temp->right);  // Enqueue right child.
            }
        }
    }

    // 🌱 Function to create a Binary Search Tree (BST).
    // The user keeps entering data until they input -1 to stop.
    void createBST(Node*& root) {
        cout << "Enter data (enter -1 to stop): ";
        int data;
        cin >> data;

        while (data != -1) {
            root = insertIntoBST(root, data);  // Insert each new value into the BST.
            cout << "Enter data: ";
            cin >> data;
        }
    }
};

// 🧪 Example usage for testing
int main() {
    Solution solution;
    Node* root = nullptr;  // Create an empty tree.

    // 🌱 Create the Binary Search Tree (BST) from user input.
    solution.createBST(root);

    // 🌳 Perform level-order traversal (BFS) and print each level.
    cout << "\nLevel Order Traversal: \n";
    solution.levelOrderTraversal(root);

    return 0;
}

/*
⏳ Time Complexity:
- Insertion: O(h), where h is the height of the tree (O(log n) in balanced BSTs, O(n) in worst case).
- Level Order Traversal: O(n), where n is the number of nodes in the tree.

💾 Space Complexity:
- Insertion: O(h), due to the recursive stack (O(log n) for balanced trees).
- Level Order Traversal: O(n), due to the queue storing nodes.

📊 Example Input:
  Enter data: 50
  Enter data: 30
  Enter data: 20
  Enter data: 25
  Enter data: 40
  Enter data: 60
  Enter data: 70
  Enter data: 80
  Enter data: 55
  Enter data: -1

📊 Example Output:
  Level Order Traversal:
  50
  30 60
  20 40 55 70
  25 80
*/
