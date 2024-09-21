#include <iostream>
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
    // 📏 Function to calculate the length of the linked list
    int getLength(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next; // Move to the next node
        }
        return length; // 🎯 Return the length of the list
    }

    // 📜 Function to rotate the linked list to the right by k places
    // Algorithm:
    // 1️⃣ If the head is null, return null.
    // 2️⃣ Calculate the length of the linked list.
    // 3️⃣ Calculate the actual number of rotations needed (k % length).
    // 4️⃣ If actualRotateK is 0 or k is equal to the length, return the original head.
    // 5️⃣ Find the position of the new last node (length - actualRotateK - 1).
    // 6️⃣ Detach the new last node and update the next pointer to null.
    // 7️⃣ Find the last node of the new head and link it to the original head.
    // 8️⃣ Return the new head of the rotated list.
    ListNode* rotateRight(ListNode* head, int k) {
        // 🛑 Base case: If the head is null, return null
        if (!head) return nullptr;

        int length = getLength(head); // Calculate length of the list
        int actualRotateK = (k % length); // Determine effective rotations

        // 🛑 If no rotations are needed, return the original head
        if (actualRotateK == 0 || k == length) return head;

        // 🔄 Calculate the position of the new last node
        int newLastNodePos = length - actualRotateK - 1;
        ListNode* newLastNode = head;
        for (int i = 0; i < newLastNodePos; i++) {
            newLastNode = newLastNode->next; // Move to the new last node
        }

        // 🔄 Detach the new last node
        ListNode* newHead = newLastNode->next; // Set new head
        newLastNode->next = nullptr; // Break the link

        // 🔄 Find the end of the new head list and link it to the original head
        ListNode* it = newHead;
        while (it->next) {
            it = it->next; // Traverse to the end of the new head list
        }
        it->next = head; // Connect the end of the new list to the original head

        return newHead; // 🎉 Return the new head of the rotated list
    }
};

// 🏁 Main function for testing
int main() {
    Solution solution;

    // 🧪 Example test case: Creating a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2; // Rotate the list by 2 positions

    // 📤 Rotate the linked list
    ListNode* rotatedList = solution.rotateRight(head, k);

    // 📜 Output the rotated list
    ListNode* current = rotatedList;
    while (current) {
        cout << current->val << " ";
        current = current->next; // Move to the next node
    }
    cout << endl;

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the linked list. The list is traversed a constant number of times.

💾 Space Complexity:
- O(1), since the rotation is done in place without using extra space for nodes.

📊 Example Output:
4 5 1 2 3 
*/
