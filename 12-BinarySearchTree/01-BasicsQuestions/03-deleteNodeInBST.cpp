#include<iostream>
#include<queue>
using namespace std;

// ✨ Node class representing a single node in the Binary Search Tree (BST)
class Node {
public:
    int data;       // Data held by the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize node with a given value
    Node(int value) {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

// 📝 Algorithm: insertIntoBST
// 1. If the tree is empty (root is NULL), create a new node and return it.
// 2. Recursively insert the new node into the appropriate subtree (left for smaller, right for larger values).
// Time Complexity: O(log n) for balanced tree, O(n) for skewed tree.
// Space Complexity: O(h) due to recursion stack (h = height of the tree).
Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

// 📝 Algorithm: createBST
// Continuously take input from the user and build the BST using insertIntoBST.
// Stops taking input when -1 is entered.
// Time Complexity: O(n log n) for n nodes.
// Space Complexity: O(h) for the recursion depth in insertIntoBST.
void createBST(Node* &root) {
    cout << "Enter data: ";
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter data: ";
        cin >> data;
    }
}

// 📝 Algorithm: maxValue
// Traverse the rightmost path in the tree to find the maximum value node.
// Time Complexity: O(h), where h is the height of the tree.
// Space Complexity: O(1).
Node* maxValue(Node* root) {
    if (root == NULL) return root;
    Node* temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

// 📝 Algorithm: deleteFromBST
// 1. Find the node to be deleted.
// 2. Handle 4 cases: leaf node, node with one child, node with two children.
// 3. Replace the node's data with the largest value from the left subtree if both children exist.
// Time Complexity: O(log n) for balanced tree, O(n) for skewed tree.
// Space Complexity: O(h) for recursion depth.
Node* deleteFromBST(Node* root, int target) {
    if (root == NULL) 
        return NULL;

    if (target == root->data) {
        // Handle deletion cases
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL) {
            Node* childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        if (root->left == NULL && root->right != NULL) {
            Node* childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        // Both left and right children exist
        Node* maxNode = maxValue(root->left);
        root->data = maxNode->data;
        root->left = deleteFromBST(root->left, maxNode->data);
    } else if (root->data > target) {
        root->left = deleteFromBST(root->left, target);
    } else {
        root->right = deleteFromBST(root->right, target);
    }
    return root;
}

// 📝 Algorithm: levelOrderTraversal
// 1. Use a queue to process nodes level by level.
// 2. Print each node's data and enqueue its children.
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(n) for the queue.
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Marker for end of level

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;  // End of a level
            if (!q.empty()) {
                q.push(NULL); // Push marker for the next level
            }
        } else {
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

int main() {
    Node* root = NULL; // Start with an empty tree
    createBST(root);   // Build the BST

    cout << "Printing Level order traversal: " << endl;
    levelOrderTraversal(root);  // Print level-order

    int target;
    cout << "Enter target value to Delete: ";
    cin >> target;

    // Repeatedly delete nodes until user enters -1
    while (target != -1) {
        root = deleteFromBST(root, target);  // Delete the target node
        cout << "Printing Level order traversal: " << endl;
        levelOrderTraversal(root);  // Print updated level-order

        cout << "Enter target value to Delete: ";
        cin >> target;
    }

    return 0;
}

/*
Sample Output:
Enter data: 50
Enter data: 30
Enter data: 60
Enter data: 25
Enter data: 40
Enter data: 70
Enter data: 80
Enter data: 55
Enter data: -1
Printing Level order traversal: 
50 
30 60 
25 40 55 70 
80 
Enter target value to Delete: 80
Printing Level order traversal: 
50 
30 60 
25 40 55 70 
Enter target value to Delete: 70
Printing Level order traversal: 
50 
30 60 
25 40 55 
Enter target value to Delete: 60
Printing Level order traversal: 
50 
30 55 
25 40 
Enter target value to Delete: 30
Printing Level order traversal: 
50 
25 55 
40 
Enter target value to Delete: 50
Printing Level order traversal: 
40 
25 55 
Enter target value to Delete: -1
*/
