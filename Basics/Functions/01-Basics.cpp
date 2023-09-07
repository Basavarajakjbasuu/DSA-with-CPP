#include<iostream>
using namespace std;
 
void sumOfTwoNum(int num1, int num2) {
  int ans = num1 + num2;
  cout << "Sum is " << ans;
}

int sumOfTwoNums(int num1, int num2) {
  return num1 + num2;
}
int main() {

  sumOfTwoNum(2, 8); //Sum is 10
  cout << endl;
  cout << "Sum is " << sumOfTwoNums(4, 2) <<endl; // Sum is 6
  return 0;
}