#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node()
  {
    this->next = NULL;
  }

  Node(int data)
  {
    // cout << "parameterized constructor call" << endl;
    this->data = data;
    this->next = NULL;
  }
};

void printLL(Node *head)
{
  // TO TRAVERSE USE TEMP POINTER => good practice

  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << "=>";
    temp = temp->next;
  }

  cout << endl;
}

//=> Should be PASS BY REFERENCE
void insertAtHead(Node *&head, Node *&tail, int data)
{
  if (head == NULL)
  {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  }
  else
  {
    // Non-empty case
    Node *newNode = new Node(data);
    // attach new node to head node
    newNode->next = head;
    // update head
    head = newNode;
  }
}

void insertAtTail(Node* &head, Node* &tail, int data){
  if(head == NULL) {
    
    //Empty LL
    //create a new node
    Node *newNode = new Node(data);
    //both head anf tail same position
    head = newNode;
    tail = newNode;
  }else {
    //Non-Empty LL
    //create a new node
    Node *newNode = new Node(data);
    //attach the new node to tail node
    tail->next = newNode;
    //update tail
    tail = newNode;
  }
}

int getLengthLL(Node* node) {

  Node *temp = node;
  int length = 0;
  while(temp != NULL) {
    length++;
    temp = temp->next;
  }

  return length;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position) {

  int length = getLengthLL(head);
  if(position < 0) {
    cout << "Oops! Please enter valid position" << endl;
  }

  if(position > length + 1) {
    cout << "Oops! Please enter valid position" << endl;
  } 

  if(position == 0) {
    insertAtHead(head, tail, data);
  } else if(position == length+ 1) {
    insertAtTail(head, tail, data);
  } else {
    // Insert at middle

    //s1: Create a new node
    Node *newNode = new Node(data);
    //s2: Traverse to find current and previous node
    Node *previousNode = NULL;
    Node *currentNode = head;
    while(position != 1) {
      previousNode = currentNode;
      currentNode = currentNode->next;
      position--;
    }
    //s3: prev->next = temp
    previousNode->next = newNode;
    //s4: temp->next = current
    newNode->next = currentNode;
  }


}

int main()
{

  Node *head = NULL;
  Node *tail = NULL;

  insertAtHead(head, tail, 50);
  insertAtHead(head, tail, 40);
  insertAtHead(head, tail, 30);
  insertAtHead(head, tail, 20);

  printLL(head);
  insertAtTail(head, tail, 100);
  printLL(head);

  /*
    20=>30=>40=>50=>
    20=>30=>40=>50=>100=>
  */

  insertAtPosition(head, tail, 45, 3);
  printLL(head);
    //  20=>30=>40=>50=>
    // 20=>30=>40=>50=>100=>
    // 20=>30=>45=>40=>50=>100=>

  insertAtPosition(head, tail, -40, 0);
  printLL(head);

  /*
    20=>30=>40=>50=>
    20=>30=>40=>50=>100=>
    20=>30=>45=>40=>50=>100=>
    -40=>20=>30=>45=>40=>50=>100=> 
  */

   insertAtPosition(head, tail, -40, 8);
  printLL(head);

  /*
    20=>30=>40=>50=>
    20=>30=>40=>50=>100=>
    20=>30=>45=>40=>50=>100=>
    -40=>20=>30=>45=>40=>50=>100=>
    -40=>20=>30=>45=>40=>50=>100=>-40=>
  */

  insertAtPosition(head, tail, 1111, 54); //Oops! Please enter valid position

  insertAtPosition(head, tail, 40, -8); //Oops! Please enter valid position
  return 0;
}