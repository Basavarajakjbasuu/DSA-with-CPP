#include<iostream>
#include<string.h>
using namespace std;
 
string decodeMessage(string key, string message) {
  // create Mapping
  char start = 'a';
  char mapping[260] = {0};

  for(auto ch: key) {
      if(ch != ' ' && mapping[ch] == 0) {
          mapping[ch] = start;
          start++;
      }
  }

  // use mapping
  string ans;
  for(auto ch: message) {
      if(ch == ' ') {
          ans.push_back(' ');
      }else {
          char decodedChar = mapping[ch];
          ans.push_back(decodedChar);
      }
  }

  return ans;
} 
int main() {

  string key = "the quick brown fox jumps over the lazy dog";
  string message = "vkbs bs t suepuv";

  cout << decodeMessage(key, message) << endl;

  return 0;
}