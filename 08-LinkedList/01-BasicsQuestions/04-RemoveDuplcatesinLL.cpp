#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

// Function to create a new node
Node* newNode(int data) {
    return new Node(data);
}

// Function to display the doubly linked list from head to tail
void displayList(Node* head) {
    while (head->next) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
}

// Function to verify if the doubly linked list is correctly connected
bool verify(Node* head) {
    int forwardLength = 0;
    int backwardLength = 0;
    
    Node* temp = head;
    // Traverse from head to tail
    while (temp->next) {
        temp = temp->next;
        forwardLength++;
    }
    
    // Traverse from tail to head
    while (temp->prev) {
        temp = temp->prev;
        backwardLength++;
    }
    
    return forwardLength == backwardLength;
}

class Solution {
public:
    // Function to remove duplicates from a sorted doubly linked list
    Node* removeDuplicates(Node* head) {
        if (head == NULL) return head;

        Node* current = head;
        
        while (current && current->next) {
            // Check if the current node's data is equal to the next node's data
            if (current->data == current->next->data) {
                Node* duplicate = current->next;
                current->next = duplicate->next;
                
                // If the next node exists, update its prev pointer
                if (duplicate->next) {
                    duplicate->next->prev = current;
                }
                
                // Delete the duplicate node to free memory
                delete duplicate;
            } else {
                current = current->next;
            }
        }
        
        return head;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        Node* head = NULL;
        Node* tail = NULL;
        int x;
        cin >> x;
        head = newNode(x);
        tail = head;
        
        for (int i = 0; i < n - 1; i++) {
            cin >> x;
            Node* temp = newNode(x);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        
        Solution obj;
        head = obj.removeDuplicates(head);
        
        if (verify(head)) {
            displayList(head);
        } else {
            cout << "Your pointers are not correctly connected";
        }
        
        cout << endl;
    }
    
    return 0;
}

/*
  1
  6    
  1 1 1 2 3 4 -> inp
  1 2 3 4 -> outp
*/