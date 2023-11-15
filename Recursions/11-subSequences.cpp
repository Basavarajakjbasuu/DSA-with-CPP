#include<iostream>
using namespace std;

void findSubsequences(int index, string output, string input ) {
  //Base Case
  if(index >= input.length()) {
    cout  << "->" << output << endl;
    return;
  }

  char ch = input[index];

  /* 
    //Exclude
    findSubsequences(index+1, output, input);

    //Include
    output.push_back(ch);
    findSubsequences(index+1, output, input);
  */

  //Include
  output.push_back(ch);
  findSubsequences(index+1, output, input);

  //Exclude
  output.pop_back();
  findSubsequences(index+1, output, input);
}

int main() {

  string input = "abc", output = "";
  int index = 0;

  findSubsequences(index, output, input);

  return 0;
}

/*
  ->abc
  ->ab
  ->ac
  ->a
  ->bc
  ->b
  ->c
  ->
*/