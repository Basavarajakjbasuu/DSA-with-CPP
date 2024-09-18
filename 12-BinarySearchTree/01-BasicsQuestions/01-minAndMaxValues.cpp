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

Node* minValue(Node* root) {

  if(root ==NULL) {
    return root;
  }  

  Node* temp = root;

  while(temp->left != NULL) {
    temp = temp->left;
  }

  return temp;
}

Node* maxValue(Node* root) {
  if(root == NULL) {
    return root;
  }

  Node* temp = root;

  while(temp->right != NULL)
    temp = temp->right;

  return temp;
}

int main() {
  Node* root = NULL;
  createBST(root);

  cout << endl;
  Node* minNode = minValue(root);
  Node* maxNode = maxValue(root);

  if(minNode == NULL) {
    cout << "Oops! no min value." << endl;
  } else {
    cout << "Minimum value is: " << minNode->data << endl;
  }
  if(maxNode == NULL) {
    cout << "Oops! no max value." << endl;
  } else {
    cout << "Maximum value is: " << maxNode->data << endl;
  }
  return 0;
}

/*
  Enter data: 50
  Enter data: 30
  Enter data: 60
  Enter data: 20
  Enter data: -40
  Enter data: 420
  Enter data: 23
  Enter data: -1

  Minimum value is: -40
  Maximum value is: 420
*/