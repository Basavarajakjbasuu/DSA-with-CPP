#include<iostream>
#include<queue>
using namespace std;
 
int main() {
  
  //Creations
  queue<int> qu;

  //insertion
  qu.push(5);
  qu.push(10);
  qu.push(20);

  // size
  cout << "Size of Queue: " << qu.size() << endl;

  //Empty
  if(qu.empty() == true) {
    cout << "Queue is empty" << endl;
  }else {
    cout << "Queue is not empty" << endl;
  }

  cout << "Front element  of Queue: " << qu.front() << endl;
  cout << "Last element of Queue: " << qu.back() << endl;
  qu.pop();
  cout << "Front element  of Queue: " << qu.front() << endl;
  cout << "Last element of Queue: " << qu.back() << endl;
  return 0;
}


/*
  Size of Queue: 3
  Queue is not empty
  Front element  of Queue: 5
  Last element of Queue: 20
  Front element  of Queue: 10
  Last element of Queue: 20
*/
