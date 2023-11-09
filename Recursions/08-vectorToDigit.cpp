#include<iostream>
#include<vector>
using namespace std;

int vectorToDigit(vector<int> inpVector, int index) {

  //Base case
  if(inpVector.size() == index+1) {
    return inpVector[index];
  }

 int currentDigit = inpVector[index];

 int nextDigit = vectorToDigit(inpVector, index + 1);
  return currentDigit + nextDigit * 10;
}

int main() {

  vector<int> inp = {2, 5, 7, 8};
  int index = 0;
  cout << vectorToDigit(inp, index);

  return 0;
}