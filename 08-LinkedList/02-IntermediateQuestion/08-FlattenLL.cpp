#include <iostream>
using namespace std;

// 🚧 Definition for a linked list node with a bottom pointer.
struct Node {
    int data;          // Value of the node
    Node* next;       // Pointer to the next node
    Node* bottom;     // Pointer to the bottom node
    Node(int val) : data(val), next(nullptr), bottom(nullptr) {} // Constructor
};

class Solution {
public:
    /*
      📝 Algorithm:
      1. **Merge Function**:
        - If one of the lists is empty, return the other.
        - Compare the current nodes of both lists.
        - Recursively merge the smaller node with the rest of the lists.
        - Return the merged list.

    */
    // 📜 Function to merge two sorted linked lists with bottom pointers
    Node* mergeLL(Node* list1, Node* list2) {
        // 🛑 Base case: If either list is null, return the other list
        if (!list1) return list2;
        if (!list2) return list1;

        Node* mergedList = nullptr; // Pointer to hold the merged list

        // 🔄 Compare the current nodes and merge accordingly
        if (list1->data < list2->data) {
            mergedList = list1; // Start with list1
            mergedList->bottom = mergeLL(list1->bottom, list2); // Merge remaining
        } else {
            mergedList = list2; // Start with list2
            mergedList->bottom = mergeLL(list1, list2->bottom); // Merge remaining
        }

        return mergedList; // 🎉 Return the head of the merged list
    }

    /*
       **Flatten Function**:
        - If the root is null, return null.
        - Recursively flatten the next list.
        - Merge the current list with the flattened next list.
        - Return the head of the merged list.
    */
    // 📜 Function to flatten the linked list
    Node* flatten(Node* root) {
        // 🛑 Base case: If the root is null, return null
        if (!root) return nullptr;

        // 🔄 Recursively flatten the next list and merge with the current list
        Node* flattenedList = mergeLL(root, flatten(root->next));

        return flattenedList; // 🎉 Return the head of the flattened list
    }
};

// 🏁 Main function for testing
int main() {
    Solution solution;

    // 🧪 Example test case: Creating a linked list with bottom pointers
    Node* root = new Node(5);
    root->bottom = new Node(10);
    root->bottom->bottom = new Node(19);
    root->bottom->bottom->bottom = new Node(28);

    Node* secondList = new Node(7);
    secondList->bottom = new Node(8);
    secondList->bottom->bottom = new Node(30);

    Node* thirdList = new Node(20);

    // Linking the lists together
    root->next = secondList;
    secondList->next = thirdList;

    // 📤 Flattening the linked list
    Node* flattenedList = solution.flatten(root);

    // 📜 Output the flattened list
    Node* current = flattenedList;
    cout << "Flattened linked list: ";
    while (current) {
        cout << current->data << " ";
        current = current->bottom;
    }
    cout << endl;

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the total number of nodes across all lists. Each node is processed once.

💾 Space Complexity:
- O(n) for the recursive stack in the worst case, where n is the height of the recursion.

📊 Example Output:
Flattened linked list: 5 7 8 10 19 20 28 30


*/
