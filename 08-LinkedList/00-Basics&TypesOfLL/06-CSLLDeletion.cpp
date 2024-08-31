#include <iostream>
using namespace std;

class Node {
public:
    int data;         // Data stored in the node
    Node* next;       // Pointer to the next node in the circular singly linked list

    // Constructor to initialize a node with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor to display when a node is deleted
    ~Node() {
        cout << "Node with data " << data << " deleted." << endl;
    }
};

// Function to insert a new node at the tail of the circular singly linked list
void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);

    // If the list is empty, create a circular link
    if (tail == NULL) {
        tail = newNode;
        newNode->next = newNode; // Point the node to itself
    } 
    else {
        newNode->next = tail->next; // Link the new node's next to the head
        tail->next = newNode;       // Link the tail's next to the new node
        tail = newNode;             // Update the tail to the new node
    }
}

// Function to print the circular singly linked list
void printLL(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = tail->next; // Start from the head (next of tail)
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);  // Loop until we circle back to the head

    cout << "(head)" << endl;
}

// Function to delete a node at a specific position in the circular singly linked list
void deleteNode(Node* &tail, int position) {
    // If list is empty
    if (tail == NULL) {
        cout << "List is empty, deletion not possible." << endl;
        return;
    }

    // Case when there's only one node in the list
    if (tail->next == tail) {
        delete tail;
        tail = NULL;
        return;
    }

    // Deleting the first node (head)
    if (position == 1) {
        Node* temp = tail->next;   // Head node (next of tail)
        tail->next = temp->next;   // Update tail's next to the second node
        temp->next = NULL;         // Disconnect the node to be deleted
        delete temp;               // Delete the node
    } 
    else {
        // For deleting a middle or last node
        Node* prev = tail->next;  // Start at the head
        Node* curr = prev->next;
        int count = 1;

        while (count < position - 1 && curr != tail) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        // If deleting the tail node, update the tail
        if (curr == tail) {
            prev->next = curr->next;
            tail = prev;
            curr->next = NULL;
            delete curr;
        } 
        else {
            // Delete the node at the given position
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}

int main() {
    Node* tail = NULL;  // Initialize tail pointer to NULL

    // Insert nodes into the circular singly linked list
    insertAtTail(tail, 10);
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    printLL(tail);  // Output: 10 -> 20 -> 30 -> 40 -> (head)

    // Deleting the first node
    deleteNode(tail, 1);
    printLL(tail);  // Output: 20 -> 30 -> 40 -> (head)

    // Deleting the last node
    deleteNode(tail, 3);
    printLL(tail);  // Output: 20 -> 30 -> (head)

    // Deleting a middle node
    deleteNode(tail, 2);
    printLL(tail);  // Output: 20 -> (head)

    // Deleting the last remaining node
    deleteNode(tail, 1);
    printLL(tail);  // Output: List is empty.

    return 0;
}
