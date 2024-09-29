#include <iostream>
#include <stack>
using namespace std;

// 🌳 Definition for the binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * Algorithm to count pairs with a given sum across two BSTs 🌟:
     * 1️⃣ Use two stacks, `stack1` for an in-order traversal of tree1 (left subtree first) 
     *    and `stack2` for a reverse in-order traversal of tree2 (right subtree first).
     * 2️⃣ Traverse both trees:
     *     - Push nodes onto respective stacks until the smallest (tree1) and largest (tree2) elements are found.
     *     - Compare the sum of the current top nodes of both stacks:
     *         - If the sum matches `x`, increment the count and pop both stacks, move to the next element in both trees.
     *         - If the sum is smaller than `x`, pop from stack1 and move to the right in tree1.
     *         - If the sum is larger than `x`, pop from stack2 and move to the left in tree2.
     * 3️⃣ Continue this process until either stack is empty.
     *
     * Time Complexity: O(n + m) where n and m are the number of nodes in the two trees 🕒.
     * Space Complexity: O(h1 + h2), where h1 and h2 are the heights of the two trees (due to stacks) 🧠.
     */

    int countPairs(Node* root1, Node* root2, int targetSum) {
        stack<Node*> stack1, stack2;  // 🌿 Two stacks for in-order and reverse in-order traversal
        int pairCount = 0;            // 🌟 Count of pairs that sum to the target
        
        Node* node1 = root1;  // 🌳 Pointer for traversal in tree1
        Node* node2 = root2;  // 🌳 Pointer for traversal in tree2
        
        // 🌀 Traverse both trees until one of the stacks is empty
        while (true) {
            // 🌱 Push left nodes of tree1 (in-order traversal)
            while (node1) {
                stack1.push(node1);
                node1 = node1->left;
            }
            
            // 🌿 Push right nodes of tree2 (reverse in-order traversal)
            while (node2) {
                stack2.push(node2);
                node2 = node2->right;
            }
            
            // 🛑 If either stack is empty, we're done
            if (stack1.empty() || stack2.empty()) break;
            
            // 🌟 Top of stack1 holds the smallest node from tree1, top of stack2 holds the largest from tree2
            Node* top1 = stack1.top();
            Node* top2 = stack2.top();
            
            int currentSum = top1->data + top2->data;  // 💡 Sum of current nodes' values
            
            // 🎯 If we find the target sum, pop both stacks and move to the next elements
            if (currentSum == targetSum) {
                ++pairCount;
                stack1.pop();
                stack2.pop();
                node1 = top1->right;  // 🍃 Move to the right in tree1
                node2 = top2->left;   // 🍂 Move to the left in tree2
            }
            // 💡 If the sum is smaller, we need a larger value, so move to the right in tree1
            else if (currentSum < targetSum) {
                stack1.pop();
                node1 = top1->right;
            }
            // 💡 If the sum is larger, we need a smaller value, so move to the left in tree2
            else {
                stack2.pop();
                node2 = top2->left;
            }
        }
        
        return pairCount;  // 🌟 Return the number of pairs found
    }
};

// 🌟 Driver code for local execution
int main() {
    Solution solution;

    // 🌳 Example trees
    /*
      BST1:
              1
              \
               3
              /
              2
            BST2:
                3
              / \
             2   4
            /     
           1
    */
    Node* root1 = new Node(1);
    root1->right = new Node(3);
    root1->right->left = new Node(2);

    Node* root2 = new Node(3);
    root2->left = new Node(2);
    root2->right = new Node(4);
    root2->left->left = new Node(1);

    int targetSum = 4;

    // 🌟 Find the number of pairs with the given sum
    int result = solution.countPairs(root1, root2, targetSum);

    // 📝 Output the result
    cout << "Number of pairs with sum " << targetSum << " is: " << result << endl;

    return 0;
}

/**
 * Example Output:
 * Number of pairs with sum 4 is: 3
 * 
 * Explanation of Output:
 * - Pair (2, 2) from tree1 and tree2 gives sum 2 + 2 = 4.
 * - Pair (3, 1) from tree1 and tree2 gives sum 3 + 1 = 4.
 * - Pair (1, 3) from tree1 and tree2 gives sum 1 + 3 = 4.
 * Hence, 3 pairs match the target sum of 4.
 */

// Time Complexity: O(n + m) where n and m are the number of nodes in the two trees 🕒.
// Space Complexity: O(h1 + h2), where h1 and h2 are the heights of the two trees 🧠.
