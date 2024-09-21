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
    // 🔄 Helper function to recursively double the linked list values
    // Algorithm:
    // 1️⃣ If the current node is null, return.
    // 2️⃣ Recursively call solve for the next node to ensure we process from the end.
    // 3️⃣ Calculate the product by multiplying the current node's value by 2 and adding the carry from the previous node.
    // 4️⃣ Update the current node's value to the last digit of the product (prod % 10).
    // 5️⃣ Update the carry for the next node (prod / 10).
    void solve(ListNode* head, int &carry) {
        if (!head) return; // 🛑 Base case: If node is null, return

        solve(head->next, carry); // 🔄 Recursive call to process the next node

        int prod = head->val * 2 + carry; // 🔢 Calculate product and carry
        head->val = prod % 10; // 🔄 Update current node's value
        carry = prod / 10; // 🔄 Update carry for the next node
    }

    // 💡 Function to double the entire linked list
    // Algorithm:
    // 1️⃣ Initialize carry as 0.
    // 2️⃣ Call the helper function to process the list and handle carry.
    // 3️⃣ If there's a remaining carry after processing, create a new head node.
    // 4️⃣ Return the modified head of the linked list.
    ListNode* doubleIt(ListNode* head) {
        int carry = 0; // 🔢 Initialize carry
        solve(head, carry); // 🔄 Process the linked list

        // 🔄 Handle any remaining carry by creating a new head node
        if (carry) {
            ListNode* newHeadNode = new ListNode(carry); // 📦 Create new node for carry
            newHeadNode->next = head; // 🔗 Link new node to the original head
            head = newHeadNode; // 🔄 Update head to the new node
        }
        return head; // 🎉 Return the updated head of the linked list
    }
};

// 🏁 Main function for testing
int main() {
    Solution solution;

    // 🧪 Example test case: Creating a linked list representing the number 123
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // 📤 Double the linked list
    ListNode* result = solution.doubleIt(head);

    // 📜 Output the result
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the linked list. Each node is processed once.

💾 Space Complexity:
- O(n) in the worst case due to the recursive call stack.

📊 Example Output:
2 4 6 
*/

