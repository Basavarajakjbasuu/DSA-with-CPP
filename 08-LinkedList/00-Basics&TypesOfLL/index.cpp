#include<iostream>
using namespace std;

class Node {
  public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

void printLL(Node* head) {
  Node *temp = head;
  while(temp != NULL) {
    cout << temp->data << "=>";
    temp = temp->next;
  }
  cout << endl;
}

void insertAtHead(Node* &head, Node* &tail, int data) {
  //Empty
  if (head == NULL) {
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
  } else {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }
}

void inserAtTail(Node* &head, Node* &tail, int data) {
  if (head == NULL) {
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
  } else {
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
  }
}
int getLength(Node* head) {
  Node* temp =head;
  int length = 0;

  while (temp != NULL) {
    length++;
    temp = temp->next;
  }

  return length;
}

void inserAtPosition(Node* &head, Node* &tail, int data, int position) {
  int length = getLength(head);

  if(position < 0 || position > length+1) {
    cout <<"Oops!, Cannot insert." <<  endl;
    return;
  }

  if(position == 0) {
    insertAtHead(head, tail, data);
    return;
  } else  if (position == length+1) {
    inserAtTail(head, tail, data);
    return;
  } else {
    Node* newNode = new Node(data);
    Node* currentNode = head;
    Node* previousNode = NULL;

    while (position != 1) {
      previousNode = currentNode;
      currentNode = currentNode->next;
      position--;
    }

    previousNode->next = newNode;
    newNode->next = currentNode;
  }
}
int main() {
 
  Node* head = NULL;
  Node* tail = NULL;
  insertAtHead(head, tail, 20);
  insertAtHead(head, tail, 40);
  insertAtHead(head, tail, 50);
  insertAtHead(head, tail, 60);
  insertAtHead(head, tail, 70);
  printLL(head);
  inserAtTail(head, tail, 60);

  printLL(head);
  inserAtPosition(head, tail, -30, 0);
  printLL(head);
  return 0;
}