#include<iostream>
#include<limits.h>
using namespace std;

void minimumOfArray(int arr[], int size, int index, int &mini) {
  
  // Base case
  if(index >= size) {
    return;
  }

  // Processing
   mini = min(mini, arr[index]);

  // Recursive call
  minimumOfArray(arr, size, index + 1, mini);
} 

int main() {
  int arr[] = {10, 20, -30, 40};
  int size = 4;
  int index = 0;
  int mini = INT_MAX;

  minimumOfArray(arr, size, index, mini);
  cout << "Minimum number in array is: " << mini << endl;
  return 0;
}

/*
  OUTPUT
  Minimum number in array is: -30
*/