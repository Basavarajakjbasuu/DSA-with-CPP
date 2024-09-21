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
    // 🔄 Function to rearrange the linked list to odd-even order
    // Algorithm:
    // 1️⃣ Check if the head is null or if there's only one node; if so, return head.
    // 2️⃣ Initialize two pointers: h1 for the head of odd nodes and h2 for the head of even nodes.
    // 3️⃣ Store the head of the even nodes for later connection.
    // 4️⃣ Use a while loop to traverse through the even nodes:
    //    - Adjust the next pointers to separate odd and even indexed nodes.
    //    - Move the h1 pointer to the next odd node and h2 pointer to the next even node.
    // 5️⃣ After the loop, connect the last odd node to the first even node.
    // 6️⃣ Return the modified head of the linked list.
    ListNode* oddEvenList(ListNode* head) {
        if (!head || head->next == nullptr) return head; // 🛑 Check for empty or single-node list

        ListNode* h1 = head; // Pointer for the head of odd nodes
        ListNode* h2 = head->next; // Pointer for the head of even nodes
        ListNode* evenHead = h2; // Store the head of even nodes

        // 🔄 Rearrange nodes in odd-even order
        while (h2 && h2->next) {
            h1->next = h2->next; // Link the current odd node to the next odd node
            h2->next = h2->next->next; // Link the current even node to the next even node
            h1 = h1->next; // Move h1 to the next odd node
            h2 = h2->next; // Move h2 to the next even node
        }

        // 🔗 Connect the last odd node to the first even node
        h1->next = evenHead;

        return head; // 🎉 Return the modified head of the linked list
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

    // 📤 Rearrange the linked list in odd-even order
    ListNode* result = solution.oddEvenList(head);

    // 📜 Output the result
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the linked list. Each node is visited once.

💾 Space Complexity:
- O(1), since we are rearranging nodes in place and using a constant amount of extra space.

📊 Example Output:
1 3 5 2 4 
*/

