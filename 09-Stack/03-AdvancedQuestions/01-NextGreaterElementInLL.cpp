#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to find the next greater value for each node in a singly linked list.
    // Time Complexity: O(n), where n is the number of nodes in the linked list.
    // Space Complexity: O(n), where n is the number of nodes, due to the use of vectors and stack.
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nodeValues;  // Vector to store values from the linked list
        
        // Traverse the linked list and store values in the vector
        while (head) {
            nodeValues.push_back(head->val);
            head = head->next;
        }

        stack<int> indexStack;  // Stack to keep track of indices with unresolved next larger values
        vector<int> result(nodeValues.size(), 0);  // Result vector initialized with zeros

        // Iterate through the vector to determine the next larger value for each element
        for (int i = 0; i < nodeValues.size(); ++i) {
            // Resolve indices in the stack where the current value is larger than the stored value
            while (!indexStack.empty() && nodeValues[i] > nodeValues[indexStack.top()]) {
                int index = indexStack.top();
                indexStack.pop();
                result[index] = nodeValues[i];
            }
            // Push the current index onto the stack
            indexStack.push(i);
        }

        return result;  // Return the vector containing the next larger values for each node
    }
};

// Sample usage (not part of the Solution class)
int main() {
    // Create a linked list for testing: 2 -> 1 -> 5
    ListNode* head = new ListNode(2, new ListNode(1, new ListNode(5)));

    Solution sol;
    vector<int> result = sol.nextLargerNodes(head);

    // Output the result
    cout << "Next larger nodes: ";
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

/*2 -> 1 -> 5
  Next larger nodes: 5 5 0
*/