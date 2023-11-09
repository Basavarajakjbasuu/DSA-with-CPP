#include<iostream>
#include<vector>
using namespace std;

void printDigit(int num) {
  //Base case
  if(num == 0) {
    return;
  }

  //get last digit
  int digit = num % 10;
  //remove digit 
  num = num / 10;

  printDigit(num);

  cout << digit << " ";
}

void storeInVector(int num, vector<int> &digits) {
  //Base case
  if(num == 0) {
    return;
  }

  //get last digit
  int digit = num % 10;
  //remove digit 
  num = num / 10;

  printDigit(num);

  digits.push_back(digit);
}

void printVector(vector <int> &vectorName) {
  for (int i = 0; i < vectorName.size(); i++)
  {
    cout << vectorName[i] << ' ';
  }

  cout << endl;
}

int main() {

  int num = 4215;

  printDigit(num);

  cout << endl;
  cout << "Ans stored in vector: ";
  vector<int> result;
  storeInVector(num, result);
  printVector(result); //Ans stored in vector: 4 2 1 5 
  return 0;
}