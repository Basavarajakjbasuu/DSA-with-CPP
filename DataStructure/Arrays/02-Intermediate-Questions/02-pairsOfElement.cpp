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

int main() {

  int arr[3] = { 10, 20, 30 };

 parisOfElement(arr, 3);

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
*/