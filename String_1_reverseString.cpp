// 反转字符串
// 编写一个函数，其作用是将输入的字符串反转过来。
// 示例 1:
// 输入: "hello"
// 输出: "olleh"
// 示例 2:
// 输入: "A man, a plan, a canal: Panama"
// 输出: "amanaP :lanac a ,nalp a ,nam A"

#include "BaseHeader.hpp"

class Solution
{
public:
  string reverseString(string s)
  {
    if( s.empty())
    {
      return s;
    }
    
    string res = s;
    int begin = 0;
    int end = res.size() - 1;

    while(begin < end)
    {
      char tmp = res[begin];
      res[begin] = res[end];
      res[end] = tmp;

      begin++;
      end--;
    }
    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  string str("A man, a plan, a canal: Panama");

  cout << str.c_str() << endl;

  cout <<  s.reverseString(str).c_str()  << endl;

  return 0;
}