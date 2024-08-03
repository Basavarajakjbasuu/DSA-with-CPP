#include<iostream>
using namespace std;
 
int main() {
  
  // creation

  char ch[05];

  // input - it will take only first word that is before " ", "\n", "\t"
  // cin >> ch;

  // print
  // cout << ch;

  // take entire sentence
  char phrase[100];

  cin.getline(phrase, 100); // My name is Bassu

  cout << phrase << endl; // My name is Bassu
  return 0;
}