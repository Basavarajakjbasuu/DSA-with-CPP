#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/* Node structure for linked list */
struct Node {
    int data;
    Node* next;

    // Constructor to initialize the node
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    // Function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* previousNode = nullptr;
        Node* currentNode = head;

        // Traverse through the list and reverse pointers
        while (currentNode != nullptr) {
            Node* newNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = newNode;
        }
        // Return the new head of the reversed list
        return previousNode;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int T;  // Number of test cases
    cin >> T;
    cin.ignore();  // Ignore the newline after the number of test cases

    // Loop for each test case
    while (T--) {
        Node* head = nullptr;
        Node* tail = nullptr;

        vector<int> arr;
        string input;
        getline(cin, input);  // Read the entire line of input
        stringstream ss(input);  // Use stringstream to process the input line

        int number;
        while (ss >> number) {
            arr.push_back(number);  // Push each integer into the vector
        }

        int n = arr.size();
        if (n != 0) {
            // Create the head and tail of the linked list
            head = new Node(arr[0]);
            tail = head;

            // Build the rest of the linked list
            for (int i = 1; i < n; ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        // Reverse the linked list
        head = ob.reverseList(head);

        // Print the reversed linked list
        printList(head);

        // Free memory
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}
