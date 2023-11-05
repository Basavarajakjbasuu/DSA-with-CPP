#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(){
      this->data = 0;
      this->next = NULL;
    }

    Node(int data) {
      this->data = data;
      this->next = NULL;
    }

    
  ~Node() {
      cout << "Destructor called: " << this->data << endl; 
  }
};


/**
 * LL INSERTION
*/
//=> Should be PASS BY REFERENCE
void insertAtHead(Node* &head, Node* &tail, int data) {
  if(head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  }else {
    //Create a new node
    Node *newNode = new Node(data);
    // Attach new node to head node
    newNode->next = head;
    // update head
    head = newNode;
  }
}

void printLL(Node *head) {
  //TO TRAVERSE USE TEMP POINTER => good practice

  Node *temp = head;

  while (temp != NULL) 
  {
    cout << temp->data << "=>";
    temp = temp->next;
  }
  cout << endl;
}

//Find the length if LL
int findLength(Node *head) {

  Node *temp = head;
  int length = 0;

  while(temp != NULL) {
    length++;
    temp = temp->next;
  }

  return length;
}

/***
 * SLL DELETION
*/

void deleteNode(Node* &head, Node* &tail, int position){
  // Empty list
  if(head == NULL) {
      cout << "Deletion is not possible" << endl;
  }

  int len = findLength(head);

  //Delete from head
  if(position == 1) {
    //Delete first node

    // store the deletion node in variable
    Node *deletedNode = head;
    // Move head to deletion next node(head contain adders of first node)
    head = head->next;
    // Make deletion node address to null
    deletedNode->next = NULL;
    // clear the memory of deletion node
    delete deletedNode;
  }
  else if(position == len) {
    //Last node deletion

    //Find Previous node of last node
    Node *prev = head;
    while(prev ->next != tail) {
      prev = prev->next;
    }

    // Prev node link NULL
    prev->next = NULL;
    // delete
    delete tail;

    //update the tail
    tail = prev;
  }
  else {
    //Middle node deletion

    //step1: set prev/Curr pointer
    Node *previousNode = NULL;
    Node *currentNode = head;
    while(position != 1) {
      position--;
      previousNode = currentNode;
      currentNode = currentNode->next;
    }

    //step2: nextNode address to previous node address
    previousNode->next = currentNode->next;

    //Step3: Isolate the current node
    currentNode->next = NULL;

    //Delete tht current node
    delete currentNode;
  }
  
}

int main() {

    // Creation of node
    // Node a;
  Node *head = NULL;
  Node *tail = NULL;

  insertAtHead(head, tail, 100);
  insertAtHead(head, tail, 90);
  insertAtHead(head, tail, 80);
  insertAtHead(head, tail, 70);



  printLL(head);

  // DELETION
  deleteNode(head, tail, 1);
  printLL(head);

  /*
    70=>80=>90=>100=>
    Destructor called: 70
    80=>90=>100=>
  */

  deleteNode(head, tail, 3);
  printLL(head);

  /*
    70=>80=>90=>100=>
    Destructor called: 70
    80=>90=>100=>
    Destructor called: 100
    80=>90=>
  */

  insertAtHead(head, tail, 70);
  insertAtHead(head, tail, 60);
  insertAtHead(head, tail, 50);

  printLL(head);
  deleteNode(head, tail, 3);
  printLL(head);

  /*
    70=>80=>90=>100=>
    Destructor called: 70
    80=>90=>100=>
    Destructor called: 100
    80=>90=>
    50=>60=>70=>80=>90=>
    Destructor called: 70
    50=>60=>80=>90=>
  */

  return 0;
}