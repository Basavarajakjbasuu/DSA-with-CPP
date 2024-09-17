#include <iostream>
using namespace std;

// 🚧 Definition for a binary tree node
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 🛠️ Function to create a binary tree from user input
// Algorithm:
// 1️⃣ Read the value for the current node.
// 2️⃣ If the value is -1, return NULL (no node).
// 3️⃣ Create a new node with the read value.
// 4️⃣ Recursively create the left and right subtrees.
// 5️⃣ Return the newly created node.
TreeNode* createTree() {
    int nodeValue;
    cin >> nodeValue;

    // 🛑 Base case: If input is -1, return NULL
    if (nodeValue == -1) {
        return nullptr;
    }

    // ✨ Step 1: Create the new node
    TreeNode* newNode = new TreeNode(nodeValue);

    // 🔄 Step 2: Create the left subtree
    newNode->left = createTree();
    // 🔄 Step 3: Create the right subtree
    newNode->right = createTree();

    return newNode;
}

// 🌿 Function to print the left boundary of the binary tree
// Algorithm:
// 1️⃣ Print the value of the current node.
// 2️⃣ Recursively print the left boundary or if left is NULL, print the right boundary.
void printLeftBoundary(TreeNode* treeRoot) {
    if (treeRoot == nullptr) {
        return;
    }

    // 🛑 Base case: If it's a leaf node, don't print
    if (treeRoot->left == nullptr && treeRoot->right == nullptr) {
        return;
    }

    cout << treeRoot->value << " ";
    if (treeRoot->left != nullptr) {
        printLeftBoundary(treeRoot->left);
    } else {
        printLeftBoundary(treeRoot->right);
    }
}

// 🍂 Function to print leaf nodes of the binary tree
// Algorithm:
// 1️⃣ If the current node is a leaf, print its value.
// 2️⃣ Recursively print leaf nodes for left and right subtrees.
void printLeafBoundary(TreeNode* treeRoot) {
    if (treeRoot == nullptr) {
        return;
    }

    // 🌱 If it's a leaf node, print the value
    if (treeRoot->left == nullptr && treeRoot->right == nullptr) {
        cout << treeRoot->value << " ";
    }

    // 🔄 Recursively print leaves in the left and right subtrees
    printLeafBoundary(treeRoot->left);
    printLeafBoundary(treeRoot->right);
}

// 🍃 Function to print the right boundary of the binary tree
// Algorithm:
// 1️⃣ Recursively print the right boundary or if right is NULL, print the left boundary.
// 2️⃣ Print the current node's value after the recursive calls.
void printRightBoundary(TreeNode* treeRoot) {
    if (treeRoot == nullptr) {
        return;
    }

    // 🛑 Base case: If it's a leaf node, don't print
    if (treeRoot->left == nullptr && treeRoot->right == nullptr) {
        return;
    }

    if (treeRoot->right != nullptr) {
        printRightBoundary(treeRoot->right);
    } else {
        printRightBoundary(treeRoot->left);
    }
    cout << treeRoot->value << " ";
}

// 🏞️ Function to perform boundary traversal of the binary tree
// Algorithm:
// 1️⃣ Print the root node.
// 2️⃣ Print the left boundary, leaf nodes, and right boundary.
void boundaryTraversal(TreeNode* treeRoot) {
    if (treeRoot == nullptr) {
        return;
    }

    // ✨ Print the root node
    cout << treeRoot->value << " ";
    // 🔄 Print the left boundary
    printLeftBoundary(treeRoot->left);
    // 🔄 Print the leaf nodes
    printLeafBoundary(treeRoot->left);
    printLeafBoundary(treeRoot->right);
    // 🔄 Print the right boundary
    if (treeRoot->right != nullptr) {
        printRightBoundary(treeRoot->right);
    } else {
        printRightBoundary(treeRoot->left);
    }
}

// 🏁 Main function for testing
int main() {
    // ✨ Create a tree from user input
    TreeNode* root = createTree();

    // 📤 Perform boundary traversal and print the result
    boundaryTraversal(root); // Example output: 10 20 40 110 111 80 60 90 112 113 180 120 30 

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

💾 Space Complexity:
- O(h), where h is the height of the tree, due to recursive stack space.

📊 Example Output:
Input:10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 60 -1 -1 120 90 -1 -1 180 112 -1 -1 113 -1 -1
                          10
                        /    \
                      20      30
                     /  \    /  \
                   40   50  60  120 
                       /  \    /  \
                     70   80  90  180
                    /  \          /  \
                  110  111      112  113
output: 10 20 40 110 111 80 60 90 112 113 180 120 30 
*/
