#include<iostream>
using namespace std;
 
class Node {
  public:
    int data;
    Node *next;

    Node() {
      this->next = NULL;
    }

    Node(int data) {
      // cout << "parameterized constructor call" << endl;
      this->data = data;
      this->next = NULL;
    }
};

void printLL(Node *head) {
  //TO TRAVERSE USE TEMP POINTER => good practice

  Node *temp = head;
  int length = 0;

  while (temp != NULL) 
  {
    length++;
    cout << temp->data << "=>";
    temp = temp->next;
  }

  cout << "Number of nodes: " << length << endl;
}



int main() {
  
  // Creation of node
    // Node a;
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node *head = first;

    printLL(first);


    return 0;
}