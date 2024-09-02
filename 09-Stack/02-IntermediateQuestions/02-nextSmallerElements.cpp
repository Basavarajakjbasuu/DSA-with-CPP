#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 
vector<int> nextSmallerElement(int *arr, int size, vector<int> &ans) {
  stack<int> st;
  st.push(-1);

  for (int i = size - 1; i >= 0; i--)
  {
    int curElm = arr[i];
    //Find the smallest number
    while(st.top() >= curElm) {
      st.pop();
    }

    ans[i] = st.top(); 

    st.push(curElm);
  }
  
  return ans;
}


int main() {
  
  int arr[5] = {8,4,6,2,3};
  int size = 5;
  vector<int> ans(size);

  ans = nextSmallerElement(arr, size, ans); 

  for(auto i: ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}

/*
  int arr[5] = {8,4,6,2,3};
  4 2 2 -1 -1
*/
