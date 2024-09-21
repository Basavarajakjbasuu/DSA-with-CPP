#include <iostream>

// 🚀 Algorithm Explanation:
// The solution uses the **Merge Sort** algorithm to sort a linked list. 
// 1. **Find the Middle**: We first find the middle of the list to split it into two halves.
// 2. **Recursively Sort**: We recursively sort both halves.
// 3. **Merge**: Finally, we merge the two sorted halves into one sorted list.
// 
// 🕒 Time Complexity: O(n log n), where n is the number of nodes in the list.
// 💾 Space Complexity: O(log n) for the recursion stack.

// Definition for singly-linked list
struct ListNode {
    int val;            // 💡 Value of the node
    ListNode* next;     // 🔗 Pointer to the next node

    // 👷 Constructors for ListNode
    ListNode() : val(0), next(nullptr) {} // Default constructor
    ListNode(int x) : val(x), next(nullptr) {} // Constructor with value
    ListNode(int x, ListNode* next) : val(x), next(next) {} // Constructor with value and next node
};

class Solution {
public:
    // 🛠️ Function to find the middle node of the linked list
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // 💨 Fast pointer starts ahead

        // 🔄 Move slow by 1 and fast by 2 until fast reaches the end
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;  // 🎯 Return the middle node
    }

    // 🛠️ Function to merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;  // 🧐 If list1 is empty, return list2
        if (!list2) return list1;  // 🧐 If list2 is empty, return list1

        ListNode dummy(0);  // ✨ Create a dummy node to simplify merging
        ListNode* current = &dummy;

        // 🔄 Traverse both lists and merge them
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;  // 📌 Append node from list1
                list1 = list1->next;   // 👉 Move to the next node in list1
            } else {
                current->next = list2;  // 📌 Append node from list2
                list2 = list2->next;   // 👉 Move to the next node in list2
            }
            current = current->next;  // 👉 Move to the next node in the merged list
        }

        // 🧐 If there are remaining nodes in either list, append them
        current->next = list1 ? list1 : list2;

        return dummy.next;  // 🔚 Return the merged list
    }

    // 🛠️ Function to sort the linked list using merge sort
    ListNode* sortList(ListNode* head) {
        // 🧐 Base case: If the list is empty or has only one node, it's already sorted
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 🔍 Find the middle of the list
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;  // ✂️ Split the list into two halves

        // 🔄 Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // 🔗 Merge the sorted halves
        return merge(left, right);
    }
};

// 🧑‍💻 Main function for local execution
int main() {
    // 📦 Create unsorted linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution sol;
    ListNode* sortedList = sol.sortList(head);  // 🔗 Sort the linked list

    // 🖨️ Print the sorted linked list
    ListNode* temp = sortedList;
    while (temp) {
        std::cout << temp->val << " ";  // 🖨️ Print the node's value
        temp = temp->next;  // 👉 Move to the next node
    }

    // 🧹 Free the memory of the linked list
    while (sortedList) {
        ListNode* nextNode = sortedList->next;
        delete sortedList;  // 🗑️ Delete current node
        sortedList = nextNode;
    }

    return 0;  // 🎉 Successful execution
}

/* Example:
    Input: 4 -> 2 -> 1 -> 3
    Output: 1 -> 2 -> 3 -> 4
*/
