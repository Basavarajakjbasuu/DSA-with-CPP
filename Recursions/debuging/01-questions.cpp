  #include<iostream>
  using namespace std;

  /**
   Question- 01

  bool isPowerOfFour(int n) {
      if(n<=1){
          return false;
      }
      if(n%4!=0){
          return false;
      }
      
      return isPowerOfFour(n/4);
  }
  */

  bool isPowerOfFour(int n) {
    //if it is negative number
      if(n<=0){
          return false;
      }
      // 1 is power of 4
      if(n == 1) {
        return true;
      }

      // checking is n is not divisible by four if
      // it is then its not a power of 4
      if( n%4 != 0){
          return false;
      }
      
      return isPowerOfFour(n/4);
  } 

  bool isPowerOfFive(int n) {
    //Negative number
    if(n<=0) {
      return false;
    }

    if(n==1) {
      return true; // 5^0 = 1
    }

    if(n%5 != 0) {
      return false;
    }

    return isPowerOfFive(n/5);
  }


  int main() {
  
  cout << "Is it power of four " << isPowerOfFour(16) << endl;
  cout << "Is it power of five " << isPowerOfFive(625) << endl;
  return 0;
  }