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


Node* bstFromInOrder(int inOrder[], int startIndex, int endIndex) {
  //Base case
  if(startIndex > endIndex)
    return NULL;

  // 1 case sol.
  int mid = (startIndex+endIndex) /2;
  int element = inOrder[mid];
  Node* root = new Node(element);

  //RE
  root->left = bstFromInOrder(inOrder, startIndex, mid-1);
  root->right = bstFromInOrder(inOrder, mid+1, endIndex);

  return root;
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

void convertBSTtoDLL(Node* root, Node* &head) {
  //Base case
  if(root == NULL) 
    return;

  //RNL
  //R
  convertBSTtoDLL(root->right, head);

  //N
  root->right = head;
  if(head != NULL)
    head->left = root;
  head = root;

  //L
  convertBSTtoDLL(root->left, head);

}

void printLL(Node* head) {
  Node* temp = head;

cout << "Printing Linked list: ";
  while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->right;
  }
  cout << endl;
}

int main() {
 
  int inOrder[] = {10, 20, 30, 40, 50, 60, 70};
  int size = 7;
  int endIndex = size - 1;
  int startIndex = 0;

  Node* root = bstFromInOrder(inOrder, startIndex, endIndex);

  levelOrderTraversal(root);

  Node* head = NULL;
  convertBSTtoDLL(root, head);
  printLL(head);
  return 0;
}

/*
  40 
  20 60 
  10 30 50 70 
  Printing Linked list: 10 20 30 40 50 60 70 
*/