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

int main() {
 

  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);

  int insElement = 250;
  insertAtBottom(st, insElement);

  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  } //40 30 20 10 250

  return 0;
}