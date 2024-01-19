#include<iostream>
using namespace std;
   
double sqrtOfNumWithPrecision(int x, int precision) {

  // Handle the special case when the number is 0 or 1.
  if (x == 0 || x == 1) {
      return x;
  }

  int startIndex = 0;
  int lastIndex = x;
  float ans = 0.00;

  while(startIndex <= lastIndex) {

    int mid = startIndex + (lastIndex - startIndex) / 2;

    if(mid*mid == x) {
        ans =  mid;
        break;
    }else if(mid * mid < x) {
        //right search
        ans = mid;
        lastIndex = mid - 1;
    }else {
        // left search
        startIndex = mid + 1;
    }

  }

  // to calculate fractional part use for loop

  float increment = 0.1;
  for (int i = 0; i < precision; i++)
  {
    while(ans * ans <= x) {
        ans += increment;
    }

    // terminate when other condition
    ans = ans - increment;
    increment = increment / 10;
  }
  
  return ans;
}
int main() {

  int num = 68;
  int precision = 4;

  cout << "Sqrt of " << num << " is: " << sqrtOfNumWithPrecision(num, precision);
  return 0;
}