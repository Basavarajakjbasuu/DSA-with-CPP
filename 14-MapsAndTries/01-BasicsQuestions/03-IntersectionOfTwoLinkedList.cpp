#include <iostream>
#include <unordered_map>
using namespace std;

// 🚧 Definition for the Node structure
struct Node {
    int data;       // Data held by the node
    Node* next;     // Pointer to the next node

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// 🔄 Algorithm to find the intersection of two linked lists:
// 1️⃣ Traverse the second list (head2) and store each value in a hash map.
// 2️⃣ Traverse the first list (head1) and check if the current node's value exists in the hash map.
// 3️⃣ If it exists, add it to the intersection list.
// 4️⃣ Ensure there are no duplicates in the intersection list by decrementing the count in the map.
// 5️⃣ Return the intersection list.

class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int, int> nodeMap; // To store occurrences of nodes from the second list
        Node* current = head2;

        // Hash all elements of the second list (head2)
        while (current != NULL) {
            nodeMap[current->data]++;
            current = current->next;
        }

        // To store the intersection list
        Node* intersectionList = NULL;
        Node* intersectionTail = NULL;
        current = head1;

        // Traverse the first list (head1) and look for common elements
        while (current != NULL) {
            if (nodeMap.find(current->data) != nodeMap.end() && nodeMap[current->data] > 0) {
                // If common element is found, add it to the intersection list
                if (!intersectionList) {
                    intersectionList = new Node(current->data); // Initialize the list
                    intersectionTail = intersectionList;
                } else {
                    intersectionTail->next = new Node(current->data); // Append to the list
                    intersectionTail = intersectionTail->next;
                }
                nodeMap[current->data]--; // Decrement the count to avoid duplicates
            }
            current = current->next;
        }

        return intersectionList; // Return the head of the intersection list
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
    // List 1: 10 -> 20 -> 30 -> 40
    // List 2: 15 -> 20 -> 30 -> 50

    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = new Node(40);

    Node* head2 = new Node(15);
    head2->next = new Node(20);
    head2->next->next = new Node(30);
    head2->next->next->next = new Node(50);

    // Solution instance
    Solution solution;
    Node* intersectionList = solution.findIntersection(head1, head2);

    // Output the result of the intersection
    cout << "Intersection of the lists: ";
    printList(intersectionList);

    return 0;
}

/*
⏳ Time Complexity:
- O(n + m), where n is the length of the first list and m is the length of the second list.
  - O(m) to traverse and hash the second list.
  - O(n) to traverse the first list and build the intersection.

💾 Space Complexity:
- O(m) for the hash map to store the nodes of the second list.

📊 Example Output:
Intersection of the lists: 20 30
*/

