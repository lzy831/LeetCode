// 有效的括号
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 示例 1:

// 输入: "()"
// 输出: true
// 示例 2:

// 输入: "()[]{}"
// 输出: true
// 示例 3:

// 输入: "(]"
// 输出: false
// 示例 4:

// 输入: "([)]"
// 输出: false
// 示例 5:

// 输入: "{[]}"
// 输出: true

#include "BaseHeader.hpp"

class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> stk;

    for(auto & i : s)
    {
      if(stk.empty() || !isMatch(stk.top(), i))
      {
        stk.push(i);
      }
      else
      {
        stk.pop();
      }
    }
    return stk.empty();
  }

  bool isMatch(const char& a, const char& b)
  {
    return (a == '(' && b == ')') ||
           (a == '[' && b == ']') ||
           (a == '{' && b == '}');
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    string ss("()[]{}");
    cout << s.isValid(ss) << endl;
  }

  {
    string ss("{[]}");
    cout << s.isValid(ss) << endl;
  }

  {
    string ss("([)]");
    cout << s.isValid(ss) << endl;
  }
  return 0;
}