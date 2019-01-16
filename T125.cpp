// 125. 验证回文串
// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
// 说明：本题中，我们将空字符串定义为有效的回文串。 
// 示例 1:
// 输入: "A man, a plan, a canal: Panama"
// 输出: true
// 示例 2:
// 输入: "race a car"
// 输出: false

#include "BaseHeader.hpp"

class Solution
{
public:
  bool isPalindrome(string s)
  {
    if(!s.size())
    {
      return true;
    }
    auto begin = s.begin();
    auto end = s.end() - 1;

    while(begin != end)
    {
      if(!(('a' <= *begin && *begin <= 'z')  || ('A' <= *begin && *begin <= 'Z')  || ('0' <= *begin && *begin <= '9')))
      {
        begin++;
        continue;
      }
      if(!(('a' <= *end && *end <= 'z') || ('A' <= *end && *end <= 'Z') || ('0' <= *end && *end <= '9')))
      {
        end--;
        continue;
      }


      if((('a' <= *begin && *begin <= 'z') || ('A' <= *begin && *begin <= 'Z')) &&
          (('a' <= *end && *end <= 'z') || ('A' <= *end && *end <= 'Z')))
      {
        if(toupper(*begin) != toupper(*end))
        {
          return false;
        }
      }
      else if(('0' <= *begin && *begin <= '9')  && ('0' <= *end && *end <= '9'))
      {
        if(*begin != *end)
        {
          return false;
        }
      }
      else
      {
        return false;
      }

      if(begin + 1 == end)
      {
        break;
      }

      begin++;
      end--;
    }
    return true;
  }
};

int main()
{
  Solution s;
  string str("abcdefg");

  // cout << *(str.begin()) << endl;
  // cout << *(str.end() - 1) << endl;

  // cout << s.isPalindrome(string("")) << endl;
  // cout << s.isPalindrome(string("acbdbca")) << endl;
  // cout << s.isPalindrome(string("acbbca")) << endl;
  // cout << s.isPalindrome(string("acbeca")) << endl;

  cout << s.isPalindrome(string(" ;A man,;& a plan, a canal: Panama")) << endl;

  cout << s.isPalindrome(string(" race  a car ")) << endl;

  cout << s.isPalindrome(string("race  a car")) << endl;

  cout << s.isPalindrome(string("ab")) << endl;
  return 0;
}
