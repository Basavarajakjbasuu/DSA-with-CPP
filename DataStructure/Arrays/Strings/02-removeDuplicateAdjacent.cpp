#include<iostream>
#include<string.h>

using namespace std;
string removeDuplicates(string s) {
    string ans = "";
    int index = 0;
    int len = s.length();

    while(index < s.length()) {

        if(ans.length() > 0 && ans[ans.length() - 1] == s[index]) {
            ans.pop_back();
        }else {
            ans.push_back(s[index]);
        }
        index++;
    }

    return ans;
}
int main() {

    string input = "deeedbbcccbdaa";

    cout << removeDuplicates(input) <<  endl;
    return 0;
}