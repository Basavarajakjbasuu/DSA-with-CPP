#include<iostream>
#include<vector>

using namespace std;

/*
  Example 1:

  Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
  Output: 21
  Explanation:
  The paper garbage truck:
  1. Travels from house 0 to house 1
  2. Collects the paper garbage at house 1
  3. Travels from house 1 to house 2
  4. Collects the paper garbage at house 2
  Altogether, it takes 8 minutes to pick up all the paper garbage.
  The glass garbage truck:
  1. Collects the glass garbage at house 0
  2. Travels from house 0 to house 1
  3. Travels from house 1 to house 2
  4. Collects the glass garbage at house 2
  5. Travels from house 2 to house 3
  6. Collects the glass garbage at house 3
  Altogether, it takes 13 minutes to pick up all the glass garbage.
  Since there is no metal garbage, we do not need to consider the metal garbage truck.
  Therefore, it takes a total of 8 + 13 = 21 minutes to collect all the garbage.
*/
int garbageCollection(vector<string>& garbage, vector<int>& travel) {
  int pickP = 0;
  int pickM = 0;
  int pickG = 0;

  int travelP = 0;
  int travelM = 0;
  int travelG = 0;

  int lastP = 0;
  int lastM = 0;
  int lastG = 0;

  // Calculate pick time

  for(int i=0; i<garbage.size(); i++) {
      string curr = garbage[i];

      for(int j=0; j< curr.length(); j++) {
          char ch = curr[j];
          if(ch == 'P') {
              pickP++;
              lastP = i;
          }else if(ch == 'M') {
              pickM++;
              lastM = i;
          }else if(ch == 'G') {
              pickG++;
              lastG = i;
          }
      }
  }

  // calculate travel time
  for(int i=0; i<lastP; i++) {
      travelP += travel[i];
  }

  for(int i=0; i<lastM; i++) {
      travelM +=travel[i];
  }

  for(int i=0; i<lastG; i++) {
      travelG += travel[i];
  }

  // cout << "P" <<(pickP ) <<endl;
  // cout << "M" <<(pickM ) <<endl;
  // cout << "G" <<(pickG ) <<endl;
  // cout << "P" <<(travelP) <<endl;
  // cout << "M" <<(travelM) <<endl;
  // cout << "G" <<(travelG) <<endl;
  int ans = (pickP + travelP) + (pickM + travelM) + (pickG + travelG);

  return ans;
}

int main() {
  vector<string> garbage = { "G", "P", "GP", "GG" };

  vector<int> travel = { 2, 4, 3 };

  cout << "Minimum time to collect garbage: " << garbageCollection(garbage, travel);
  return 0;
}

/*
  Minimum time to collect garbage: 21
*/