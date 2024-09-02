#include<iostream>
using namespace std;

class Stack {

  public:
    int *arr;
    int size;
    int top;

    Stack(int size) {
      arr = new int(size);
      this->size = size;
      this->top = -1;
    }

    //O(1)
    void push(int data) {

      if(size == top+1) {
        cout << "Overflow! Stack is full" << endl;
      }else {
        top++;
        arr[top] = data;
      }
      
    }

    //O(1)
    void pop() {
      if(top == -1) {
        cout << "Underflow! Stack is empty." << endl;

      }else {
        top--;
      }
    }    

    bool isEmpty() {
      if(top == -1) {
        return true;
      }else {
        return false;
      }
    }

    int getTop() {
      if(top == -1) {
        cout << "Underflow! Stack is empty." << endl;
        return -1;
      }else {
        return arr[top];
      }
    }

    int getSize() {
      return top + 1;
    }

    //O(n)
    void print() {
      if(top == -1) {
        cout << "Underflow! No element to print" << endl;
      } else {
        cout << "Top value: " << arr[top] << endl;
        cout << "Stack :";
        for (int i = 0; i < getSize(); i++)
        {
          cout << arr[i] << " ";
        }
        cout << endl<< endl; 
      }
    }
};


int main() {
 
 
  // stack<int> st;

  // st.push(10);
  // st.push(12);
  // st.push(14);

  // cout << st.size() << endl;
  // cout << st.top() << endl;

    Stack stk(6);

    stk.push(10);
    stk.print();

    stk.push(20);
    stk.print();

    stk.push(30);
    stk.print();

    /*
      Top value: 10
      Stack :10 

      Top value: 20
      Stack :10 20 

      Top value: 30
      Stack :10 20 30 
    */

    stk.pop();
    stk.print(); 
    /*
      Top value: 20
      Stack :10 20
    */

    stk.pop();
    stk.pop();
    stk.print(); 
    // Underflow! No element to print
    Stack stk1(2);

    stk1.print(); //Underflow! No element to print
    stk1.push(11);
    stk1.push(22);
    stk1.push(33); //Overflow! Stack is full

    cout << "Top element: " << stk1.getTop() << endl; //Top element: 22
    cout << "Size of Stack: " << stk1.getSize() << endl; //Size of Stack: 2

    return 0;
}