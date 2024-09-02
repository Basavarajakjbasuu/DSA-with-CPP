#include <iostream> // Include for input/output operations

// Definition for singly-linked list
struct ListNode {
    int val;           // Value of the node
    ListNode *next;    // Pointer to the next node

    // Constructors for ListNode
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Method to merge two sorted linked lists
    // Time Complexity: O(m + n), where m and n are the lengths of the two lists.
    // Space Complexity: O(1), because we only use a constant amount of extra space.
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If one of the lists is empty, return the other list
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        // Create a dummy node to simplify merging
        ListNode dummyNode(0);
        ListNode *current = &dummyNode;  // Pointer to build the new list

        // Traverse both lists and merge them
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                current->next = list1;  // Append node from list1
                list1 = list1->next;   // Move to next node in list1
            } else {
                current->next = list2;  // Append node from list2
                list2 = list2->next;   // Move to next node in list2
            }
            current = current->next;  // Move to the next node in the merged list
        }

        // If there are remaining nodes in list1, append them
        if (list1 != NULL) {
            current->next = list1;
        }

        // If there are remaining nodes in list2, append them
        if (list2 != NULL) {
            current->next = list2;
        }

        // Return the merged list, starting from the next of dummyNode
        return dummyNode.next;
    }
};

// Sample usage (not part of the Solution class)
int main() {
    // Create nodes for list1
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // Create nodes for list2
    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution sol;
    ListNode *mergedList = sol.mergeTwoLists(list1, list2);

    // Print the merged list
    ListNode *temp = mergedList;
    while (temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }

    // Free the remaining nodes in the merged list
    while (mergedList) {
        ListNode *nextNode = mergedList->next;
        delete mergedList;
        mergedList = nextNode;
    }

    return 0;
}

/* 1.
    1->3->5 2->4->6 - inp
    1 2 3 4 5 6 - otp
*/