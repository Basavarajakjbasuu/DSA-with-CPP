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
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << endl;
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

// ==> Don't forgot about CBR
void insertAtHead(Node* &head, Node* &tail, int data) {
  //LL is Empty
  if(head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    }else {
  //LL is not Empty

    Node *newNode = new Node(data);
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
  }
}


void insertAtTail(Node *&head, Node *&tail, int data) {
  if(head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  }else {
    Node *newNode = new Node(data);
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
  }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position) {
  if(head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  }else {
    int length = findLengthLL(head);
    if(position == 1) {
      insertAtHead(head, tail, data);
    }
    else if(position == length + 1) {
      insertAtTail(head, tail, data);
    }else {
      //insert at poss
      //s1: create a new node
      Node *newNode = new Node(data);
      //s2: Traversing to find previous node and current node
      Node *previousNode = NULL;
      Node *currentNode = head;
      while( position !=1 ) {
        position--;
        previousNode = currentNode;
        currentNode = currentNode->next;
      }

      //S3: new node previous to previous node
      newNode->previous = previousNode;
      //s4: previous node next to new node
      previousNode->next = newNode;
      //s5: new node next to current node
      newNode->next = currentNode;
      //s6: current node previous to new node
      currentNode->previous = newNode;
    }
  }
}

int main() {

  Node *head = NULL;
  Node *tail = NULL;

  insertAtHead(head, tail, 60);
  insertAtHead(head, tail, 40);
  insertAtHead(head, tail, 20);
  insertAtHead(head, tail, 5);
  printLL(head); //5->20->40->60->

  insertAtTail(head, tail, 70);
  printLL(head); //5->20->40->60->70->

  insertAtPosition(head, tail, 1, 1);
  printLL(head); // 1->5->20->40->60->70->
  
  insertAtPosition(head, tail, 90, 7);
  printLL(head); // 1->5->20->40->60->70->90->
  
  insertAtPosition(head, tail, 0, 3);
  printLL(head); // 1->5->0->20->40->60->70->90->

  return 0;
}