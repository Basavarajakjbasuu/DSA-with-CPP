#include <iostream>
#include <map>
using namespace std;

// 🚧 Definition for the Node structure
struct Node {
    int data;       // Data held by the node
    Node* next;     // Pointer to the next node

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// 🔄 Algorithm to create a union of two linked lists:
// 1️⃣ Use a sorted map to store unique values from both lists.
// 2️⃣ Traverse both lists and add their values to the map.
// 3️⃣ Create a new linked list from the values in the map, which ensures sorted unique elements.
// 4️⃣ Return the head of the new union list.

class Solution {
public:
    Node* makeUnion(Node* head1, Node* head2) {
        map<int, Node*> uniqueNodes; // To store unique values (automatically sorted)
        
        // Traverse list 1 and add nodes to the map
        Node* curr = head1;
        while (curr != NULL) {
            uniqueNodes[curr->data] = curr;
            curr = curr->next;
        }

        // Traverse list 2 and add nodes to the map
        curr = head2;
        while (curr != NULL) {
            uniqueNodes[curr->data] = curr;
            curr = curr->next;
        }

        // Create the union list using the map (sorted unique values)
        Node* unionList = NULL;
        Node* unionTail = NULL;

        for (auto it = uniqueNodes.begin(); it != uniqueNodes.end(); ++it) {
            if (!unionList) {
                unionList = new Node(it->first); // Initialize the union list
                unionTail = unionList;
            } else {
                unionTail->next = new Node(it->first); // Add new node to the union list
                unionTail = unionTail->next;
            }
        }

        return unionList; // Return the head of the new union list
    }
};

// 🧪 Utility function to print linked lists
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// 🏁 Main function to test the solution
int main() {
    // Create two example linked lists:
    // List 1: 10 -> 20 -> 30
    // List 2: 20 -> 40 -> 50

    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);

    Node* head2 = new Node(20);
    head2->next = new Node(40);
    head2->next->next = new Node(50);

    // Solution instance
    Solution solution;
    Node* unionList = solution.makeUnion(head1, head2);

    // Output the result of the union
    cout << "Union of the lists: ";
    printList(unionList);

    return 0;
}

/*
⏳ Time Complexity:
- O(n + m + (n + m)log(n + m)), where n is the size of the first list and m is the size of the second list.
  - O(n + m) to traverse both lists.
  - O((n + m)log(n + m)) for inserting elements into the map.

💾 Space Complexity:
- O(n + m) for the map to store all unique elements from both lists.

📊 Example Output:
Union of the lists: 10 20 30 40 50
*/

