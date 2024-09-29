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

Node* convertDLLtoBST(Node* &head, int n) {
  //Base case
  if(head == NULL || n<=0) {
    return NULL;
  }

  //LNR
  //L
  Node* leftSubtree = convertDLLtoBST(head, n/2);

  //N
  Node* root= head;
  root->left = leftSubtree;
  head = head -> right;

  //R
  Node* rightSubtree = convertDLLtoBST(head, n-n/2-1);
  root->right = rightSubtree;
  return root;

}

int main() {

  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);

  first->right = second;
  second->left = first;
  second->right = third;
  third->left = second;

  Node* head = first;
  //10->20->30

  Node* root = convertDLLtoBST(head, 3);
  levelOrderTraversal(root);

  return 0;
}

/*
  20 
10 30
*/