#include <iostream>
using namespace std;

// Node structure definition
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Solution class that contains the function to detect a loop in a linked list
class Solution {
public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // Initialize two pointers, fast and slow.
        Node* fast = head;
        Node* slow = head;
        
        // Traverse the list with two pointers, fast moves two nodes ahead and slow moves one node ahead
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next; // Fast pointer moves two steps at a time
            slow = slow->next;       // Slow pointer moves one step at a time
            
            // If fast and slow pointers meet, there is a loop in the linked list
            if (fast == slow) {
                return true;
            }
        }
        // If no loop is found, return false
        return false;
    }
};

int main() {
    // Create linked list nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Introduce a loop for testing (e.g., node 5 points back to node 2)
    head->next->next->next->next->next = head->next;

    // Create a Solution object
    Solution sol;

    // Check if the loop exists in the linked list
    if (sol.detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}
