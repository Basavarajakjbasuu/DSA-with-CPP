#include<iostream>
using namespace std;

class Node {

  public:
    int data;
    Node *next;
    Node *previous;

    Node() {
      this->next = NULL;
      this->previous = NULL;
    }

    Node(int data) {
      this->data = data;
      this->next = NULL;
      this->previous = NULL;
    }
};

void printLL(Node* head) {
  Node *temp = head;

  while (temp != NULL) 
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int findLengthLL(Node *head) {
  Node *temp = head;

  int length = 0;
  while(temp != NULL) {
    length++;
    temp = temp->next;
  }

  return length;
}

void insertAtHead(Node *head, Node *tail, int data) {
  
}

int main() {

  Node *head = new Node(10);

  return 0;
}