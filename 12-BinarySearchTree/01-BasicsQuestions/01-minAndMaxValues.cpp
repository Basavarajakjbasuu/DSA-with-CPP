#include<iostream>
using namespace std;

// ✨ Node class for Binary Search Tree (BST)
class Node {
public:
    int data; // Data of the node
    Node* left; // Left child pointer
    Node* right; // Right child pointer

    // Constructor to initialize node with data and null children
    Node(int value) {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

// 📝 Algorithm: insertIntoBST
// 1. If the root is NULL, create a new node and return it.
// 2. Otherwise, recursively call insertIntoBST based on whether the new data is greater or lesser than the root.
// 3. If the data is greater, move to the right subtree; if lesser, move to the left subtree.
// 4. Continue until the correct position is found.
// Time Complexity: O(log n) for balanced BST, O(n) for skewed BST.
// Space Complexity: O(h) where h is the height of the tree due to recursion stack.
Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

// 📝 Algorithm: createBST
// Continuously read input and insert data into the BST until -1 is encountered.
// Time Complexity: O(n log n) for balanced tree insertions.
// Space Complexity: O(h) for recursion depth in insertIntoBST.
void createBST(Node* &root) {
    cout << "Enter data: ";
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter data: ";
        cin >> data;
    }
}

// 📝 Algorithm: minValue
// 1. Traverse the leftmost path of the tree to find the minimum value.
// 2. If the left pointer of the current node is NULL, that node holds the minimum value.
// Time Complexity: O(h), where h is the height of the tree.
// Space Complexity: O(1).
Node* minValue(Node* root) {
    if(root == NULL) return root;

    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

// 📝 Algorithm: maxValue
// 1. Traverse the rightmost path of the tree to find the maximum value.
// 2. If the right pointer of the current node is NULL, that node holds the maximum value.
// Time Complexity: O(h), where h is the height of the tree.
// Space Complexity: O(1).
Node* maxValue(Node* root) {
    if(root == NULL) return root;

    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp;
}

int main() {
    Node* root = NULL; // Create an empty tree
    createBST(root); // Build the BST

    cout << endl;
    Node* minNode = minValue(root);
    Node* maxNode = maxValue(root);

    if(minNode == NULL) {
        cout << "Oops! no min value." << endl;
    } else {
        cout << "Minimum value is: " << minNode->data << endl;
    }

    if(maxNode == NULL) {
        cout << "Oops! no max value." << endl;
    } else {
        cout << "Maximum value is: " << maxNode->data << endl;
    }

    return 0;
}

/*
Sample Output:
Enter data: 50
Enter data: 30
Enter data: 60
Enter data: 20
Enter data: -40
Enter data: 420
Enter data: 23
Enter data: -1

Minimum value is: -40
Maximum value is: 420
*/
