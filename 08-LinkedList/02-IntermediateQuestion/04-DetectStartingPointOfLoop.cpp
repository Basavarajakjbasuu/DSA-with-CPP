#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Function to detect the cycle in a singly-linked list
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        // Step 1: Detect if there is a cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) break;
        }

        // No cycle detected
        if (!fast || !fast->next) return NULL;

        // Step 2: Find the cycle's start point
        // start to traverse from slow and head by one step
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // The node where the cycle begins
        return slow;
    }
};

int main() {
    // Create nodes
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Create a linked list: 3 -> 2 -> 0 -> -4
    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create a cycle (node4 points to node2)
    node4->next = node2;

    // Create a Solution object
    Solution solution;

    // Detect cycle
    ListNode* cycleNode = solution.detectCycle(head);

    // Print result
    if (cycleNode) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}

// Cycle detected at node with value: 2