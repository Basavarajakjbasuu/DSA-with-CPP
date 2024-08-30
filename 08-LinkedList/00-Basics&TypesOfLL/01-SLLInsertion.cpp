#include <iostream>
using namespace std;

// Definition of the Node class
class Node {
public:
  int data;    // To store the value/data of the node
  Node *next;  // Pointer to the next node in the linked list

  // Default constructor to initialize `next` as NULL
  Node() {
    this->next = NULL;
  }

  // Parameterized constructor to initialize the node with data
  Node(int data) {
    this->data = data;
    this->next = NULL;  // New nodes start with `next` as NULL
  }
};

// Function to print the linked list
void printLL(Node *head) {
  // It's good practice to use a temporary pointer for traversal
  Node *temp = head;

  // Traverse through the linked list until reaching NULL
  while (temp != NULL) {
    cout << temp->data << "=>";  // Print the data of each node
    temp = temp->next;           // Move to the next node
  }
  cout << endl;
}

// Function to insert a node at the head of the linked list
// Passed by reference to modify the original list
void insertAtHead(Node *&head, Node *&tail, int data) {
  if (head == NULL) {
    // If the list is empty, both head and tail point to the new node
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  } else {
    // Non-empty list case
    Node *newNode = new Node(data);  // Create a new node
    newNode->next = head;  // Link new node to current head
    head = newNode;        // Update head to point to the new node
  }
}

// Function to insert a node at the tail of the linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
  if(head == NULL) {
    // If the list is empty, create a new node and update both head and tail
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  } else {
    // Non-empty list case
    Node *newNode = new Node(data);  // Create a new node
    tail->next = newNode;  // Attach new node to the tail node
    tail = newNode;        // Update tail to point to the new node
  }
}

// Function to get the length of the linked list
int getLengthLL(Node* node) {
  Node *temp = node;
  int length = 0;

  // Traverse through the linked list and count the nodes
  while(temp != NULL) {
    length++;
    temp = temp->next;
  }
  return length;
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
  int length = getLengthLL(head);

  // Check for invalid position
  if(position < 0 || position > length + 1) {
    cout << "Oops! Please enter valid position" << endl;
    return;
  }

  // Insert at the head if position is 0
  if(position == 0) {
    insertAtHead(head, tail, data);
  } 
  // Insert at the tail if position is length + 1
  else if(position == length + 1) {
    insertAtTail(head, tail, data);
  } 
  // Insert in the middle of the list
  else {
    Node *newNode = new Node(data);  // Create a new node
    Node *previousNode = NULL;
    Node *currentNode = head;

    // Traverse to the desired position
    while(position != 1) {
      previousNode = currentNode;
      currentNode = currentNode->next;
      position--;
    }

    // Insert the new node in the correct position
    previousNode->next = newNode;
    newNode->next = currentNode;
  }
}

int main() {
  Node *head = NULL;  // Initialize head pointer to NULL
  Node *tail = NULL;  // Initialize tail pointer to NULL

  // Insert nodes at the head
  insertAtHead(head, tail, 50);
  insertAtHead(head, tail, 40);
  insertAtHead(head, tail, 30);
  insertAtHead(head, tail, 20);

  // Print the linked list
  printLL(head);
  /*
    20=>30=>40=>50=>
  */

  // Insert a node at the tail
  insertAtTail(head, tail, 100);
  printLL(head);
  /*
    20=>30=>40=>50=>
    20=>30=>40=>50=>100=> 
  */

  // Insert a node at position 3
  insertAtPosition(head, tail, 45, 3);
  printLL(head);
  /*
    20=>30=>40=>50=>
    20=>30=>40=>50=>100=>
    20=>30=>45=>40=>50=>100=>
  */

  // Insert a node at the head (position 0)
  insertAtPosition(head, tail, -40, 0);
  printLL(head);
  //-40=>20=>30=>45=>40=>50=>100=>

  // Insert a node at the tail (position 8)
  insertAtPosition(head, tail, -40, 8);
  printLL(head);
  //-40=>20=>30=>45=>40=>50=>100=>-40=>

  // Trying to insert at an invalid position
  insertAtPosition(head, tail, 1111, 54);  // Invalid position
  //Oops! Please enter valid position
  insertAtPosition(head, tail, 40, -8);    // Invalid position
  // Oops! Please enter valid position


  return 0;
}
