// 最长公共前缀
// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1:

// 输入: ["flower","flow","flight"]
// 输出: "fl"
// 示例 2:

// 输入: ["dog","racecar","car"]
// 输出: ""
// 解释: 输入不存在公共前缀。
// 说明:

// 所有输入只包含小写字母 a-z 。
#include "BaseHeader.hpp"

class Solution
{
public:
  string longestCommonPrefix(vector<string>& strs)
  {
    string res;
    if(strs.empty())
    {
      return res;
    }
    if(strs.size() < 2)
    {
      return strs[0];
    }


    for(int i = 0; i < strs[0].size(); i++)
    {

      for(int j = 1; j < strs.size(); j ++)
      {
        if(strs[j].size() > i)
        {
          if(strs[0][i] != strs[j][i])
          {
            return res;
          }
        }
        else
        {
          return res;
        }
      }
      res.append(1, strs[0][i]);
    }

    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    vector<string> v = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(v).c_str() << endl;
  }
  {
    vector<string> v = {"flower", "fdow", "flight"};
    cout << s.longestCommonPrefix(v).c_str() << endl;
  }

  {
    vector<string> v = {"flower"};
    cout << s.longestCommonPrefix(v).c_str() << endl;
  }

  return 0;
}