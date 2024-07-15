#include<iostream>
using namespace std;

//VISITED METHOD
void findMissing(int a[], int N) {
  for(int i=0; i<N; i++) {
    int index = abs(a[i]);
    if(a[index - 1] > 0) {
      a[index-1] *= -1;
    }
  }

  for(int i=0; i<N; i++) {
    cout << a[i] << " ";
  }

  cout << endl;
  for(int  i =0; i<N; i++) {
    if(a[i] > 0) {
      cout << "Missing element: " <<i+1;
    }
  }
  
}

int main() {
  int a[5] = {1,3,5,3,4};

  findMissing(a, 5);

  return 0;
}