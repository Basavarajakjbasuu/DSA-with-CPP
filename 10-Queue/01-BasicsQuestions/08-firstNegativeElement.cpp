#include<iostream>
#include<stack>
#include<deque>
#include<queue>
using namespace std;

void printFirstNegativeElement(int *arr, int n, int k) {
  deque<int> dq;

  //Process first k elements - first window
  for(int index = 0; index<k; index++) {
    int element = arr[index];

    if(element < 0) {
      dq.push_back(index);
    }
  }

  //Process remaining windows - Remove and addition
  for(int index = k; index <  n; index++) {

    if(dq.empty()) {
      cout << "0 ";
    }else {
      cout << arr[dq.front()] << " ";
    }

    //Remove - when index is out of range of queue
    if(index - dq.front() >= k) {
      dq.pop_front();
    }

    //Addition
    if(arr[index] < 0) {
      dq.push_back(index);
    }
  }

  //Last window
  if(dq.empty()) {
      cout << "0 ";
    }else {
      cout << arr[dq.front()] << " ";
    }
    
  cout << endl;
}


int main() {
 
 int arr[] = { -8, 2, 3, -6, 10 }; 
  int n = 5;
  int k = 2;
 printFirstNegativeElement(arr, n, k);

  return 0;
}

/*
  Printing Queue: 10 40 20 50 30 60
*/
