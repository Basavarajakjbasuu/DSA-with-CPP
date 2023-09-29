#include<iostream>
using namespace std;
 
int main() {

  string firstName;

  string lastName;

  cin >> firstName;
  cin >> lastName;

  cout << "Length of string: " << firstName.length() << endl;
  cout << "Is string is Empty: " << firstName.empty() << endl;
  cout << "char at 0th postion: " << firstName.at(0) << endl;
  cout << "Front char of String: " << firstName.front() << endl;
  cout << "Back char of String: " << firstName.back() << endl;

  // append
  cout << "Append " << firstName << " and " << lastName << " : " << firstName.append(lastName) << endl;

  // Erase the char in string
  string description = "This is a String";
  description.erase(5, 3);
  cout << description << endl; //This a String

  // find
  string str1 = "We are best friends!";
  string checkStr = "best";

  // npos - No postion
  if(str1.find(checkStr) == string::npos) {
    cout << checkStr << " not is there \n";
  }else {
    cout << checkStr << " is there \n";
  }

  // compare
  string st1 = "Friends";
  string st2 = "Friends";

  if(st1.compare(st2)) {
    cout << "Matching \n";
  }else {
    cout << "Not matching \n";
  }

  // substrings
  string myStr = "This is my favorite car";

  cout << myStr.substr(11, 8) << endl; //Favorite

  return 0;
}

/*
  Basavaraja KJ
  Length of string: 10
  Is string is Empty: 0
  char at 0th postion: B
  Front char of String: B
  Back char of String: a
  Append Basavaraja and KJ : BasavarajaKJ
  This a String
  best is there 
  Not matching 
  Favorite 
*/