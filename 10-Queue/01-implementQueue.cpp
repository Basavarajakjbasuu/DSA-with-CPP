#include<iostream>
using namespace std;

class Queue{
  public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size) {
      arr= new int[size];
      this->size = size;
      front = -1;
      rear = -1;
    }

    //O(1)
    void push(int val) {
      //Check full
      if(rear == size -1) {
        cout << "Oops! Overflow." << endl;
        return;
      }else if (front == -1 && rear == -1) {
        //Empty case
        front++;
        rear++;
        arr[rear] = val;
      }else {
        //Normal case
        rear++;
        arr[rear] = val;
      }
    }

    //O(1)
    void pop() {
      //Under flow
      if(front == -1 && rear == -1){
        cout << "Oops! Underflow" << endl;
      }else if(front == rear) {
        //Single element
        arr[front] = -1;
        front = -1;
        rear = -1;
      }else {
        //Normal case
        arr[front] = -1;
        front++;
       }
    }

    //O(1)
    bool isEmpty() {
      if(front == -1 && rear == -1) {
        return true;
      }else {
        return false;
      }
    }

  //O(1)
  int getSize() {
    if(front == -1 && rear == -1) {
      return 0;
    }else {
    return rear-front+1;
    }
  }

  //O(1)
  int getFront() {
    if(front == -1) {
      cout << "No element to get" << endl;
      return -1;
    }else {
      return arr[front];
    }
  }

  //O(1)
  int getRear() {
    if(rear == -1) {
      cout << "No element to get" << endl;
      return -1;
    }else {
      return arr[rear];
    }
  }

  //O(n)
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
 
  //Creations
  Queue q(4);

  q.push(5);
  q.push(10);
  q.push(15);
  q.push(20);
  q.print();

  cout << "Size of queue: " << q.getSize() << endl;
  q.pop();
  q.print();
  cout << "Size of queue: " << q.getSize() << endl;

  cout << "Queue is empty or not " << q.isEmpty() << endl;

  q.push(100);
  q.print();

  cout << "Get front element: " << q.getFront()<< endl;
  cout << "Get rear element: " << q.getRear()<< endl;
  return 0;
}


/*
  Printing Queue: 5 10 15 20 
  Size of queue: 4
  Printing Queue: -1 10 15 20 
  Size of queue: 3
  Queue is empty or not 0
  Oops! Overflow.
  Printing Queue: -1 10 15 20 
  Get front element: 10
  Get rear element: 20
*/
