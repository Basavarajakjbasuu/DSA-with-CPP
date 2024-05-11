#include<iostream>
using namespace std;

int setBitCount(int num) {
  int count = 0;
  // while(num > 0) {
  //   int bit = num % 2;
  //   if(bit == 1) {
  //     count++;
  //   } 
  //   num = num/2;
  // }

  // With bitwise operator

  while (num) {
    int bit = (num&1);
    if(bit == 1) {
      count++;
    }
    num = num >> 1;

  }

  return count;
} 

int main() {
  int num=0;

  cout << "Enter the num: ";
  cin >> num;
  int count = setBitCount(num);
  cout << "Set Bit count for " << num << " is: " << count << endl;
  return 0;
}

/*
  Enter the num: 15
  Set Bit count for 15 is: 4

  Enter the num: 7
  Set Bit count for 7 is: 3
*/