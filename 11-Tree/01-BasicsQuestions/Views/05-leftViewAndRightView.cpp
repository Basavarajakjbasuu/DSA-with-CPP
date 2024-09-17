#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// 🌳 Algorithm to create a binary tree from user input:
// 1️⃣ Read a value from the user.
// 2️⃣ If the value is -1, return NULL to indicate no node.
// 3️⃣ Create a new node with the given value.
// 4️⃣ Recursively create the left and right subtrees.
// 5️⃣ Return the newly created node.

Node* createTree() {
    int data;
    cin >> data;

    // If the input is -1, it means no node should be created.
    if (data == -1) {
        return NULL;
    }

    // Create a new node with the input value.
    Node* newNode = new Node(data);

    // Recursively create the left and right subtrees.
    newNode->left = createTree();
    newNode->right = createTree();

    return newNode;
}

// 🔍 Algorithm for preOrder traversal (NLR):
// 1️⃣ Print the root node's data.
// 2️⃣ Recursively traverse the left subtree.
// 3️⃣ Recursively traverse the right subtree.

void preOrder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 🔍 Algorithm for inOrder traversal (LNR):
// 1️⃣ Recursively traverse the left subtree.
// 2️⃣ Print the root node's data.
// 3️⃣ Recursively traverse the right subtree.

void inOrder(Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// 🔍 Algorithm for postOrder traversal (LRN):
// 1️⃣ Recursively traverse the left subtree.
// 2️⃣ Recursively traverse the right subtree.
// 3️⃣ Print the root node's data.

void postOrder(Node* root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// 🔍 Algorithm for levelOrder traversal:
// 1️⃣ Use a queue to keep track of nodes at each level.
// 2️⃣ Enqueue the root node and a NULL marker.
// 3️⃣ Dequeue a node and print its data.
// 4️⃣ Enqueue its left and right children, if they exist.
// 5️⃣ When a NULL marker is reached, print a newline and enqueue another NULL marker if the queue is not empty.

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

// 🔍 Algorithm to print the left view of the tree:
// 1️⃣ Use a recursive approach to visit nodes level by level.
// 2️⃣ Track the current level using the 'level' parameter.
// 3️⃣ Add the first node of each level to the leftView vector.
// 4️⃣ Traverse the left and right subtrees.

void printLeftView(Node* root, int level, vector<int>& leftView) {
    if (root == NULL)
        return;

    if (level == leftView.size()) {
        leftView.push_back(root->data);
    }

    printLeftView(root->left, level + 1, leftView);
    printLeftView(root->right, level + 1, leftView);
}

// 🔍 Algorithm to print the right view of the tree:
// 1️⃣ Use a recursive approach to visit nodes level by level.
// 2️⃣ Track the current level using the 'level' parameter.
// 3️⃣ Add the first node of each level from the right side to the rightView vector.
// 4️⃣ Traverse the right and left subtrees.

void printRightView(Node* root, int level, vector<int>& rightView) {
    if (root == NULL)
        return;

    if (level == rightView.size()) {
        rightView.push_back(root->data);
    }

    printRightView(root->right, level + 1, rightView);
    printRightView(root->left, level + 1, rightView);
}

int main() {
    // Create the tree based on user input.
    Node* root = createTree();
    
    // Print the left view of the tree.
    vector<int> leftView;
    printLeftView(root, 0, leftView);
    cout << "Printing Left view: " << endl;
    for (int i = 0; i < leftView.size(); i++) {
        cout << leftView[i] << " ";
    }
    cout << endl;

    // Print the right view of the tree.
    vector<int> rightView;
    printRightView(root, 0, rightView);
    cout << "Printing Right view: " << endl;
    for (int i = 0; i < rightView.size(); i++) {
        cout << rightView[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

💾 Space Complexity:
- O(h), where h is the height of the tree. This accounts for recursion stack space and storage for views.

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

Printing Left view:
10 20 40 70 110 

Printing Right view:
10 30 120 180 113
*/
