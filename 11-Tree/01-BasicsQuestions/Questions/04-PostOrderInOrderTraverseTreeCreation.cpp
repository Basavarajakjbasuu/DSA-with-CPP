#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// 🗺️ Create a mapping of node values to their indices in the inOrder array
void createMapping(int inOrder[], int size, map<int, int> &valueToIndexMap) {
    for (int i = 0; i < size; i++) {
        int element = inOrder[i];
        valueToIndexMap[element] = i;
    }
}

// 🚀 Perform level order traversal of the tree
void levelOrderTraverse(Node *root) {
    queue<Node*> qu;
    qu.push(root);

    while (!qu.empty()) {
        Node* front = qu.front();
        qu.pop();

        cout << front->data << " ";

        if (front->left != NULL) {
            qu.push(front->left);
        }

        if (front->right != NULL) {
            qu.push(front->right);
        }
    }
}

// 🔍 Find the index of a target value in the inOrder array
int searchInOrder(int inOrder[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (inOrder[i] == target) {
            return i;
        }
    }
    return -1;
}

// 🌳 Algorithm to construct a binary tree from postOrder and inOrder traversals:
// 1️⃣ Base Case: If postIndex is out of bounds or inOrderStart > inOrderEnd, return NULL.
// 2️⃣ Create the root node from the current element in postOrder.
// 3️⃣ Find the index of the root node in the inOrder array using the precomputed map.
// 4️⃣ Recursively build the right subtree using the elements to the right of the root in inOrder.
// 5️⃣ Recursively build the left subtree using the elements to the left of the root in inOrder.
// 6️⃣ Return the constructed root node.

Node* constructTreeFromPostAndInOrderTraversal(map<int, int> &valToIndexMap, int postOrder[], int inOrder[], int &postIndex, int inOrderStart, int inOrderEnd, int size) {
    // BASE CASE
    if (postIndex < 0 || inOrderStart > inOrderEnd) {
        return NULL;
    }

    // 1️⃣ Construct the current node
    int element = postOrder[postIndex];
    postIndex--;
    Node* root = new Node(element);
    
    // Find the index of the current element in inOrder
    int position = valToIndexMap[element];

    // RECURSION: Build right and left subtrees
    root->right = constructTreeFromPostAndInOrderTraversal(valToIndexMap, postOrder, inOrder, postIndex, position + 1, inOrderEnd, size);
    root->left = constructTreeFromPostAndInOrderTraversal(valToIndexMap, postOrder, inOrder, postIndex, inOrderStart, position - 1, size);

    return root;
}

int main() {
    int inOrder[] = {10, 8, 6, 2, 4, 12};
    int postOrder[] = {8, 6, 4, 12, 10, 2};
    int size = 6;
    int postOrderIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;

    map<int, int> valToIndexMap;
    createMapping(inOrder, size, valToIndexMap);
    Node* root = constructTreeFromPostAndInOrderTraversal(valToIndexMap, postOrder, inOrder, postOrderIndex, inOrderStart, inOrderEnd, size);

    cout << "Printing entire tree: " << endl;
    levelOrderTraverse(root);
    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the tree. Each node is processed once.

💾 Space Complexity:
- O(n), where n is the number of nodes in the tree. This includes space for the recursion stack and the map.

📊 Example Output:
Printing entire tree: 
2 8 4 10 6 12
*/
