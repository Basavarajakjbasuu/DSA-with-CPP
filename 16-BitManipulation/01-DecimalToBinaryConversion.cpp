#include<iostream>
#include<cstring>
using namespace std;

string convertToBinary(int num) {
  string res = "";

  while(num != 0) {
    if(num%2 == 1) res += '1';
    else res +='0';
    num /=2;
  }

  //Reverse the result
  int left = 0, right = res.length() - 1;
  while (left < right) {
    swap(res[left], res[right]);
    left++;
    right--;
  }
  return res;
}

int main() {
  
  int deciNum = 0;

  cout << "Enter decimal Num: ";
  cin >>deciNum;

  cout << "Binary equivalent of " << deciNum << " is: " << convertToBinary(deciNum)<< endl;
  return 0;
}

/*
  -------------
  TC - log2 N
  SC - log2 N
  ------------
  Enter decimal Num: 13
  Binary equivalent of 13 is: 1101

  Enter decimal Num: 15
  Binary equivalent of 15 is: 1111

  Enter decimal Num: 1024
  Binary equivalent of 1024 is: 10000000000
*/