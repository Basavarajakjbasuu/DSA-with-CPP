#include<iostream>
using namespace std;
 
class CQueue {
  public:
    int *arr;
    int size;
    int front;
    int rear;

    CQueue(int size) {
      arr = new int[size];
      this->size = size;
      front = -1;
      rear = -1;
    }

    void push(int val) {
      //Overflow
      //Empty case -> first element
      //Circular nature
      //normal flow

      if((front == 0 && rear == size - 1) || (rear == front - 1)) {
        cout << "Oops! Overflow." << endl;
      }else if(front == -1 && rear == -1) {
        front++;
        rear++;
        arr[rear] = val;
      }else if(rear == size-1 && front != 0) {
        rear = 0;
        arr[rear] = val;
      }else {
        rear++;
        arr[rear] = val;
      }
    }

    void pop() {
      //Underflow
      //Empty case -> first element
      //Circular nature
      //normal flow

      if(front == -1 && rear == -1) {
        cout << "Oops! underflow." << endl;
      }else if(front == rear) {
        arr[front] = -1;
        front = -1;
        rear = -1;
      }else if(front == size - 1) {
        arr[front] = -1;
        front = 0;
      }else {
        arr[front] = -1;
        front++;
      }
    }

    void print() {
        cout <<"Printing Queue: ";
        for (int i = 0; i < size; i++)
        {
          cout << arr[i] << " ";
        }
        cout << endl;
    }

}; 
int main() {
  CQueue cq(5);

  cq.push(20);
  cq.push(40);
  cq.push(60);
  cq.push(80);
  cq.push(100);
  // cq.push(200); Oops! Overflow.
  cq.print(); //Printing Queue: 20 40 60 80 100

  cq.pop();
  cq.pop();
  cq.pop();
  cq.print(); //Printing Queue: -1 -1 -1 80 100

  cq.push(445);
  cq.push(345);
  cq.push(225);
  // cq.push(125); //Oops! Overflow.
  cq.print(); //Printing Queue: 445 345 225 80 100
  return 0;
}
