#include<iostream>
#include<map>
#include<queue>
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

void printBottomView(Node* root) {
  // hd- horizontalDistance
  map<int, int> hdToNodeMap;
  queue<pair <Node*, int>> q;

  q.push(make_pair(root, 0));

  while(!q.empty()) {
    pair<Node*, int> temp = q.front();
    q.pop();

    Node* frontNode = temp.first;
    int hd = temp.second;

    // overwrite the answer so deeper node is updated
    hdToNodeMap[hd] = frontNode->data;

    if(frontNode->left != NULL) {
      q.push(make_pair(frontNode->left, hd-1));
    }

    if(frontNode->right != NULL) {
      q.push(make_pair(frontNode->right, hd+1));
    }
  }  

  cout << "Printing top view: ";
  for(auto i: hdToNodeMap) {
    cout << i.second << " ";
  }
}

int main() {
  Node* root = createTree();

  printBottomView(root); //Printing top view: 110 70 111 80 112 90 113
  return 0;
}

//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1