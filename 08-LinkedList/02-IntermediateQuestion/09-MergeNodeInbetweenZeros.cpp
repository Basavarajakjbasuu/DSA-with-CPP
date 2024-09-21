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
    // 📚 Function to merge nodes between zeros in a linked list
    // Algorithm:
    // 1️⃣ Initialize two pointers: slow for the current node in the new list, and fast to traverse the original list.
    // 2️⃣ Initialize a sum variable to keep track of the sum of values between zeros.
    // 3️⃣ Traverse the list using the fast pointer:
    //    - If the current value is not zero, add it to sum.
    //    - If the current value is zero, set the slow node's value to the sum and reset the sum to zero.
    //    - Move the slow pointer to the next position.
    // 4️⃣ After the loop, disconnect any remaining nodes after the last merged node.
    // 5️⃣ Delete the remaining nodes to prevent memory leaks.
    // 6️⃣ Return the head of the modified linked list.
    ListNode* mergeNodes(ListNode* head) {
        if (!head) return nullptr; // Return null if the list is empty

        ListNode* slow = head; // Pointer to the current node in the new list
        ListNode* fast = head->next; // Pointer to traverse the original list
        ListNode* newLastNode = nullptr; // Pointer to track the last node in the new list
        int sum = 0;  // Initialize sum for values between zeros

        // 🔄 Traverse the list
        while (fast) {
            // If the current node value is not zero, add it to the sum
            if (fast->val != 0) {
                sum += fast->val;    
            } else {
                // If a zero is found, assign the sum to the slow node
                slow->val = sum;
                sum = 0; // Reset sum for the next segment
                newLastNode = slow; // Update newLastNode to the current slow node
                slow = slow->next; // Move slow to the next position
            }
            fast = fast->next; // Move fast to the next position
        }

        // 🗑️ Disconnect remaining nodes
        ListNode* temp = newLastNode->next; // Start from the next of last node
        newLastNode->next = nullptr; // Disconnect the new last node

        // 🔥 Clean up the remaining nodes to avoid memory leaks
        while (temp) {
            ListNode* nxt = temp->next;
            delete temp; // Free memory for the node
            temp = nxt; // Move to the next node
        }

        return head; // 🎉 Return the head of the modified linked list
    }
};

// 🏁 Main function for testing
int main() {
    Solution solution;

    // 🧪 Example test case: Creating a linked list with values
    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(0);

    // 📤 Merge nodes between zeros
    ListNode* result = solution.mergeNodes(head);

    // 📜 Output the result
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the linked list. Each node is visited exactly once.

💾 Space Complexity:
- O(1), since only a constant amount of space is used for pointers and variables.

📊 Example Output:
4 9
*/
