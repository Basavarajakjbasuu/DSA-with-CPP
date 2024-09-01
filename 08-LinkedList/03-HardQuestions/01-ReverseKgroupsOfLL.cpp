#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to get the length of the linked list
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        
        // Traverse the linked list and count nodes
        while (temp) {
            length++;
            temp = temp->next;
        }
        
        return length;
    }

    // Function to reverse nodes in k-group
    ListNode* reverseKGroup(ListNode* head, int k) {
        // If the list is empty or has only one node, no reversal needed
        if (head == NULL || head->next == NULL) return head;
        
        // Get the length of the linked list
        int lengthOfLL = getLength(head);
        
        // If there are fewer than k nodes, no need to reverse
        if (lengthOfLL < k) {
            return head;
        }

        // Initialize pointers for reversal
        ListNode *curr = head; // Current node
        ListNode *prev = NULL; // Previous node
        ListNode *nextNode = NULL; // Next node
        int pos = 0;
        
        // Reverse the first k nodes
        while (pos < k) {
            nextNode = curr->next; // Store the next node
            curr->next = prev; // Reverse the current node's link
            prev = curr; // Move prev to current node
            curr = nextNode; // Move to next node
            pos++;
        }
        
        // Recursively reverse the remaining list
        ListNode *recurssionAns = NULL;
        if (nextNode) {
            recurssionAns = reverseKGroup(nextNode, k); // Reverse the next k-group
            head->next = recurssionAns; // Connect the current reversed segment to the result of the recursive call
        }

        // Return the new head of the reversed segment
        return prev;
    }
};

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return NULL;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;
    for (size_t i = 1; i < values.size(); ++i) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }
    return head;
}

int main() {
    // Example input: 1->2->3->4->5->6 and k = 2
    vector<int> values = {1, 2, 3, 4, 5, 6};
    int k = 2;

    // Create the linked list from the example input
    ListNode* head = createList(values);

    // Instantiate Solution and call reverseKGroup
    Solution solution;
    ListNode* newHead = solution.reverseKGroup(head, k);

    // Print the modified linked list
    printList(newHead);

    return 0;
}


/*1. 
  vector<int> values = {1, 2, 3, 4, 5, 6};
  2 1 4 3 6 5 
*/