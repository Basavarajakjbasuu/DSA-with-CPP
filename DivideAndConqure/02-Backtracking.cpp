#include<iostream>
using namespace std;

void printPermutation(string &str, int index) {
  // Base case
  if(index >= str.length()) {
    cout << str << " ";
    return;
  }

  for (int j = index; j < str.length(); j++)
  {
    swap(str[index], str[j]);

    // Recursion call
    printPermutation(str, index + 1);

    // backtracking
    swap(str[index], str[j]);
  }
  
}

int main() {

  string str = "abc";
  int index = 0;

  printPermutation(str, index);

  return 0;
}

/*
  Without reference consume more memory Output
    abc acb bac bca cab cba
  
  With reference output
    abc acb cab cba abc acb 

  After backtracking code output
    abc acb bac bca cba cab 
*/