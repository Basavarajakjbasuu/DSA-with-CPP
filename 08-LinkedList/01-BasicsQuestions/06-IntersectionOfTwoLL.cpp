#include <iostream> // Include for input/output operations

// Definition for singly-linked list
struct ListNode {
    int val;           // Value of the node
    ListNode *next;    // Pointer to the next node

    // Constructor for ListNode
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Helper function to get the length of a linked list
    // Time Complexity: O(n), where n is the number of nodes in the list.
    // Space Complexity: O(1), as we only use a constant amount of extra space.
    int getLengthLL(ListNode *head) {
        ListNode *temp = head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    // Function to find the intersection node of two linked lists
    // Time Complexity: O(m + n), where m and n are the lengths of the two lists.
    // Space Complexity: O(1), because we only use a constant amount of extra space.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLengthLL(headA);
        int lenB = getLengthLL(headB);

        // Align the starting points of both lists
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; ++i) {
                headA = headA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; ++i) {
                headB = headB->next;
            }
        }

        // Traverse both lists in parallel to find the intersection
        while (headA && headB) {
            if (headA == headB) return headA;  // Intersection found
            headA = headA->next;
            headB = headB->next;
        }

        // No intersection found
        return nullptr;
    }
};

// Sample usage (not part of the Solution class)
int main() {
    // Create nodes for list A
    ListNode *common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode *headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;

    // Create nodes for list B
    ListNode *headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = common;

    Solution sol;
    ListNode *intersection = sol.getIntersectionNode(headA, headB);

    // Print the result
    if (intersection) {
        std::cout << "Intersection node value: " << intersection->val << std::endl;
    } else {
        std::cout << "No intersection" << std::endl;
    }

    // Free the remaining nodes
    while (headA) {
        ListNode *nextNode = headA->next;
        delete headA;
        headA = nextNode;
    }

    while (headB) {
        ListNode *nextNode = headB->next;
        delete headB;
        headB = nextNode;
    }

    delete common; // Free the common nodes

    return 0;
}

/*
  Intersection node value: 8
*/