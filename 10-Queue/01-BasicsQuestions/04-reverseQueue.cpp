#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &qu) {
  stack<int> st;

  // Push elements of the queue onto the stack
  while(!qu.empty()) {
    int frontElement = qu.front();
    qu.pop();

    st.push(frontElement);
  }

  // Pop elements from the stack and push them back into the queue
  while(!st.empty()) {
    int element = st.top();
    st.pop();

    qu.push(element);
  }
} 

void reverseQueueByRec(queue<int> &q) {
  //Base case
  if(q.empty()) {
    return;
  }

  int element = q.front();
  q.pop();

  reverseQueueByRec(q);

  q.push(element);
}

int main() {
 
 queue<int> q;

 q.push(10);
 q.push(20);
 q.push(30);
 q.push(40);
 q.push(50);
 q.push(60);

//  reverseQueue(q);
 reverseQueueByRec(q);
 //Printing Queue 
 cout << "Printing Queue: ";
  while(!q.empty()) {
    int element = q.front();
    q.pop();
    cout << element << " ";
  }
  cout <<  endl;

  return 0;
}

/*
  Printing Queue: 60 50 40 30 20 10
*/
