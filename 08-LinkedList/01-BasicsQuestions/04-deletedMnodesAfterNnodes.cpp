#include <iostream> // Include for input/output operations

// Define the Node structure
struct Node {
    int data;           // Data part of the node
    struct Node *next;  // Pointer to the next node

    // Constructor to initialize node
    Node(int x) : data(x), next(nullptr) {}
};

// Solution class with the linkdelete method
class Solution {
public:
    // Method to delete n nodes after skipping m nodes
    void linkdelete(struct Node **head, int n, int m) {
        // Check if the head pointer is null
        if (!head || !(*head)) return;

        Node *current = *head;  // Initialize the current pointer to the head of the list
        Node *temp = nullptr;   // Temporary pointer for deletion

        // Traverse the linked list
        while (current) {
            // Skip m nodes
            for (int i = 1; i < m && current != nullptr; ++i) {
                current = current->next;
            }

            // If current is null, we've reached the end of the list
            if (!current) return;

            // Now 'current' is at the m-th node, we start deleting the next n nodes
            temp = current->next;
            for (int i = 1; i <= n && temp != nullptr; ++i) {
                Node *nextNode = temp->next;  // Save the next node
                delete temp;                  // Delete the current node
                temp = nextNode;             // Move to the next node
            }

            // Link the m-th node to the node after the n deleted nodes
            current->next = temp;
            
            // Move to the next segment of the list
            current = temp;
        }
    }
};

// Sample usage (not part of the Solution class)
int main() {
    // Create nodes
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    
    Solution sol;
    int m = 2;  // Number of nodes to skip
    int n = 2;  // Number of nodes to delete
    
    sol.linkdelete(&head, n, m);

    // Print the modified list
    Node *temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    // Free the remaining nodes
    while (head) {
        Node *nextNode = head->next;
        delete head;
        head = nextNode;
    }

    return 0;
}
/*1. 
    1->2->3->4->5->6 m=2 n=2
    1 2 5 6 
*/