#include <iostream>
#include <map>
#include <queue>
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

// 🏞️ Function to print the bottom view of the binary tree
// Algorithm:
// 1️⃣ Use a map to store nodes at different horizontal distances.
// 2️⃣ Perform a level order traversal using a queue, storing horizontal distance with each node.
// 3️⃣ Update the map with the current node's value.
// 4️⃣ Print the values from the map, which represent the bottom view.
void printBottomView(TreeNode* treeRoot) {
    // 📍 hd - horizontalDistance
    map<int, int> hdToNodeMap;
    queue<pair<TreeNode*, int>> nodeQueue;

    nodeQueue.push(make_pair(treeRoot, 0));

    while (!nodeQueue.empty()) {
        auto temp = nodeQueue.front();
        nodeQueue.pop();

        TreeNode* frontNode = temp.first;
        int hd = temp.second;

        // 🔄 Update the map to overwrite with deeper node if applicable
        hdToNodeMap[hd] = frontNode->value;

        if (frontNode->left != nullptr) {
            nodeQueue.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right != nullptr) {
            nodeQueue.push(make_pair(frontNode->right, hd + 1));
        }
    }

    cout << "Printing bottom view: ";
    for (const auto& entry : hdToNodeMap) {
        cout << entry.second << " ";
    }
    cout << endl;
}

// 🏁 Main function for testing
int main() {
    // ✨ Create a tree from user input
    TreeNode* root = createTree();

    // 📤 Print the bottom view of the tree
    printBottomView(root); // Example output: 110 70 111 80 112 90 113

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes. Each node is visited once during level order traversal.

💾 Space Complexity:
- O(w), where w is the width of the tree. Space used for storing nodes at each level.

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
Printing bottom view: 110 70 111 80 112 90 113
*/
