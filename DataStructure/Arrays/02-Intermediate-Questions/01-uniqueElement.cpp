#include<iostream>
using namespace std;

/**
 * Find Unique element in and Array 
 */ 

int uniqueElement(int arr[], int n) {

  int ans = 0;
  for (int i = 0; i < n; i++) {

    ans = ans ^ arr[i];
  }

  return ans;
}

int main() {

  int arr[8] = {2, 4, 5, 9, 4, 2, 5};

  cout << "unique element is: " << uniqueElement(arr, 8) << endl;
  return 0;
}