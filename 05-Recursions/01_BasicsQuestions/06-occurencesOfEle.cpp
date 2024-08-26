#include<iostream>
#include<vector>
using namespace std;

vector<int> findOccurrences(int arr[], int size, int index, int target) {

  vector<int> ans;
  vector<int> nextAns;

  //BASE CASE
  if(index >= size) {
    return ans;
  }

  if(arr[index] == target) {
    ans.push_back(index);
  }

  nextAns = findOccurrences(arr, size, index + 1, target);

  ans.insert(ans.end(), nextAns.begin(), nextAns.end());

  return ans;
}



int main() {
   
  int arr[6] = {2, 4, 2, 8, 2, 2};
  int size = 6;
  int index = 0;
  int target = 2;

  vector<int> occurrences = findOccurrences(arr, size, index, target);

  cout << "Occurrences of " << target << " are at indices: ";
  for (int index : occurrences) {
    cout << index << " ";
  }
  //Occurrences of 2 are at indices: 0 2 4 5


  return 0;
}