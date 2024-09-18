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

Node* maxValue(Node* root) {
  if(root == NULL) {
    return root;
  }

  Node* temp = root;

  while(temp->right != NULL)
    temp = temp->right;

  return temp;
}


Node* deleteFromBST(Node* root, int target) {
  //Search the target
  //Delete target

  if(root == NULL) 
    return NULL;
  
  if(target == root->data) {
    //Target found Delete node
    // handle 4-cases

    if(root->left == NULL && root->right == NULL) {
      //1 case => only leaf node
      delete root;
      return NULL;
    }
    else if(root->left != NULL && root->right == NULL) {
      //2nd case => left node there
      Node* childSubtree = root->left;
      delete root;
      return childSubtree;
    }
    else if(root->left == NULL && root->right != NULL) {
      //3rd case => right  node there
      Node* childeSubtree = root->right;
      delete root;
      return childeSubtree;
    }
    else {
      //4th case => both right and left nodes there
      //find maxNode
      Node* maxNode = maxValue(root->left);
      //Replacement
      root->data = maxNode->data;

      //Delete actual max node
      root->left = deleteFromBST(root->left, maxNode->data);
    }

  }else if(root->data > target) {
    // Move to left
    root->left = deleteFromBST(root->left, target);
  } else {
    //Move to right
    root->right = deleteFromBST(root->right, target);
  }

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


int main() {
  
  Node* root = NULL;
  createBST(root);

  cout << "Printing Level order traversal: " <<  endl;
  levelOrderTraversal(root);

  int target;
  cout << "Enter target value to Delete: ";
  cin>> target;

  while(target != -1) {
    root = deleteFromBST(root, target);

    cout << "Printing Level order traversal: " << endl;
    levelOrderTraversal(root);

    cout << "Enter target value to Delete: ";
    cin>> target;
  }

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
  Printing Level order traversal: 
  50 
  30 60 
  25 40 55 70 
  80 
  Enter target value to Delete: 80
  Printing Level order traversal: 
  50 
  30 60 
  25 40 55 70 
  Enter target value to Delete: 70
  Printing Level order traversal: 
  50
  30 60
  25 40 55
  Enter target value to Delete: 60
  Printing Level order traversal: 
  50
  30 55 
  25 40
  Enter target value to Delete: 30
  Printing Level order traversal:
  50
  25 55
  40
  Enter target value to Delete: 50
  Printing Level order traversal:
  40
  25 55
  Enter target value to Delete: -1
*/