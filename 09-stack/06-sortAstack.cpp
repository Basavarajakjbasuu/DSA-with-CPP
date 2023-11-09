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

void sortStack(stack<int> &stk) {
  //Base case
  if(stk.empty()) {
    return;
  }

  //Once case
  int temp = stk.top();
  stk.pop();

  sortStack(stk);

  insertInSortedStack(stk, temp);
}

int main() {
 
  stack<int> st;
  st.push(15);
  st.push(9);
  st.push(12);
  st.push(3);
  st.push(6);
  st.push(18);

  sortStack(st); //18 15 12 9 6 3
  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}