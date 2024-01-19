#include<iostream>
using namespace std;

void twoSumOfArray(int arr[], int n) {

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int twoSum = arr[i] + arr[j];
      cout << arr[i] << " + " << arr[j] << " = " << twoSum << endl;
    }
    
  }
  
}

int main() {
  int arr[3] = { 10, 20, 30 };

  twoSumOfArray(arr, 3);
  return 0;
}

/*
  10 + 10 = 20
  10 + 20 = 30
  10 + 30 = 40
  20 + 10 = 30
  20 + 20 = 40
  20 + 30 = 50
  30 + 10 = 40
  30 + 20 = 50
  30 + 30 = 60
*/