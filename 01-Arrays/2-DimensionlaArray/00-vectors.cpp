#include<iostream>
#include<vector>
using namespace std;
 
int main() {
  vector<int> v(5);

  //Printing
  for(int i=0; i<v.size(); i++) {
    cout << v[i] << " ";
  }

  // vector<int> arr(5);
  // //Insert
  // arr.push_back(4);
  // arr.push_back(8);
  // arr.push_back(12);

  vector< vector<int>> arr(5, vector<int> (10, -1));

  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = 0; j < arr[i].size(); j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  /**
   -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
  */
  



  return 0;
}