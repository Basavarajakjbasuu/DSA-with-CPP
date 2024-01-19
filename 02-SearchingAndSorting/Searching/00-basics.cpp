#include<iostream>
#include<vector>
using namespace std;

bool linearSearch(vector<int> arr, int searchKey) {

  bool success = false;

  for (int i = 0; i < arr.size(); i++)
  {
    if(searchKey == arr[i]) {
      cout << "Value found at index " << i << endl;

      success = true;
    }
  }
    return success;
  
} 

bool binarySearch(vector<int> arr, int key) {
    int startIndex = 0;
    int endIndex = arr.size() - 1;


    while(startIndex <= endIndex) {
      // Mid index of an array
      int midIndex = startIndex + (startIndex - endIndex) / 2;

      if(key == arr[midIndex]) {
        cout << "Value " << arr[midIndex] << " found at index " << midIndex << endl;

        return true;
      } else if(key > arr[midIndex] ) {
        startIndex = midIndex + 1;
      } else if(key < arr[midIndex]){
        endIndex = midIndex - 1;
      }

    }

    cout << "Value " << key << " not found in the array." << endl;
    return false;
}

int main() {

  vector<int> inputArr = {2, 4, 5, 0, 24, 45, 67};

  int key = 45;
  linearSearch(inputArr, key);

  binarySearch(inputArr, key);
  return 0;
}

/*
  OUTPUT
  Value found at index 5
  Value 45 found at index 5
*/