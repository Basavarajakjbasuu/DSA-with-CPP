#include<iostream>
#include<queue>
using namespace std;
 
int main() {
  string str = "ababc";
  queue<char> qu;
  int freq[26] = {0};

  for (int i = 0; i < str.length(); i++)
  {
    char ch = str[i];
    freq[ch-'a']++;
    qu.push(ch);

    // Find answer
    while(!qu.empty()) {
      char frontCharacter = qu.front();

      if(freq[frontCharacter - 'a'] > 1) {
        qu.pop();
      }else {
        // frontCharacter == 1 case
        cout << frontCharacter << "->";
        break;
      }
    }

    if(qu.empty()) {
      cout << "#" << "->";
    }
  }
  

  return 0;
}

/*
  INP = ababc
  a->a->b->#->c->
*/