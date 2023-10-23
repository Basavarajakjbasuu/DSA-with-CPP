#include<iostream>
#include<vector>
using namespace std;

void evenElementInArray(int arr[], int size, int index, vector <int> &evenElements ) {
  // Base case
  if(index >= size) {
    return;
  }

  // Processing
  if(arr[index] % 2 == 0) {
    evenElements.push_back(arr[index]);
  }
  // Recursive call
  return evenElementInArray(arr, size, index + 1, evenElements);
}

void printVector(vector <int> &vectorName) {
  for (int i = 0; i < vectorName.size(); i++)
  {
    cout << vectorName[i] << ' ';
  }

  cout << endl;
}

int main() {

  int arr[] = {10, 12, 14, 13, 15, 16, 20, 9, 17, 100};
  int size = 10;
  int index = 0;
  vector<int> evenElements;
  evenElementInArray(arr, size, index, evenElements);
  printVector(evenElements);
  return 0;
}

/*
  OUTPUT
  10 12 14 16 20 100 
*/