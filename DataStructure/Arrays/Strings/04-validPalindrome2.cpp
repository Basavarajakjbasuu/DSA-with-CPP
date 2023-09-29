#include<iostream>
#include<string.h>
using namespace std;

bool isPalindrome(string str, int startIndex, int endIndex)
{
  while (startIndex <= endIndex)
  {

    if (str[startIndex] != str[endIndex])
    {
      return false;
    }
    else
    {
      startIndex++;
      endIndex--;
    }
  }

  return true;
}

bool validPalindrome(string s)
{
  int startIndex = 0;
  int endIndex = s.length() - 1;

  while (startIndex <= endIndex)
  {

    if (s[startIndex] == s[endIndex])
    {
      startIndex++;
      endIndex--;
    }
    else
    {
      bool ans1 = isPalindrome(s, startIndex + 1, endIndex);
      bool ans2 = isPalindrome(s, startIndex, endIndex - 1);

      return ans1 || ans2;
    }
  }

  return true;
}

int main() {

  string inStr = "abca";

  cout << validPalindrome(inStr);
  return 0;
}