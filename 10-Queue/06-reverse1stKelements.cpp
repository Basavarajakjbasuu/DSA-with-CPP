#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseFirstKElement(queue<int> &qu, int k) {
  stack<int> st;
  int n = qu.size();

  if(k >n || k==0) {
    return;
  }
  for(int i=0; i<k; i++) {
    int temp = qu.front();
    qu.pop();
    st.push(temp);
  }

  while(!st.empty()) {
    int temp = st.top();
    st.pop();
    qu.push(temp);
  }

  for(int i=0; i < (n-k); i++) {
    int temp = qu.front();
    qu.pop();
    qu.push(temp); 
  }
}

int main() {
 
 queue<int> q;

 q.push(10);
 q.push(20);
 q.push(30);
 q.push(40);
 q.push(50);
 q.push(60);

reverseFirstKElement(q, 4);
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
  Printing Queue: 40 30 20 10 50 60
*/
