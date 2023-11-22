#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 
vector<int> prevSmallerElement(int *arr, int size, vector<int> &ans) {
  stack<int> st;
  st.push(-1);

  for (int i = 0; i < size; i++)
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

  ans = prevSmallerElement(arr, size, ans); 

  for(auto i: ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}

/*
  int arr[5] = {8,4,6,2,3};
  -1 -1 4 -1 2 
*/
