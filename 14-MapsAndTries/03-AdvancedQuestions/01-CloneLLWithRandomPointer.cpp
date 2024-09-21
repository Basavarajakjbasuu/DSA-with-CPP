#include <iostream>
#include <unordered_map> // For unordered_map
using namespace std;

// 🚧 Definition for a Node in the linked list.
class Node {
public:
    int val;           // Value of the node
    Node* next;       // Pointer to the next node
    Node* random;     // Pointer to a random node

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution1 {
public:
    // 📜 Helper function to recursively copy nodes
    Node* helper(Node* head, unordered_map<Node*, Node*>& mp) {
        // 🛑 Base case: If the head is null, return null
        if (!head) return NULL;

        // 🔄 Create a new node with the value of the current node
        Node* newHead = new Node(head->val);
        mp[head] = newHead; // Store the mapping of old node to new node

        // 🔄 Recursively copy the next node
        newHead->next = helper(head->next, mp);

        // 🔄 Copy the random pointer using the map
        if (head->random) {
            newHead->random = mp[head->random];
        }

        return newHead; // 🎉 Return the newly created node
    }

    // 📜 Function to create a deep copy of the linked list with random pointers
    // Algorithm:
    // 1️⃣ Initialize an unordered_map to store mappings from old nodes to new nodes.
    // 2️⃣ Define a helper function that takes the current node and the map as parameters.
    // 3️⃣ If the current node is null, return null.
    // 4️⃣ Create a new node for the current node and store its mapping in the unordered_map.
    // 5️⃣ Recursively call the helper function for the next node and set the new node's next pointer.
    // 6️⃣ If the current node has a random pointer, map it to the copied node using the unordered_map.
    // 7️⃣ Return the newly created node.
    // 8️⃣ In the main function, call the helper function with the head of the original list to get the deep copy.
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp; // Map to store old nodes and their copies
        return helper(head, mp); // Start the recursive copying process
    }
};

class Solution {
public:
    // 📜 Function to create a deep copy of the linked list with random pointers
    // Algorithm:
    // 1️⃣ If the head is null, return null.
    // 2️⃣ Clone the nodes by inserting a new node next to each original node.
    // 3️⃣ Set the random pointers of the cloned nodes using the original nodes' random pointers.
    // 4️⃣ Detach the original and cloned nodes to restore the original list and separate the cloned list.
    // 5️⃣ Return the head of the cloned list.
    Node* copyRandomList(Node* head) {
        // 🛑 Base case: If the head is null, return null
        if (!head) return nullptr;

        Node* it = head; 

        // 🔄 Clone A->A'
        while(it) {
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next; // Link new node to the next original node
            it->next = clonedNode; // Link original node to the cloned node
            it = clonedNode->next; // Move to the next original node
        }

        it = head;

        // 🔄 Attach old node random to new node random
        while(it) {
            Node* clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : nullptr; // Set random pointer
            it = clonedNode->next; // Skip the cloned node
        }

        // 🔄 Detach old nodes from cloned nodes
        it = head;
        Node* clonedHead = it->next; // Head of the cloned list
        while(it) {
            Node* clonedNode = it->next; // Current cloned node
            it->next = clonedNode->next; // Restore the original list
            if (clonedNode->next) {
                clonedNode->next = clonedNode->next->next; // Link cloned nodes
            }
            it = it->next; // Move to the next original node
        }

        return clonedHead; // 🎉 Return the head of the cloned list
    }
};

// 🏁 Main function for testing
int main() {
    Solution solution;

    // 🧪 Example test case: Creating a linked list with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next; // 1's random points to 2
    head->next->random = head; // 2's random points to 1
    head->next->next->random = head->next; // 3's random points to 2

    // 📤 Creating a deep copy of the linked list
    Node* copiedList = solution.copyRandomList(head);

    // 📜 Output the copied list to verify
    Node* current = copiedList;
    while (current) {
        cout << "Node Value: " << current->val;
        if (current->random) {
            cout << ", Random Value: " << current->random->val;
        } else {
            cout << ", Random Value: NULL";
        }
        cout << endl;
        current = current->next;
    }

    return 0;
}

/*
⏳ Time Complexity:
- O(n), where n is the number of nodes in the linked list. Each node is processed once.

💾 Space Complexity:
- O(n) for the unordered_map storing the mapping from old nodes to new nodes.

📊 Example Output:
Node Value: 1, Random Value: 2
Node Value: 2, Random Value: 1
Node Value: 3, Random Value: 2

*/
