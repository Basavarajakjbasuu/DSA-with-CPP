#include<iostream>
using namespace std;
 
int main() {
  
  //Array creation
  int arr[101];
  char ch[102];
  bool flags[104];
  long points[123];
  short num[100];

  int a = 5;
  cout << "Address of a: " << &a << endl; // Address of a: 0x41d7bff5ac
  cout << "Size of a: " << sizeof(a) << endl; //Size of a: 4
  cout << "Base address of arr is: " << &arr << endl; // Base address of arr is: 0x41d7bff950
  cout << "Base address of arr is: " << arr << endl; // Base address of arr is: 0x41d7bff950

  cout << "Size of arr is: " <<  sizeof(arr) << endl; // Size of arr is: 404 => 101*4

  //Display array
  int brr[6] = {5, 10, 15, 20, 25, 25};
  int n=6;
  for(int i=0; i<n; i++) {
    cout << brr[i] << " "; // 5 10 15 20 25 25 
  }
  cout << endl;


  //Taking input
  int crr[6];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  
  return 0;
}