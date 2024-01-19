#include<iostream>
#include<queue>
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


void levelOrderTraversal(Node* root) {
  queue<Node*>  q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()) {
    Node* temp = q.front();
    q.pop();

    if(temp == NULL) {
      cout << endl;
      if(!q.empty()) {
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if(temp->left != NULL)  
        q.push(temp->left);
      
      if(temp->right != NULL)
        q.push(temp->right);
    }

  }
}


void preOrder(Node* root) {
  if(root == NULL) 
    return;

  //NLR
  cout<<root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node* root) {
  if(root == NULL)
    return;

  //LNR
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void postOrder(Node* root) {
  if(root == NULL)
    return;

  //LRN
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

int main() {
  Node* root = NULL;
  createBST(root);
  levelOrderTraversal(root);

  cout << endl << "InOrder: "; inOrder(root);
  cout << endl << "PostOrder: "; postOrder(root);
  cout << endl << "PreOrder: "; preOrder(root);
  return 0;
}

/*
  Enter data: 50
  Enter data: 30
  Enter data: 60
  Enter data: 25
  Enter data: 40
  Enter data: 70
  Enter data: 80
  Enter data: 55
  Enter data: -1
  50
  30 60
  25 40 55 70
  80

  InOrder: 25 30 40 50 55 60 70 80 
  PostOrder: 25 40 30 55 80 70 60 50 
  PreOrder: 50 30 25 40 60 55 70 80
*/