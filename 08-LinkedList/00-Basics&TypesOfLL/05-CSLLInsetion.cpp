#include<iostream>
using namespace std;

class Node {
public:
    int data;     // Data stored in the node
    Node *next;   // Pointer to the next node in the circular linked list

    // Default constructor
    Node() {
        this->next = NULL;
    }

    // Parameterized constructor to initialize a node with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to insert a new node at the head of the circular linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
    // Create a new node
    Node* newNode = new Node(data);

    // If the list is empty
    if (head == NULL) {
        head = newNode;  // Head points to the new node
        tail = newNode;  // Tail also points to the new node
        newNode->next = head;  // Circular link: next of new node points to itself (head)
    } 
    else {
        // Set the new node's next pointer to the current head
        newNode->next = head;
        // Tail's next pointer should point to the new head
        tail->next = newNode;
        // Update head to the new node
        head = newNode;
    }
}

// Function to insert a new node at the tail of the circular linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
    // Create a new node
    Node* newNode = new Node(data);

    // If the list is empty
    if (head == NULL) {
        head = newNode;  // Head points to the new node
        tail = newNode;  // Tail also points to the new node
        newNode->next = head;  // Circular link: next of new node points to itself (head)
    } 
    else {
        // Set the tail's next pointer to the new node
        tail->next = newNode;
        // Update the new node's next pointer to the head to maintain circularity
        newNode->next = head;
        // Update the tail pointer to the new node
        tail = newNode;
    }
}

// Function to insert a node at a specific position in the circular linked list
void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
    // If the position is 1, insert at the head
    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    // Create a new node
    Node* newNode = new Node(data);

    // Traverse the list to find the node before the desired position
    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // If the insertion is at the tail position
    if (temp->next == head) {
        insertAtTail(head, tail, data);
    } 
    else {
        // Insert the new node at the desired position
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to print the circular linked list
void printLL(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    // Use a do-while loop to traverse through the circular list
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);  // Stop when we are back at the head node

    cout << "(head)" << endl;  // Indicate the circular nature
}

int main() {
    Node* head = NULL;  // Initialize the head pointer to NULL
    Node* tail = NULL;  // Initialize the tail pointer to NULL

    // Insert nodes at the head
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    printLL(head);  // Output: 30 -> 20 -> 10 -> (head)

    // Insert nodes at the tail
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    printLL(head);  // Output: 30 -> 20 -> 10 -> 40 -> 50 -> (head)

    // Insert nodes at specific positions
    insertAtPosition(head, tail, 15, 4);  // Inserting at position 4
    printLL(head);  // Output: 30 -> 20 -> 10 -> 15 -> 40 -> 50 -> (head)

    insertAtPosition(head, tail, 60, 7);  // Inserting at position 7 (tail)
    printLL(head);  // Output: 30 -> 20 -> 10 -> 15 -> 40 -> 50 -> 60 -> (head)

    insertAtPosition(head, tail, 5, 1);  // Inserting at position 1 (head)
    printLL(head);  // Output: 5 -> 30 -> 20 -> 10 -> 15 -> 40 -> 50 -> 60 -> (head)

    return 0;
}
