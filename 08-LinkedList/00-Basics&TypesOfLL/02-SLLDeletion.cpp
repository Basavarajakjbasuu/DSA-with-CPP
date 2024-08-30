#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node(){
      this->data = 0;
      this->next = NULL;
    }

    // Parameterized constructor to initialize with data
    Node(int data) {
      this->data = data;
      this->next = NULL;
    }

    // Destructor to free memory when the node is deleted
    ~Node() {
      cout << "Destructor called: " << this->data << endl; 
    }
};

/**
 * Linked List Insertion
 * Insert a node at the head of the linked list
 * head and tail are passed by reference so the changes reflect in the main function
*/
void insertAtHead(Node* &head, Node* &tail, int data) {
  // Check if the linked list is empty
  if(head == NULL) {
    // Create a new node with the given data
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  } else {
    // Create a new node
    Node *newNode = new Node(data);
    // Point the new node's next to the current head
    newNode->next = head;
    // Update the head to be the new node
    head = newNode;
  }
}

/**
 * Print the Linked List
 * Traverse the linked list from head and print each node's data
 */
void printLL(Node *head) {
  // Use a temporary pointer to traverse
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data << "=>";
    temp = temp->next;
  }
  cout << endl;
}

/**
 * Find the Length of the Linked List
 * Traverse the list and count the nodes
 */
int findLength(Node *head) {
  Node *temp = head;
  int length = 0;

  // Traverse the list until the end
  while(temp != NULL) {
    length++;
    temp = temp->next;
  }

  return length;
}

/**
 * Linked List Deletion
 * Deletes a node at the given position
 */
void deleteNode(Node* &head, Node* &tail, int position){
  
  // Find the length of the linked list
  int len = findLength(head);
  // Check if the linked list is empty
  if(len < 0 || position > len) {
    cout << "Deletion is not possible" << endl;
    return;
  }

  // Single element
  if (head == NULL) {
    Node *temp = head;
    delete temp;
  }

  // Case 1: Deleting the first node (head)
  if(position == 1) {
    Node *deletedNode = head;
    // Move head to the next node
    head = head->next;
    // Detach the deleted node
    deletedNode->next = NULL;
    // Delete the node and free memory
    delete deletedNode;
  }
  // Case 2: Deleting the last node (tail)
  else if(position == len) {
    Node *prev = head;

    // Traverse to the second-last node
    while(prev->next != tail) {
      prev = prev->next;
    }

    // Detach the last node and update the tail
    prev->next = NULL;
    delete tail;
    tail = prev;
  }
  // Case 3: Deleting a node from the middle of the list
  else {
    Node *previousNode = NULL;
    Node *currentNode = head;

    // Traverse to the desired position
    while(position != 1) {
      position--;
      previousNode = currentNode;
      currentNode = currentNode->next;
    }

    // Adjust the pointers to bypass the current node
    previousNode->next = currentNode->next;
    currentNode->next = NULL;

    // Delete the current node
    delete currentNode;
  }
}

int main() {
  Node *head = NULL;
  Node *tail = NULL;

  // Insert nodes at the head of the list
  insertAtHead(head, tail, 100);
  insertAtHead(head, tail, 90);
  insertAtHead(head, tail, 80);
  insertAtHead(head, tail, 70);

  // Print the initial linked list
  printLL(head);

  // Delete the head node (position 1)
  deleteNode(head, tail, 1);
  printLL(head);
  /*
    70=>80=>90=>100=>
    Destructor called: 70
    80=>90=>100=>
   */

  // Delete the tail node (last position)
  deleteNode(head, tail, findLength(head));
  printLL(head);
  /*
    Destructor called: 100
    80=>90=>
  */

  // Insert additional nodes at the head
  insertAtHead(head, tail, 70);
  insertAtHead(head, tail, 60);
  insertAtHead(head, tail, 50);

  // Print the modified linked list
  printLL(head);

  // Delete a node from the middle (position 3)
  deleteNode(head, tail, 3);
  printLL(head);
  /*
    50=>60=>70=>80=>90=>
    Destructor called: 70
    50=>60=>80=>90=>
  */
  deleteNode(head, tail, 45);
  // Deletion is not possible

  return 0;
}
