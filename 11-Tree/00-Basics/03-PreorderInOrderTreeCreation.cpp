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
Node* constructTreeFromPreAndInOrderTraversal(map<int, int> &valToIndexMap, int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size ) {
  // BASE CASE
  if(preIndex >= size || inOrderStart > inOrderEnd) {
    return NULL;
  }

  //1 case sol.
  int element = preOrder[preIndex];
  preIndex++;
  Node* root = new Node(element);
  //Search the preOrder index element in InOrder
  // int position = searchInOrder(inOrder, size, element);
  int position = valToIndexMap[element];

  //RE
  root->left = constructTreeFromPreAndInOrderTraversal(valToIndexMap,preOrder, inOrder, preIndex, inOrderStart, position-1, size);

  root->right = constructTreeFromPreAndInOrderTraversal(valToIndexMap, preOrder, inOrder, preIndex, position+1, inOrderEnd, size);

  return root;
}


int main() {
  int inOrder[] = {10, 8, 6, 2, 4, 12};
  int preOrder[] = {2, 8, 10, 6, 4, 12};
  int size = 6;
  int preOrderIndex = 0;
  int inOrderStart = 0;
  int inOrderEnd = 5;

  map<int, int> valToIndexMap;
  createMapping(inOrder, size, valToIndexMap);
  Node* root = constructTreeFromPreAndInOrderTraversal( valToIndexMap, preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, size);

  cout << "Printing entire tree: " << endl;
  levelOrderTraverse(root);
  return 0;
}

/*
  Printing entire tree: 
  2 8 4 10 6 12
*/