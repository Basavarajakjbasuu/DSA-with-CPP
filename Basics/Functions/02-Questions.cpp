#include<iostream>
using namespace std;

  // maximum of three number
  int maxOfThreeNums(int num1, int num2, int num3) {

    if(num1 >= num2 && num1 >= num3) {
      return num1;
    } else if(num2 >= num1 && num2 >= num3) {
      return num2;
    }else {
      return num3;
    }
  }

  //Approach 2
  int maxOfThreeNum2(int num1, int num2, int num3) {
    int ans = max(num1, num2);
    int finalAns = max(ans, num3);
    return finalAns;
  }

int main() {

    cout << "Maximum Num is: " << maxOfThreeNums(-12, -5, -10); //Maximum Num is: -5
    cout << "Maximum Num is: " << maxOfThreeNum2(-12, 5, -10); //Maximum Num is: 5
    return 0;
}