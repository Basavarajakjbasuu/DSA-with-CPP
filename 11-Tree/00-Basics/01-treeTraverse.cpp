#include<iostream>
using namespace std;

class Node {
  public:
  int data;
  Node *left;
  Node *right;

  Node (int val) {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *createTree() {
  // cout << "Enter the value for Node: " << endl;
  int data;
  cin>> data;

  // If we dont want node
  if(data == -1) {
    return NULL;
  } 

  //Step1: Create Node
  Node *newNode = new Node(data);

  //Step2: Create left subtree
  // cout<< "Left of node: " << newNode->data << endl;
  newNode->left = createTree();
  //Step3: Create right subtree
  // cout<< "Right of node: " << newNode->data << endl;
  newNode->right = createTree();  

  return newNode;
}

void preOrderTraversal(Node *root) {
  //Base case
  if(root == NULL) {
    return;
  }

  //NLR
  //N
  cout << root->data << " ";
  //L
  preOrderTraversal(root->left);
  //R
  preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root) {
  //Base case
  if(root == NULL) {
    return;
  }

  //LNR
  //L
  inOrderTraversal(root->left);
  //N
  cout << root->data << " ";
  //R
  inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
  //Base case
  if(root == NULL) {
    return;
  }

  //LRN
  //L
  postOrderTraversal(root->left);
  //R
  postOrderTraversal(root->right);
  //N
  cout << root->data << " ";
}

int main() {
 
  cout << "Enter values for node: ";
  Node *root = createTree();

  //LNR
  cout << "PreOrder: "; preOrderTraversal(root); cout << endl;
  //LRN
  cout << "PostOrder: "; postOrderTraversal(root); cout << endl;
  //NLR
  cout << "inOrder: "; inOrderTraversal(root); cout << endl;

  return 0;
}

/*
  Enter the value for Node:
  10         
  Left of node: 10
  Enter the value for Node: 
  20
  Left of node: 20
  Enter the value for Node: 
  40
  Left of node: 40
  Enter the value for Node: 
  -1
  Right of node: 40
  Enter the value for Node: 
  -1
  Right of node: 20
  Enter the value for Node: 
  -1
  Right of node: 10
  Enter the value for Node:
  30
  Left of node: 30
  Enter the value for Node:
  50
  Left of node: 50
  Enter the value for Node:
  -1
  Right of node: 50
  Enter the value for Node:
  -1
  Right of node: 30
  Enter the value for Node:
  60
  Left of node: 60
  Enter the value for Node:
  -1
  Right of node: 60
  Enter the value for Node:
  -1
  PreOrder: 10 20 40 30 50 60
  PostOrder: 40 20 50 60 30 10
  inOrder: 40 20 10 50 30 60
*/

/*
  Enter values for node: 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1
  PreOrder: 10 20 40 30 50 60 
  PostOrder: 40 20 50 60 30 10 
  inOrder: 40 20 10 50 30 60 
*/