#include<iostream>
#include<queue>
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
  int data;
  cin>> data;

  // If we dont want node
  if(data == -1) {
    return NULL;
  } 

  //Step1: Create Node
  Node *newNode = new Node(data);

  //Step2: Create left subtree
  newNode->left = createTree();
  //Step3: Create right subtree
  newNode->right = createTree();  

  return newNode;
}

void levelOrderTraverse(Node *root) {
  queue<Node*> qu;
  qu.push(root);

  while (!qu.empty())
  {
    Node* front = qu.front();
    qu.pop();

    cout << front->data << " ";

    if(front->left != NULL) {
      qu.push(front->left);
    }

    if(front->right != NULL) {
      qu.push(front->right);
    }
  }
  
}



void levelOrderTraverseWithMarker(Node *root) {
  queue<Node*> qu;
  qu.push(root);
  qu.push(NULL);

  //if we take qu.empty() it will go infinite loop at last node because every time adding null so 
  while (qu.size() > 1)
  {
    Node* front = qu.front();
    qu.pop();

    if(front == NULL) {
      cout << endl;
      qu.push(NULL);
    }else {
      // valid
      cout << front->data << " ";

      if(front->left != NULL) {
        qu.push(front->left);
      }

      if(front->right != NULL) {
        qu.push(front->right);
      }
    }

  }
  
}

int main() {
  cout << "Enter the value for Node: " << endl;
  Node *root = createTree();

  cout<<"Level order: ";
  levelOrderTraverse(root);

  cout << endl;

  cout << "Level order with Marker: " << endl;
  levelOrderTraverseWithMarker(root);
  return 0;
}


/*
  Enter the value for Node: 
  10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1
  Level order: 10 20 30 40 50 60 
  Level order with Marker: 
  10 
  20 30 
  40 50 60 
*/