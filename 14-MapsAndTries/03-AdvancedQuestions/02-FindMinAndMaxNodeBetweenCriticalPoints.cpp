#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX
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
    // 📜 Function to find distances between critical points in the linked list
    // Algorithm:
    // 1️⃣ Initialize a vector to store the result: minimum distance and distance between first and last critical points.
    // 2️⃣ Set pointers for previous, current, and next nodes.
    // 3️⃣ Traverse the list to identify critical points (local maxima and minima).
    // 4️⃣ Update the first and last critical points' indices, as well as the minimum distance between them.
    // 5️⃣ If only one or no critical points are found, return {-1, -1}.
    // 6️⃣ Otherwise, return the minimum distance and the distance between the first and last critical points.
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1}; // Initialize result vector
        ListNode* prev = head; // Pointer to the previous node
        if (!prev) return ans; // If the list is empty, return {-1, -1}
        ListNode* curr = head->next; // Pointer to the current node
        if (!curr) return ans; // If there's only one node, return {-1, -1}
        ListNode* nxt = head->next->next; // Pointer to the next node
        if (!nxt) return ans; // If there are only two nodes, return {-1, -1}

        int firstCP = -1; // First critical point index
        int lastCP = -1; // Last critical point index
        int minDist = INT_MAX; // Minimum distance between critical points
        int i = 1; // Counter for node index

        // 🔄 Traverse the list to find critical points
        while (nxt) {
            bool isCP = ((curr->val > prev->val && curr->val > nxt->val) || 
                         (curr->val < prev->val && curr->val < nxt->val));

            // If it's a critical point
            if (isCP) {
                if (firstCP == -1) { // If it's the first critical point
                    firstCP = i;
                    lastCP = i;
                } else { // Update last critical point
                    minDist = min(minDist, i - lastCP); // Update minimum distance
                    lastCP = i; // Update last critical point
                }
            }

            // Move pointers forward
            i++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }

        // 📏 Check if we found at least two critical points
        if (firstCP == lastCP) {
            return ans; // Return {-1, -1} if only one critical point was found
        } else {
            ans[0] = minDist; // Minimum distance between critical points
            ans[1] = lastCP - firstCP; // Distance between first and last critical points
        }
        return ans; // 🎉 Return the result vector
    }
};

// 🏁 Main function for testing
int main() {
    Solution solution;

    // 🧪 Example test case: Creating a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(3);

    // 📤 Get distances between critical points
    vector<int> result = solution.nodesBetweenCriticalPoints(head);

    // 📜 Output the result
    cout << "Minimum distance: " << result[0] << ", Distance between first and last critical points: " << result[1] << endl;

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the linked list. Each node is visited exactly once.

💾 Space Complexity:
- O(1), since only a constant amount of space is used for pointers and variables.

📊 Example Output:
Minimum distance: 1, Distance between first and last critical points: 4
*/
