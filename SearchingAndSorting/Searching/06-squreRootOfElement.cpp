#include<iostream>
using namespace std;

/*
  Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
*/

  
int sqrtOfNum(int x) {
  int startIndex = 0;
  int lastIndex = x;
  int ans = -1;

  while(startIndex <= lastIndex) {

    long long int mid = startIndex + (lastIndex - startIndex) / 2;

    if(mid*mid == x) {
        return mid;
    }else if(mid * mid < x) {
        ans = mid;
        //right search
        startIndex = mid + 1;
    }else {
        // left search
        lastIndex = mid - 1;
    }

  }

  return ans;
}

int main() {

  int num = 101;
  cout << "Square Root of: " << sqrtOfNum(num);
  return 0;
}

/*
  Possible test cases

  1
    int num = 64;
    cout << "Square Root of: " << sqrtOfNum(num); 
    Square Root of: 8

  2
    int num = 81;
    cout << "Square Root of: " << sqrtOfNum(num);
    Square Root of: -1

  3
    int num = 100;
    cout << "Square Root of: " << sqrtOfNum(num);
    Square Root of: 10

  4
    int num = 101;
    cout << "Square Root of: " << sqrtOfNum(num);
    Square Root of: 10

*/