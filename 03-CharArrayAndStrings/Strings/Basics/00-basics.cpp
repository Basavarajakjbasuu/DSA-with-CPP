#include<iostream>
using namespace std;
 
int main() {

  // creation
  string name;

  // input
  // cin >> name;

  getline(cin, name); // to take more than one word as input

  // output
  cout << "Ouput: " << name << endl;

  // Print first character
  cout << "First character is: " << name[0] << endl;

  int index = 0;

  while(name[index] != '\0') {
    cout << "index: " << index << " character " << name[index] << endl;
    index++;
  }

  return 0;
}

/*
  Bassu
  Ouput: Bassu
  First character is: B
  index: 0 character B
  index: 1 character a
  index: 2 character s
  index: 3 character s
  index: 4 character u
*/