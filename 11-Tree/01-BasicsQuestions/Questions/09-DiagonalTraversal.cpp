#include <iostream>
#include <queue>
#include <vector>
using namespace std;

 
// A binary tree node
struct Node {
    int data;
    Node* left, * right;
    Node(): data(0), left(NULL), right(NULL) {};
    Node(int val): data(val), left(NULL), right(NULL) {}; 
    Node(int val, Node *left, Node *right): data(val), left(left), right(right) {};
};

// 📝 Algorithm explanation: 
// The function performs diagonal traversal of the binary tree. It uses a queue to keep track of nodes
// at different levels and traverses each diagonal by going rightwards, adding the left child to the queue
// for processing in the next diagonal.
// 
// 🕒 Time Complexity: O(N), where N is the number of nodes in the tree, since each node is visited once.
// 🗂️ Space Complexity: O(N), due to the use of a queue for storing nodes.

vector<int> diagonal(Node *root) {
    vector<int> answer;
    
    // Base case: If the tree is empty, return an empty answer
    if (!root) return answer;

    // Queue to store nodes for diagonal processing
    queue<Node*> qu;

    // Start by pushing the root to the queue
    qu.push(root);

    // Process nodes until the queue is empty
    while(!qu.empty()) {
        // Pop the front node from the queue
        Node* temp = qu.front(); 
        qu.pop();
        
        // Traverse the current diagonal (going rightwards)
        while(temp) {
            // Add the current node's data to the result
            answer.push_back(temp->data);
            
            // If the current node has a left child, enqueue it
            if(temp->left) {
                qu.push(temp->left);
            }
            // Move to the right child to continue diagonal traversal
            temp = temp->right;
        }
    }

    // Return the result vector containing diagonal traversal
    return answer;
}

int main() {
    // Example tree construction for testing
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    
    // Call diagonal traversal function
    vector<int> result = diagonal(root);

    // Output the result
    for(int val : result) {
        cout << val << " ";
    }

    return 0;
}

/*
Sample Input:
    Tree Structure:
            8
           / \
          3   10
         / \    \
        1   6    14
           / \   /
          4   7 13
          
Sample Output:
8 10 14 3 6 7 13 1 4
*/

