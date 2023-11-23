#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void interLeaveQueue(queue<int> &qu) {
  queue<int> secondHalf;

  //Push first half of queue in second half make two halves
  int size = qu.size();
  for (int i = 0; i < size/2; i++)
  {
    int temp = qu.front();
    qu.pop();

    secondHalf.push(temp);
  }

  //Merge both halves into original queue
  for(int i=0; i<size/2; i++) {
    int temp = secondHalf.front();
    secondHalf.pop();

    qu.push(temp);
    temp = qu.front();
    qu.pop();
    qu.push(temp);
  }

}

//Printing Queue 
void printQueue(queue<int> q) {
 cout << "Printing Queue: ";
  while(!q.empty()) {
    int element = q.front();
    q.pop();
    cout << element << " ";
  }
  cout <<  endl;
}

int main() {
 
 queue<int> q;

 q.push(10);
 q.push(20);
 q.push(30);
 q.push(40);
 q.push(50);
 q.push(60);

 printQueue(q);
 interLeaveQueue(q);
 printQueue(q);
 

  return 0;
}

/*
  Printing Queue: 10 20 30 40 50 60
  Printing Queue: 10 40 20 50 30 60
*/
