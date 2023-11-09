#include<iostream>
#include<stack>
using namespace std;
 
void insertAtBottom(stack<int> &stk, int ele) {
  //BASE CASE
  if(stk.empty()) {
    stk.push(ele);
    return;
  }

  //1 case
  int temp = stk.top();
  stk.pop();

  //Recursive call
  insertAtBottom(stk, ele);

  //Backtrack
  stk.push(temp);
}

void reverseStack(stack<int> &stk) {
  //Base case
  if(stk.empty()) {
    return;
  }

  int temp = stk.top();
  stk.pop();

  reverseStack(stk);

  //Backtracking
  insertAtBottom(stk, temp);
}

int main() {
 

  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);

  reverseStack(st);

  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }  

  return 0;
}

/*
  Without reverse
  40 30 20 10

  With reverse
  10 20 30 40

*/