#include<iostream>
using namespace std;

bool  isEven(int num) {

  if(num % 2 == 0) return true;

  return false;
} 

//Bitwise solution
bool  isEven1(int num) {

  if((num&1) == 0) return true;

  return false;
}

int main() {
 
  int num=0;

  cout<< "Enter the num: ";
  cin>>num;

  if(isEven1(num)) {
    cout<< num << " is Even" << endl;
  } else {
    cout<< num << " is Odd" << endl;
  }
  return 0;
}