#include<iostream>
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


void printLeftBoundary(Node* root) {
  if(root == NULL)
    return;

  if(root->left == NULL && root->right == NULL) 
    return;

  cout << root->data << " ";
  if(root->left != NULL) {
    printLeftBoundary(root->left);
  } else {
    printLeftBoundary(root->right);
  }
}

void printLeafBoundary(Node* root) {
  if(root == NULL)
    return;

  if(root->left == NULL && root->right == NULL) {
    cout << root->data << " ";
  }

  printLeafBoundary(root->left);
  printLeafBoundary(root->right);
}

void printRightBoundary(Node* root) {
  if(root == NULL)
    return;

  if(root->left == NULL && root->right == NULL) 
    return;

  if(root->right != NULL) {
    printRightBoundary(root->right);
  } else {
    printRightBoundary(root->left);
  }
  cout << root->data << " ";
}

void boundaryTraversal(Node* root) {
  if(root == NULL)
    return;

  // printLeftBoundary(root);
  // printLeafBoundary(root);
  
  // if(root->right != NULL) {
  //   printRightBoundary(root->right);
  // }else {
  //   printRightBoundary(root->left);
  // }

  cout << root->data << " ";
  printLeftBoundary(root->left);
  printLeafBoundary(root->left);
  printLeafBoundary(root->right);
  printRightBoundary(root->right);
}

int main() {
  Node* root = createTree();

  boundaryTraversal(root); // 10 20 40 110 111 80 112 113 90 60 30
  return 0;
}

//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
