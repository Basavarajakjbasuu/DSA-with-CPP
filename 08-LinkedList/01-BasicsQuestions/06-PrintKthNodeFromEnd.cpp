#include <iostream> // Include for input/output operations

// Definition for singly-linked list
struct Node {
    int data;           // Data of the node
    Node *next;         // Pointer to the next node

    // Constructor for Node
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    // Function to find the data of the kth node from the end of a linked list.
    // Time Complexity: O(n), where n is the number of nodes in the linked list.
    // Space Complexity: O(1), because we only use a constant amount of extra space.
    int getKthFromLast(Node *head, int k) {
        Node *slow = head;  // Pointer to traverse the list slowly
        Node *fast = head;  // Pointer to traverse the list quickly
        
        // Move fast pointer k nodes ahead
        for (int i = 0; i < k; ++i) {
            // If there are fewer than k nodes in the list
            if (!fast) return -1;
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the end of the list
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Return the data of the kth node from the end
        return slow->data;
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

    Solution sol;
    int k = 2;  // Example: get the 2nd node from the end

    int result = sol.getKthFromLast(head, k);

    // Print the result
    if (result != -1) {
        std::cout << "The " << k << "th node from the end is " << result << std::endl;
    } else {
        std::cout << "The list is shorter than " << k << " nodes." << std::endl;
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
  1->2->3->4->5 & k=2
  The 2th node from the end is 4
*/