#include<iostream>
using namespace std;
 
int main() {
  
  // Array creation
  int arr[10];
  char ch[13];
  bool flag[4];

  // Access address of Array
  cout << "Base Address of arr: " << &arr << endl; //Address of arr: 0x34f5ffd30
  cout << arr << endl; //0x34f5ffd30

  //sizOf
  cout << "Size of arr: " << sizeof(arr) << endl; //Size of arr: 40 => 10 * 4 int size is 4
  cout << "Size of ch: " << sizeof(ch) << endl; //Size of arr: 13 => 13 * 1 char size is 1
  cout << "Size of flag: " << sizeof(flag) << endl; //Size of arr: 4 => 4 * 1 bool size is 1


  /**
   * Array initialization
  */
  int arr1[5] = {1, 2, 3, 4, 5};

  int brr[6] = {3, 4};

  // int crr[2] = {34, 234, 44, 56}; //too many initializers for 'int [2]'
  /*
      int n;
      cin >> n;
      int arr2[n]; //? BAD PRACTICE
  */

  /**
   * Indexing in Array
  */

  // 0 based Index

  // 0 to n-1 to from first to last block index

  /**
   * Accessing array values
  */

  cout << arr1[0] << endl; //1
  cout << arr1[2] << endl; //3
  cout << arr1[3] << endl; //4
  cout << arr1[5] << endl; //32758 => junk values

  int n = 5;
  for (int i = 0; i < n; i++) {
    cout << arr1[i] << " "; //1 2 3 4 5
  }
    return 0;
}