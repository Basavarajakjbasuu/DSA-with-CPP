#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

// 🌳 Definition for the binary tree node.
struct Node
{
  int data;
  Node *left;
  Node *right;

  // Constructor to initialize a node
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  /**
   * 🌟 Algorithm to calculate the maximum sum of non-adjacent nodes:
   *
   * 1️⃣ **Check for null root**:
   *    - If the root is null, return `{0, 0}` where both values represent sums.
   *    - Time complexity here is **O(1)** as it's a simple check.
   *
   * 2️⃣ **Recursive calculation for left and right subtrees**:
   *    - **Recursively call** `getMaxSumHelper` for the left child to get the pair of sums for the left subtree.
   *    - **Recursively call** `getMaxSumHelper` for the right child to get the pair of sums for the right subtree.
   *    - Both recursive calls take **O(n)** time where 'n' is the number of nodes.
   *
   * 3️⃣ **Compute the sum including the current node**:
   *    - **First value (a)**: Add the current node's value to the second value (non-adjacent sum) of the left and right subtrees.
   *
   * 4️⃣ **Compute the sum excluding the current node**:
   *    - **Second value (b)**: Take the maximum between the first and second values for both the left and right subtrees and add them.
   *
   * 5️⃣ **Return the pair of sums**:
   *    - Return the pair `{a, b}` representing the sum including and excluding the current node.
   *
   * 🧠 **Time Complexity (TC)**: O(n), where 'n' is the number of nodes in the tree since each node is visited once.
   * 🧠 **Space Complexity (SC)**: O(h), where 'h' is the height of the tree due to the recursion stack.
   */

  // 🟢 Helper function to calculate the max sum of non-adjacent nodes.
  pair<int, int> getMaxSumHelper(Node *root)
  {
    if (!root)
      return {0, 0}; // 🛑 Base case: If node is null, return 0 for both sums.

    // 🌱 Recursively calculate the max sum for the left and right subtrees.
    pair<int, int> leftSubtree = getMaxSumHelper(root->left);
    pair<int, int> rightSubtree = getMaxSumHelper(root->right);

    // 🌟 Calculate the sum including the current node.
    int includeCurrentNode = root->data + leftSubtree.second + rightSubtree.second;

    // 🌟 Calculate the sum excluding the current node.
    int excludeCurrentNode = max(leftSubtree.first, leftSubtree.second) + max(rightSubtree.first, rightSubtree.second);

    return {includeCurrentNode, excludeCurrentNode}; // 🔄 Return both sums.
  }

  // 🟢 Main function to get the maximum sum of non-adjacent nodes.
  int getMaxSum(Node *root)
  {
    pair<int, int> maxSum = getMaxSumHelper(root);
    return max(maxSum.first, maxSum.second); // 🔄 Return the maximum of both sums.
  }
};

// 🌟 Example for local execution
int main()
{
  Solution solution;

  // Example tree creation:
  /*
          1
        /   \
       2     3
      /     /  \
     4     5    6
  */
  Node *root = new Node(1);
  root->left = new Node(2);
  root->left->left = new Node(4);
  root->right = new Node(3);
  root->right->left = new Node(5);
  root->left->right = new Node(6);

  // 🌟 Expected Output: Maximum sum of non-adjacent nodes is 16
  cout << "Maximum sum of non-adjacent nodes: " << solution.getMaxSum(root) << endl;

  return 0;
}

/**
 * 🧠 Time Complexity (TC): O(n), where 'n' is the number of nodes in the tree.
 *     - Each node is visited exactly once during the recursion.
 *
 * 🧠 Space Complexity (SC): O(h), where 'h' is the height of the tree.
 *     - The space complexity is determined by the recursion stack depth.
 *
 * 🔍 Sample Output:
 * Maximum sum of non-adjacent nodes: 16
 *
 *
  //            10
  //           /  \
  //          1    2
  //         / \
  //        3   4
  //
  // 1️⃣ At node 3 (leaf node):
  //    - Sum including node 3: 3 + 0 (left child) + 0 (right child) = 3
  //    - Sum excluding node 3: max(0, 0) + max(0, 0) = 0
  //
  // 2️⃣ At node 4 (leaf node):
  //    - Sum including node 4: 4 + 0 (left child) + 0 (right child) = 4
  //    - Sum excluding node 4: max(0, 0) + max(0, 0) = 0
  //
  // 3️⃣ At node 1:
  //    - Sum including node 1: 1 + 0 (exclude left subtree) + 0 (exclude right subtree) = 1
  //    - Sum excluding node 1: max(3, 0) + max(4, 0) = 7
  //
  // 4️⃣ At node 2 (leaf node):
  //    - Sum including node 2: 2 + 0 (left child) + 0 (right child) = 2
  //    - Sum excluding node 2: max(0, 0) + max(0, 0) = 0
  //
  // 5️⃣ At root node 10:
  //    - Sum including root 10: 10 + 7 (exclude left subtree) + 0 (exclude right subtree) = 17
  //    - Sum excluding root 10: max(1, 7) + max(2, 0) = 9
  //
  // Maximum sum = max(17, 9) = 17
 */
