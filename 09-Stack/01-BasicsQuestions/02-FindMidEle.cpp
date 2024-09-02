#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int &pos, int &ans) {
  //Base case
  if(pos == 1) {
    ans = st.top();
    return;
  }

  //First case
  pos--;
  int temp = st.top();
  st.pop();

  //Recursion
  solve(st, pos, ans);

  //Backtracking
  st.push(temp);
}


int getMiddleElement(stack<int> &st) {
  int size = st.size();
  int ans = -1;
  if(st.empty()) {
    cout << "OOPS! Stack is Empty." << endl;
    return -1;
  } else {
    //Stack is not empty
    //ODD
    int pos = 0;
    if(size & 1) {
      pos = size / 2 + 1;
    } else {
      pos = size / 2;
    }

     solve(st, pos, ans);
  }

  return ans;
}


int main() {

  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);
  st.push(60);
  st.push(70);
  st.push(80);


  int midEle = getMiddleElement(st);
  cout << "Middle element: " << midEle << endl;
  return 0;
}

/*
  ODD case
  Middle element: 40

  EVEN case
  Middle element: 50

  ONLY two element
  Middle element: 20

  When no element found
  OOPS! Stack is Empty.
*/