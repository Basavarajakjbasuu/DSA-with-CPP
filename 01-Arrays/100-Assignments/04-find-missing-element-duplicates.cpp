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

// SORTING and SWAPPING method
void findMissing2(int a[], int N) {

  int i=0;
  while (i<N) {
    int index = a[i] - 1;
    if(a[i] != a[index]) {
      swap(a[i], a[index]);
    } else {
      i++;
    }
  }

  // for(int i=0; i<N; i++) {
  //   cout << a[i] << " ";
  // }

  for(int i=0; i<N; i++) {

    if(a[i] != i+1) {
      cout << "Missing element: " << i+1 << " ";
    }
  }
}

int main() {
  int a[5] = {1,3,3,3,4};
  int a1[5] = {1,3,3,3,5};

  findMissing(a, 5);
  cout << endl;
  findMissing2(a1, 5);

  return 0;
}

/*
  -1 3 -3 -3 4 
  Missing element: 2Missing element: 5
  Missing element: 2 Missing element: 4 
*/