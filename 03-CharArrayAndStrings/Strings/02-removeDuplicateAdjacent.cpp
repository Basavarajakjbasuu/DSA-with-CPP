#include<iostream>
#include<string.h>

using namespace std;
//New string method
string removeDuplicates(string s) {
    string ans = "";
    int index = 0;
    int len = s.length();

    while(index < s.length()) {
        // we will check if current character index and  previous index element(right most element) is same then pop it
        if(ans.length() > 0 && ans[ans.length() - 1] == s[index]) {
            ans.pop_back();
        }else {
            //else will push it new string
            ans.push_back(s[index]);
        }
        index++;
    }

    return ans;
}
int main() {

    string input = "deeedbbcccbdaa";

    cout << "Output string: " << removeDuplicates(input) <<  endl;
    return 0;
}


/* TEST CASES
  1. string inStr = "abbaca";
    Output string: ca

  2. string inStr = "azxxzy";
    Output string: ay

  3. string input = "deeedbbcccbdaa";
    Output string: dedcbd

*/