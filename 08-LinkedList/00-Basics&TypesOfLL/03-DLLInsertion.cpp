#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;     // Pointer to the next node in the doubly linked list
    Node *previous; // Pointer to the previous node in the doubly linked list

    // Default constructor
    Node() {
      this->next = NULL;
      this->previous = NULL;
    }

    // Parameterized constructor to initialize a new node with data
    Node(int data) {
      this->data = data;
      this->next = NULL;
      this->previous = NULL;
    }
};

// Function to print the linked list
void printLL(Node* head) {
  Node *temp = head;

  // Traverse through the list and print each node's data
  while (temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << endl;
}

// Function to find the length of the linked list
int findLengthLL(Node *head) {
  Node *temp = head;
  int length = 0;

  // Count the number of nodes
  while(temp != NULL) {
    length++;
    temp = temp->next;
  }

  return length;
}

// Function to insert a new node at the head (start) of the linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
  // Case when the list is empty
  if(head == NULL) {
    Node *newNode = new Node(data);
    head = newNode; // Head and tail both point to the new node
    tail = newNode;
  } else {
    // Create a new node and set its next pointer to the current head
    Node *newNode = new Node(data);
    newNode->next = head;
    head->previous = newNode; // Update the current head's previous pointer
    head = newNode; // Update the head pointer
  }
}

// Function to insert a new node at the tail (end) of the linked list
void insertAtTail(Node *&head, Node *&tail, int data) {
  // Case when the list is empty
  if(head == NULL) {
    Node *newNode = new Node(data);
    head = newNode; // Head and tail both point to the new node
    tail = newNode;
  } else {
    // Create a new node and set the previous tail's next pointer to the new node
    Node *newNode = new Node(data);
    tail->next = newNode;
    newNode->previous = tail; // Set the new node's previous pointer to the current tail
    tail = newNode; // Update the tail pointer
  }
}

// Function to insert a new node at a specific position in the linked list
void insertAtPosition(Node *&head, Node *&tail, int data, int position) {
  int length = findLengthLL(head); // Find the current length of the list
  if (position <= 0 || position > length) {
    cout << "Oops! insertion at given position not possible." << endl;
    return;
  }

  // Case when the list is empty
  if(head == NULL) {
    Node *newNode = new Node(data);
    head = newNode; // Head and tail both point to the new node
    tail = newNode;
  } else {


    // Insert at the head if position is 1
    if(position == 1) {
      insertAtHead(head, tail, data);
    }
    // Insert at the tail if position is at the end of the list
    else if(position == length + 1) {
      insertAtTail(head, tail, data);
    } else {
      // Insertion at a middle position
      Node *newNode = new Node(data); // Create a new node

      // Traverse to find the previous node and the current node
      Node *previousNode = NULL;
      Node *currentNode = head;
      while(position != 1) {
        position--;
        previousNode = currentNode;
        currentNode = currentNode->next;
      }

      // Update the new node's previous and next pointers
      newNode->previous = previousNode;
      previousNode->next = newNode;
      newNode->next = currentNode;
      currentNode->previous = newNode; // Update the current node's previous pointer
    }
  }
}

int main() {
  Node *head = NULL;
  Node *tail = NULL;

  // Inserting nodes at the head
  insertAtHead(head, tail, 60);
  insertAtHead(head, tail, 40);
  insertAtHead(head, tail, 20);
  insertAtHead(head, tail, 5);
  printLL(head); // Output: 5->20->40->60->

  // Inserting node at the tail
  insertAtTail(head, tail, 70);
  printLL(head); // Output: 5->20->40->60->70->

  // Inserting node at the head (position 1)
  insertAtPosition(head, tail, 1, 1);
  printLL(head); // Output: 1->5->20->40->60->70->

  // Inserting node at the tail (position 7)
  insertAtPosition(head, tail, 90, 7);
  printLL(head); // Output: 1->5->20->40->60->70->90->

  // Inserting node at position 3
  insertAtPosition(head, tail, 0, 3);
  printLL(head); // Output: 1->5->0->20->40->60->70->90->

  return 0;
}
