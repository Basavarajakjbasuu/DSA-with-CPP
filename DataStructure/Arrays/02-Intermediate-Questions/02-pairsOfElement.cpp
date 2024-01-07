#include<iostream>
using namespace std;


/*
  Itirate over the array and print its pairs
*/
void parisOfElement(int arr[], int n) {

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
    }
    
  }
  
}

void parisFromLastElement(int arr[], int n) {

  for(int i = n-1; i>=0; i--) {

    for(int j = n-1; j>=0; j--) {

      cout << "(" << arr[i] <<", " << arr[j] <<")" << endl;
    }
  }
}

void parisFromDiffElement(int arr[], int n, int eleIdx) {

  for(int i = eleIdx; i>=0; i--) {

    for(int j = eleIdx; j>=0; j--) {

      cout << "(" << arr[i] <<", " << arr[j] <<")" << endl;
    }
  }
}

int main() {

  int arr[3] = { 10, 20, 30 };

//  parisOfElement(arr, 3);
// parisFromLastElement(arr, 3);

parisFromDiffElement(arr, 3, 1);

  return 0;
}

/*
  (10, 10)
  (10, 20)
  (10, 30)
  (20, 10)
  (20, 20)
  (20, 30)
  (30, 10)
  (30, 20)
  (30, 30)


  if j=i

  (10, 10)
  (10, 20)
  (10, 30)
  (20, 20)
  (20, 30)
  (30, 30)

  parisFromLastElement(arr, 3);

  (30, 30)
  (30, 20)
  (30, 10)
  (20, 30)
  (20, 20)
  (20, 10)
  (10, 30)
  (10, 20)
  (10, 10)

*/