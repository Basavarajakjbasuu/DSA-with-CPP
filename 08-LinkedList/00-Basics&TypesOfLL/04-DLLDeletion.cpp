#include<iostream>
using namespace std;

class Node {
  public:
    int data;       // Data stored in the node
    Node *next;     // Pointer to the next node in the doubly linked list
    Node *previous; // Pointer to the previous node in the doubly linked list

    // Default constructor: initializes next and previous pointers to NULL
    Node() {
      this->next = NULL;
      this->previous = NULL;
    }

    // Parameterized constructor to initialize a new node with a specific value
    Node(int data) {
      this->data = data;
      this->next = NULL;
      this->previous = NULL;
    }

    // Destructor: called when a node is deleted to free memory
    ~Node() {
      cout << "Deleted node is: " << this->data << endl;
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

// Function to delete a node from a doubly linked list at a specific position
void deletionFromDLL(Node *&head, Node *&tail, int position) {
  // Find the length of the linked list
  int lengthOfDLL = findLengthLL(head);

  // If the position is invalid or the list is empty
  if (position <= 0 || position > lengthOfDLL || head == NULL) {
    cout << "Oops! Deletion is impossible." << endl;
    return;
  }

  // Special case: if there is only one node in the list
  if (head == tail) {
    Node *temp = head;
    delete temp;  // Delete the single node
    head = NULL;  // Set both head and tail to NULL
    tail = NULL;
    return;
  }

  // Deletion of the first node
  if (position == 1) {
    Node *temp = head;
    head = head->next;        // Update head to the next node
    head->previous = NULL;    // Remove the reference to the old head
    temp->next = NULL;        // Isolate the old head node
    delete temp;              // Delete the old head node
  } 
  // Deletion of the last node
  else if (position == lengthOfDLL) {
    Node *previousNode = tail->previous;  // Find the node before the tail
    previousNode->next = NULL;            // Set the second last node's next pointer to NULL
    tail->previous = NULL;                // Remove the reference to the previous node
    delete tail;                          // Delete the last node
    tail = previousNode;                  // Update the tail pointer
  } 
  // Deletion of a node at a middle position
  else {
    Node *previousNode = NULL;
    Node *curentNode = head;

    // Traverse the list to find the node at the specified position
    while (position != 1) {
      position--;
      previousNode = curentNode;
      curentNode = curentNode->next;
    }

    Node *nextNode = curentNode->next;     // Get the node after the current node
    previousNode->next = nextNode;         // Update the previous node's next pointer
    nextNode->previous = previousNode;     // Update the next node's previous pointer
    curentNode->previous = NULL;           // Isolate the current node
    curentNode->next = NULL;
    delete curentNode;                     // Delete the current node
  }
}

int main() {
  
  Node *head = NULL;
  Node *tail = NULL;

  // Inserting nodes at the head
  insertAtHead(head, tail, 4);
  insertAtHead(head, tail, 8);
  insertAtHead(head, tail, 12);
  insertAtHead(head, tail, 16);
  
  printLL(head); // Output: 16->12->8->4->

  // Deleting the first node
  deletionFromDLL(head, tail, 1);
  printLL(head); // Output: 12->8->4->

  // Deleting the second node
  deletionFromDLL(head, tail, 2);
  printLL(head); // Output: 12->4->

  // Inserting new nodes at the head
  insertAtHead(head, tail, 20);
  insertAtHead(head, tail, 24);
  
  printLL(head); // Output: 24->20->12->4->

  // Deleting the last node
  deletionFromDLL(head, tail, findLengthLL(head));
  printLL(head); // Output: 24->20->12->

  return 0;
}
