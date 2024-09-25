#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */
   struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
public:
    int diameter = 0;  // 📝 Initialize a variable to store the maximum diameter
    
    // 📝 Algorithm: height
    // Recursively calculate the height of the tree while updating the diameter.
    // Time Complexity: O(n), where n is the number of nodes in the tree.
    // Space Complexity: O(h), where h is the height of the tree (due to recursion stack).
    int height(TreeNode* root) {
        if (!root) return 0;  // Return 0 for null nodes
        
        // Recursively find the height of the left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        // Update the diameter (max sum of left and right heights)
        int currentDiameter = leftHeight + rightHeight;
        diameter = max(diameter, currentDiameter);
        
        // Return the height of the current node +1 is important
        return max(leftHeight, rightHeight) + 1;
    }
    
    // 📝 Algorithm: diameterOfBinaryTree
    // This function initializes the height calculation and returns the final diameter.
    // Time Complexity: O(n), Space Complexity: O(h)
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);  // Calculate height and update the diameter
        return diameter;  // Return the final diameter value
    }
};

int main () {

  /*
          Example Input Tree:
           1
          / \
         2   3
        / \     
       4   5    

  */

  TreeNode * root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  Solution sol;

  cout << "Diameter of a tree: " << sol.diameterOfBinaryTree(root) << endl;

  return 0; 
}


/*
  Time Complexity: O(n), where n is the number of nodes in the tree.

  Space Complexity: O(h), where h is the height of the tree (due to recursion stack).

  Diameter of the tree: 3
*/