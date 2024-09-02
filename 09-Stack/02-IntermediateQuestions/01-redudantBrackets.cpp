#include<iostream>
#include<stack>
using namespace std;
 
bool checkRedundant(string str) {
  stack<char> st;

  for(int i=0; i<str.length(); i++) {
    char ch = str[i];

    if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      st.push(ch);
    }else if (ch == ')') {
      // If a found closing bracket then i need to count operator until its open bracket
      int operatorCount = 0;
      while(!st.empty() && st.top() != '(') {
        char temp = st.top();

        if(temp == '+' || temp == '-' || temp == '*' || temp == '/') {
          operatorCount++;
        }

        st.pop();
      }
      //If we reach here then only one bracket present so we pop it
      st.pop();

      if (operatorCount == 0) {
        return true;
      }

    }
  }

// each bracket pair have single operator so no redundant bracket 
  return false;
}

int main() {
 
  string str = "((a+b)*(c-d))";

  bool ans = checkRedundant(str);

  if(ans == true) {
    cout << "Redundant Brackets  present." << endl;
  }else {
    cout << "Redundant Brackets Not present." << endl;
  }
  return 0;
}


/*
  string str = "((a+b)*(c-d))";
  Redundant Brackets Not present.

  string str = "((a+b)*(c-d)))";
  Redundant Brackets  present.
*/
