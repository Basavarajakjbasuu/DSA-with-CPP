//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for a linked list node
struct Node {
    int data;
    Node* next;

    // Constructor to create a new node with given data
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to create a loop in the linked list
void loopHere(Node* head, Node* tail, int position) {
    if (position == 0)
        return;  // No loop if position is 0

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;  // Creating the loop by connecting tail to the node at 'position'
}

// Function to check if there is a loop in the linked list
bool isLoop(Node* head) {
    if (!head)
        return false;

    Node* fast = head->next;
    Node* slow = head;

    // Floyd's Cycle-Finding Algorithm
    while (fast != slow) {
        if (!fast || !fast->next)
            return false;  // No loop found
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;  // Loop found
}

// Function to calculate the length of the linked list
int length(Node* head) {
    int ret = 0;
    while (head) {
        ret++;
        head = head->next;
    }
    return ret;
}

// Function to check if the linked list is altered
bool notOriginal(Node* head, unordered_map<Node*, int>& myMap) {
    while (head) {
        if (myMap.find(head) == myMap.end())  // Node not found in original map
            return true;
        if (myMap[head] != head->data)  // Data mismatch
            return true;
        head = head->next;
    }
    return false;  // List is unchanged
}

// } Driver Code Ends

// Solution class to remove the loop in the linked list
class Solution {
public:
    // Function to remove the loop in the linked list
    void removeLoop(Node* head) {
        if (!head || !head->next) return;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect if a loop exists using Floyd's Cycle-Finding Algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) break;  // Loop detected
        }

        // If no loop is detected, return
        if (slow != fast) return;

        // Step 2: Find the start of the loop
        slow = head;
        if (slow == fast) {  // Special case: loop starts at the head
            while (fast->next != slow) fast = fast->next;
        } else {  // Normal case: move both pointers one step at a time until they meet
            while (fast->next != slow->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Remove the loop by setting the last node's next to NULL
        fast->next = NULL;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;  // Number of test cases
    cin.ignore();  // Ignore the newline after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);  // Read the linked list as a space-separated string
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);  // Store the linked list values
        }

        unordered_map<Node*, int> myMap;  // To store the original nodes and their values

        int n = arr.size();
        if (n == 0) continue;  // Skip empty test case

        Node *head, *tail;
        head = new Node(arr[0]);
        tail = head;
        myMap[head] = arr[0];

        for (int i = 1; i < n; i++) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
            myMap[tail] = arr[i];
        }

        int pos;
        cin >> pos;  // Position at which the loop is to be created
        cin.ignore();  // Ignore the newline after the integer input
        loopHere(head, tail, pos);  // Create a loop in the linked list

        Solution ob;
        ob.removeLoop(head);  // Remove the loop if present

        // Check if the loop is removed and the list remains intact
        if (isLoop(head) || length(head) != n || notOriginal(head, myMap))
            cout << "false\n";
        else
            cout << "true\n";
    }
    return 0;
}
// } Driver Code Ends

/*
  1 2 3 4
  2
  true
*/