#include<iostream>
using namespace std;
 
class DeQueue {
  public:
    int *arr;
    int size;
    int front;
    int rear;

    DeQueue(int size) {
      arr = new int[size];
      this->size = size;
      front = -1;
      rear = -1;
    }

    void pushFront(int val) {
      //Overflow
      //Empty case -> first element
      //Circular nature
      //normal flow

       if((front == 0 && rear == size - 1) || (rear == front - 1)) {
        cout << "Oops! Overflow." << endl;
      }else if(front == -1 && rear == -1) {
        front++;
        rear++;
        arr[front] = val;
      }else if(rear != size-1 && front == 0) {
        front = size - 1;
        arr[front] = val;
      }else {
        front--;
        arr[front] = val;
      }

    }

    void pushBack(int val) {
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

    void popFront() {
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

    void popBack() {
      //Underflow
      if(front == -1 && rear == -1) {
        cout << "Oops! underflow." << endl;
      }else if(front ==rear) {
        //Single element
        arr[rear] = -1;
        front= -1;
        rear = -1;
      }else if(rear == 0) {
        //Circular nature
        arr[rear] = - 1;
        rear = size - 1;
      }else {
        //Normal
        arr[rear] = -1;
        rear--;
      }
    }
};

int main() {
  
  return 0;
} 
