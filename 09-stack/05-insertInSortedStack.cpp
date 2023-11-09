#include<iostream>
#include<stack>
using namespace std;
 
void insertInSortedStack(stack<int> &stk, int element) {
  //Base case
  //Check its stack empty or not
  if(stk.empty() || element > stk.top()) {
    stk.push(element);
    return;
  }

  int temp = stk.top();
  stk.pop();

  insertInSortedStack(stk, element);

  //Backtracking
  stk.push(temp);
}

int main() {
  
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);

  insertInSortedStack(st, 35); //40 35 30 20 10
  insertInSortedStack(st, 5); //40 35 30 20 10 5
  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}