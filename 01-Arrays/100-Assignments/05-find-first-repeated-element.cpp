#include<iostream>
#include<unordered_map>
using namespace std;

int firstRepeated(int a[], int n) {

  for(int i=0; i<n; i++) {
    bool isRepeated = false;

    for(int j=i+1; i<n; i++) {

      if(a[i] == a[j]) {
        isRepeated = true;
        return a[i];
      }
    }
  }

  return -1;
}

int firstRepeatedOptimal(int arr[], int n) {
   unordered_map<int, int> hash;
        for(int i=0; i<n; i++) {
            hash[arr[i]]++;
        }
        
        for(int i=0; i<n; i++) {
            if(hash[arr[i]] > 1) {
                return arr[i];
            }
        }
    return -1;    
}

int main() {
 
  int a[] = {1,5,3,4,3,5,6};

  cout << "First repeated element: " << firstRepeated(a, 7) << endl;
  cout << "First repeated element: " << firstRepeatedOptimal(a, 7) << endl;
  return 0;
}

// First repeated element: 5
// First repeated element: 5