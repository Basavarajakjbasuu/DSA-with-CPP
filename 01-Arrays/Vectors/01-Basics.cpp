#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> v) {
  int size = v.size();

  cout << "Vector Elements are: ";
  for (int i = 0; i < size; i++) {
    cout << v[i] << " ";
  }
}

int main() {
  
  // Initialise
  vector<int> v;

  // insert
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  printVector(v); //Vector Elements are: 1 2 3

  // delete
  v.pop_back();
  printVector(v); //Vector Elements are: 1 2

  v.pop_back();
  printVector(v); //Vector Elements are: 1

  v.pop_back();
  printVector(v); //Vector Elements are: 


    // insert
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  // clear
  v.clear();
  printVector(v); //Vector Elements are:

  // Initialize with specific element
  vector<int> v1(5, -1);
  printVector(v1); //Vector Elements are: -1 -1 -1 -1 -1
  return 0;
}