#include<iostream>
using namespace std;

/*

1
2 2
3 3 3
4 4 4 4
5 5 5 5 5

print row + 1
*/
int main() {

  int numRows = 0;
  cin >> numRows;

  for (int row = 0; row < numRows; row++){
    
    for (int col = 0; col < row + 1; col++){

      cout << row + 1 << " ";
    }
    cout << endl;
  }
  
  return 0;
}

/*
    5
    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5
*/