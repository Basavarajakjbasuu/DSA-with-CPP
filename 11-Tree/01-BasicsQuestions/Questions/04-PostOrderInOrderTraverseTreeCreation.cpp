#include<iostream>
#include<queue>
#include<map>

using namespace std;

class Node {
  public:
  int data;
  Node *left;
  Node *right;

  Node (int val) {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

void createMapping(int inOrder[], int size, map<int, int> &valueToIndexMap) {

  for (int i = 0; i < size; i++)
  {
    int element = inOrder[i];
    int index = i;
    valueToIndexMap[element] = i;
  }
  
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


int searchInOrder(int inOrder[], int size, int target) {
  for (int i = 0; i < size; i++)
  {
    if(inOrder[i] == target) {
      return i;
    }
  }
  return -1;  
}

//Should pass reference preIndex;
Node* constructTreeFromPostAndInOrderTraversal(map<int, int> &valToIndexMap, int postOrder[], int inOrder[], int &postIndex, int inOrderStart, int inOrderEnd, int size ) {
  // BASE CASE
  if(postIndex < 0 || inOrderStart > inOrderEnd) {
    return NULL;
  }

  //1 case sol.
  int element = postOrder[postIndex];
  postIndex--;
  Node* root = new Node(element);
  //Search the preOrder index element in InOrder
  // int position = searchInOrder(inOrder, size, element);
  int position = valToIndexMap[element];

  //RE
  // should right call then left
  root->right = constructTreeFromPostAndInOrderTraversal(valToIndexMap, postOrder, inOrder, postIndex, position+1, inOrderEnd, size);
  root->left = constructTreeFromPostAndInOrderTraversal(valToIndexMap,postOrder, inOrder, postIndex, inOrderStart, position-1, size);



  return root;
}


int main() {
  int inOrder[] = {10, 8, 6, 2, 4, 12};
  int postOrder[] = {8, 6, 14, 4, 10, 2};
  int size = 6;
  int postOrderIndex = size-1;
  int inOrderStart = 0;
  int inOrderEnd = size-1;

  map<int, int> valToIndexMap;
  createMapping(inOrder, size, valToIndexMap);
  Node* root = constructTreeFromPostAndInOrderTraversal( valToIndexMap, postOrder, inOrder, postOrderIndex, inOrderStart, inOrderEnd, size);

  cout << "Printing entire tree: " << endl;
  levelOrderTraverse(root);
  return 0;
}

/*
  Printing entire tree: 
  2 8 4 10 6 12
*/