#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10; // Print the last digit of the node's data
        node = node->next;
    }
    cout << "\n";
}

class Solution {
  public:
    // Function to reverse the linked list
    Node* reverseLL(Node *head) {
        Node *prev = NULL;
        Node *curr = head;
        
        while (curr) {
            Node *nextNode = curr->next; // Store the next node
            curr->next = prev; // Reverse the link
            prev = curr; // Move prev to current
            curr = nextNode; // Move to the next node
        }
        
        return prev; // New head of the reversed list
    }

    // Function to add 1 to the number represented by the linked list
    Node* addOne(Node* head) {
        // Step 1: Reverse the linked list to make addition easier
        head = reverseLL(head);
        
        // Step 2: Add 1 to the reversed linked list
        int carry = 1; // Initialize carry to 1 (since we are adding 1)
        Node *temp = head;

        // Traverse the list and add carry
        while (temp != NULL) {
            int totalSum = temp->data + carry;
            
            // Update the current node's data
            temp->data = totalSum % 10; // Get the last digit
            carry = (totalSum >= 10) ? 1 : 0; // Update carry for next node

            // Move to the next node
            if (temp->next == NULL && carry > 0) {
                // If this is the last node and we still have a carry
                temp->next = new Node(carry); // Create a new node with the carry
                carry = 0; // Reset carry
            }
            
            temp = temp->next; // Move to the next node
        }

        // Step 3: Reverse the list again to restore original order
        head = reverseLL(head);
        
        // Return the head of the modified list
        return head;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Parse input numbers into vector
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        // Create linked list from the input vector
        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data); // Add new node to the list
            tail = tail->next;
        }

        Solution ob;
        head = ob.addOne(head); // Add one to the number represented by the list
        printList(head); // Print the result
    }
    return 0;
}

