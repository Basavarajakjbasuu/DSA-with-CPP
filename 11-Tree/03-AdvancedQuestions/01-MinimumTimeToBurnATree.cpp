#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// 🚧 Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 📜 Helper function to create a mapping of nodes to their parents
    // and find the target node in the binary tree.
    // Algorithm:
    // 1️⃣ Start with the root node and initialize an empty queue for BFS.
    // 2️⃣ Create a mapping from each node to its parent.
    // 3️⃣ Traverse the tree using BFS:
    //    a. If the current node is the target node, store it.
    //    b. For each child of the current node, add it to the queue and update the parent map.
    // 4️⃣ Return the target node after the traversal is complete.
    Node* makeNodeToParentMappingAndFindTheTargetNode(Node* root, unordered_map<Node*, Node*>& parentMap, int target) {
        if (!root) return nullptr;  // 🛑 Base case: If root is null, return nullptr.

        queue<Node*> nodeQueue;  // 🗂️ Queue for BFS traversal.
        Node* targetNode = nullptr;  // 🌟 Variable to hold the target node.
        nodeQueue.push(root);
        parentMap[root] = nullptr;  // 📌 Root has no parent.

        while (!nodeQueue.empty()) {
            Node* currentNode = nodeQueue.front();
            nodeQueue.pop();

            if (currentNode->data == target) {
                targetNode = currentNode;  // 🎯 Target node found.
            } 
            if (currentNode->left) {
                nodeQueue.push(currentNode->left);
                parentMap[currentNode->left] = currentNode;  // 📜 Map left child to current node.
            }
            if (currentNode->right) {
                nodeQueue.push(currentNode->right);
                parentMap[currentNode->right] = currentNode;  // 📜 Map right child to current node.
            }
        }

        return targetNode;  // ✅ Return the target node.
    }

    // 🔥 Function to calculate the minimum time to burn the tree from the target node.
    // Algorithm:
    // 1️⃣ Start with the target node and initialize a queue for BFS.
    // 2️⃣ Create a mapping to track burnt nodes.
    // 3️⃣ Add the target node to the queue and mark it as burnt.
    // 4️⃣ While there are nodes in the queue:
    //    a. Process all nodes at the current level.
    //    b. For each node, check its left child, right child, and parent:
    //       - If any of these nodes are not burnt, mark them as burnt and add them to the queue.
    //    c. If any fire spread occurs at this level, increment the time.
    // 5️⃣ Continue until all nodes are burnt and return the total time taken.
    int burnTree(Node* targetNode, unordered_map<Node*, Node*>& parentMap) {
        if (!targetNode) return 0;  // 🛑 Base case: If target node is null, return 0.

        unordered_map<Node*, bool> isBurnt;  // 🔥 Map to track burnt nodes.
        queue<Node*> nodeQueue;  // 🗂️ Queue for BFS traversal.
        int timeTaken = 0;  // ⏳ Variable to keep track of time.
        nodeQueue.push(targetNode);
        isBurnt[targetNode] = true;  // 🔥 Mark the target node as burnt.

        while (!nodeQueue.empty()) {
            int size = nodeQueue.size();  // 📏 Get the number of nodes at the current level.
            bool isFireSpreaded = false;  // 📈 Track if fire has spread at this level.

            for (int i = 0; i < size; i++) {
                Node* currentNode = nodeQueue.front();
                nodeQueue.pop();

                // 🔄 Check and burn left child.
                if (currentNode->left && !isBurnt[currentNode->left]) {
                    nodeQueue.push(currentNode->left);
                    isBurnt[currentNode->left] = true;
                    isFireSpreaded = true;  // 🔥 Fire spread to left child.
                }
                // 🔄 Check and burn right child.
                if (currentNode->right && !isBurnt[currentNode->right]) {
                    nodeQueue.push(currentNode->right);
                    isBurnt[currentNode->right] = true;
                    isFireSpreaded = true;  // 🔥 Fire spread to right child.
                }
                // 🔄 Check and burn parent node.
                if (parentMap[currentNode] && !isBurnt[parentMap[currentNode]]) {
                    nodeQueue.push(parentMap[currentNode]);
                    isBurnt[parentMap[currentNode]] = true;
                    isFireSpreaded = true;  // 🔥 Fire spread to parent.
                }
            }
            if (isFireSpreaded) {
                ++timeTaken;  // 🕒 Increase time if fire spread in this round.
            }
        }

        return timeTaken;  // ✅ Return total time taken to burn the tree.
    }

    // 📅 Main function to calculate the minimum time to burn the tree starting from the target node.
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentMap;  // 📜 Map to hold parent-child relationships.
        Node* targetNode = makeNodeToParentMappingAndFindTheTargetNode(root, parentMap, target);  // 🔍 Find the target node.
        return burnTree(targetNode, parentMap);  // 🔥 Start burning the tree and return time taken.
    }
};

// 🏁 Main function for testing
int main() {
    Solution solution;

    // 🧪 Example test case: Creating a sample binary tree

    /*
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right = new Node(6);
    root->right->right->right = new Node(9);
    root->right->right->right->right = new Node(10);

    int targetValue = 8;  // 🔍 Target node to start burning
    // 📤 Output the minimum time to burn the tree from the target node
    int result = solution.minTime(root, targetValue);
    cout << "Minimum time to burn the tree: " << result << " units" << endl;

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the tree. Each node is processed once.

💾 Space Complexity:
- O(n), for the parent map and queue used for BFS traversal.

📊 Example Output Explanation:
- Given the binary tree:
                  1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
*/
