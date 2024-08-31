#include <iostream>
using namespace std;

class Node {
public:
    int data;         // Data stored in the node
    Node* next;       // Pointer to the next node in the circular doubly linked list
    Node* prev;       // Pointer to the previous node in the circular doubly linked list

    // Default constructor
    Node() {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    // Parameterized constructor to initialize a node with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a new node at the head of the circular doubly linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
    // Create a new node
    Node* newNode = new Node(data);

    // Case when the list is empty
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;  // Point to itself (circular)
        newNode->prev = newNode;  // Point to itself (circular)
    } 
    else {
        // Link the new node's next to the current head
        newNode->next = head;
        // Link the head's prev to the new node
        head->prev = newNode;
        // Link the new node's prev to the tail
        newNode->prev = tail;
        // Link the tail's next to the new node
        tail->next = newNode;
        // Update head to the new node
        head = newNode;
    }
}

// Function to insert a new node at the tail of the circular doubly linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
    // Create a new node
    Node* newNode = new Node(data);

    // Case when the list is empty
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;  // Point to itself (circular)
        newNode->prev = newNode;  // Point to itself (circular)
    } 
    else {
        // Link the new node's next to the head (circular)
        newNode->next = head;
        // Link the head's prev to the new node
        head->prev = newNode;
        // Link the tail's next to the new node
        tail->next = newNode;
        // Link the new node's prev to the current tail
        newNode->prev = tail;
        // Update the tail pointer to the new node
        tail = newNode;
    }
}

// Function to insert a node at a specific position in the circular doubly linked list
void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
    // If position is 1, insert at the head
    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    // Create a new node
    Node* newNode = new Node(data);

    // Traverse to find the node before the insertion position
    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // If inserting at the tail position
    if (temp->next == head) {
        insertAtTail(head, tail, data);
    } 
    else {
        // Link the new node to its previous and next nodes
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to print the circular doubly linked list
void printLL(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    // Use a do-while loop to traverse through the circular list
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);  // Stop when we reach the head again

    cout << "(head)" << endl;  // Indicate circular nature
}

// Function to print the circular doubly linked list in reverse
void printReverse(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = tail;

    // Use a do-while loop to traverse through the circular list in reverse
    do {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    } while (temp != tail);  // Stop when we reach the tail again

    cout << "(tail)" << endl;  // Indicate circular nature
}

int main() {
    Node* head = NULL;  // Initialize the head pointer to NULL
    Node* tail = NULL;  // Initialize the tail pointer to NULL

    // Insert nodes at the head
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    printLL(head);  // Output: 30 <-> 20 <-> 10 <-> (head)
    printReverse(tail);  // Output: 10 <-> 20 <-> 30 <-> (tail)

    // Insert nodes at the tail
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    printLL(head);  // Output: 30 <-> 20 <-> 10 <-> 40 <-> 50 <-> (head)
    printReverse(tail);  // Output: 50 <-> 40 <-> 10 <-> 20 <-> 30 <-> (tail)

    // Insert nodes at specific positions
    insertAtPosition(head, tail, 15, 4);  // Inserting at position 4
    printLL(head);  // Output: 30 <-> 20 <-> 10 <-> 15 <-> 40 <-> 50 <-> (head)

    insertAtPosition(head, tail, 60, 7);  // Inserting at position 7 (tail)
    printLL(head);  // Output: 30 <-> 20 <-> 10 <-> 15 <-> 40 <-> 50 <-> 60 <-> (head)

    insertAtPosition(head, tail, 5, 1);  // Inserting at position 1 (head)
    printLL(head);  // Output: 5 <-> 30 <-> 20 <-> 10 <-> 15 <-> 40 <-> 50 <-> 60 <-> (head)

    return 0;
}
