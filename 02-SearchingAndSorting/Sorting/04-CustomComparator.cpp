#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printArray(vector<int> &arr) {
  for(int i=0; i<arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout <<  endl;
}

void printVV(vector<vector <int>> &vt) {
  for(int i=0; i<vt.size(); i++) {
    vector<int> &temp = vt[i];
    int a = temp[0];
    int b = temp[1];
    cout << a << " " << b <<  endl;
  }
  cout <<  endl;
}

bool myComp(int &a, int &b) {
  // return a < b; // sort in increasing order
  return a > b; // sort in decreasing order
} 

bool myComp1(vector<int> a, vector<int> b) {
  // return a[0] < b[0]; // consider zeroth index
  return a[1] < b[1]; // consider first index
}

int main() {
 
  vector<int> nums = {1, 12, 45,11, 46, 78, -4, 0};
  sort(nums.begin(), nums.end());
  /*
    Sort in increasing order
      -4 0 1 11 12 45 46 78 
  */
  printArray(nums);

  vector<int> nums1 = {44, 22, 55, 11, 33, 66};
  sort(nums1.begin(), nums1.end(), myComp);
  printArray(nums1);
  /*
    if a < b increasing order 
   11 22 33 44 55 66
  */

  /*
    if a > b decreasing order
    66 55 44 33 22 11
  */
 //-----------------------------------------------------------

  // VECTOR OF VECTOR SORTING
  vector<vector <int>> vvtr;
  int n;
  cout << "Enter size \n";
  cin >> n;
  for(int i=0; i<n; i++) {
    int a,b;
    cout << "Enter a, b ";
    cin >> a >> b;
    vector<int> temp;
    temp.push_back(a);
    temp.push_back(b);
    vvtr.push_back(temp);
  }

  cout<<"VV values are " <<  endl;
  // sort(vvtr.begin(), vvtr.end());
  sort(vvtr.begin(), vvtr.end(), myComp1);
  printVV(vvtr);
  /*
    Enter size 
    5
    Enter a, b 2 33
    Enter a, b 0 66
    Enter a, b 1 33
    Enter a, b 4 66
    Enter a, b 0 22
    VV values are 
    0 22
    0 66
    1 33
    2 33
    4 66
    NOTE: Sorting based on zeroth index
  */

  /*
    Enter size 
    5
    Enter a, b 2 33
    Enter a, b 0 66
    Enter a, b 1 33
    Enter a, b 4 66
    Enter a, b 0 22
    VV values are 
    0 22
    2 33
    1 33
    0 66
    4 66
    NOTE: Sorting based on first index
  */
  return 0;
}