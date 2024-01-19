#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int value) {
    this->data = value;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* insertIntoBST(Node* root, int data) {
  //BASE CASE
  if(root == NULL) {
    root = new Node(data);
    return root;
  }

  //if its not root node
  if(data > root->data) {
    root->right = insertIntoBST(root->right, data);
  } else {
    root->left = insertIntoBST(root->left, data);
  }

  return root;
}

//should pass by reference
void createBST(Node* &root) {
  cout << "Enter data: ";
  int data;
  cin>> data;

  while(data!=-1) {
    cout << "Enter data: ";
    root = insertIntoBST(root, data);
    cin>> data;
  }

}

bool searchInBST(Node* root, int target) {
  //BASE CASE
  if(root == NULL)
    return false;

  if(root->data == target)
    return true;

  //RE
  bool leftAns = false;
  bool rightAns = false;
  if(target > root->data) 
    rightAns = searchInBST(root->right, target);
  else 
    leftAns = searchInBST(root->left, target);

  return leftAns || rightAns;
}

int main() {
  Node* root = NULL;
  createBST(root);

  int key;
  cout << "Enter element to search: ";
  cin>> key;

  bool isFound = searchInBST(root, key);

  if(isFound)
    cout << key << " found in BST " << endl; 
  else 
    cout << key << " not found in BST " << endl;

  return 0;
}

/*
  POSITIVE CASE

  Enter data: 50
  Enter data: 30
  Enter data: 20
  Enter data: 40
  Enter data: -10
  Enter data: 56
  Enter data: 23
  Enter data: -1
  Enter element to search: 23
  23 found in BST

  NEGATIVE CASE

  Enter data: 40
  Enter data: 34
  Enter data: 56
  Enter data: 78
  Enter data: 9
  Enter data: 0
  Enter data: -1
  Enter element to search: -1
  -1 not found in BST
*/