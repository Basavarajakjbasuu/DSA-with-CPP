#include<iostream>
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

//It returns root node of created tree
Node *createTree() {
  cout << "Enter the value for Node: " << endl;
  int data;
  cin>> data;

  // If we dont want node
  if(data == -1) {
    return NULL;
  } 

  //Step1: Create Node
  Node *newNode = new Node(data);

  //Step2: Create left subtree
  cout<< "Left of node: " << newNode->data << endl;
  newNode->left = createTree();
  //Step3: Create right subtree
  cout<< "Right of node: " << newNode->data << endl;
  newNode->right = createTree();  

  return newNode;
}

int main() {
  Node *root = createTree();
  return 0;
}