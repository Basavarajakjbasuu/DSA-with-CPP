#include<iostream>
#include<queue>
#include<vector>

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


void preOrder(Node* root) {
  if(root==NULL) 
    return;

    //NLR
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void inOrder(Node* root) {
  if(root==NULL)
    return;

    //LNR
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


void postOrder(Node* root) {
  if(root==NULL)
    return;

    //LRN
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}


void levelOrderTraversal(Node* root) {
  queue<Node*> q;
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
    }else {
      cout << temp->data << " ";
      if(temp->left != NULL) {
        q.push(temp->left);
      }

      if(temp->right !=NULL) {
        q.push(temp->right);
      }
    }
  }
}


void printLeftView(Node* root, int level, vector<int>& leftView) {
  if(root ==NULL) 
    return;

  if(level == leftView.size()) {
    leftView.push_back(root->data);
  }

  printLeftView(root->left, level+1, leftView);
  printLeftView(root->right, level+1, leftView);
}


void printRightView(Node* root, int level, vector<int>& rightView) {
  if(root ==NULL) 
    return;

  if(level == rightView.size()) {
    rightView.push_back(root->data);
  }

  printRightView(root->right, level+1, rightView);
  printRightView(root->left, level+1, rightView);
}

int main() {
  Node* root = createTree();
  // levelOrderTraversal(root);
  vector<int> leftView;
  printLeftView(root, 0, leftView);
  cout<< "Printing Left view " << endl;
  for (int i = 0; i < leftView.size(); i++)
  {
    cout << leftView[i] << " ";
  }  
  /*
    Printing Left view 
    10 20 40 70 110
  */

  cout<<endl;

  cout<< "Printing Right view " << endl;
  vector<int> rightView;
  printRightView(root, 0, rightView);
  for (int i = 0; i < rightView.size(); i++)
  {
    cout << rightView[i] << " ";
  }

  /*
    Printing Right view 
    10 30 60 90 113 
  */
  return 0;
}
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1