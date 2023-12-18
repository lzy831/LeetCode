#include "BaseHeader.h"

class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;

    // 空输入也是可以返回 true 的
    for (int i = 0; i < s.size(); i++) {
      if (!isValidChar(s[i])) {  // 非法值，直接失败
        return false;
      }

      if (isLeft(s[i])) {
        // 左括号直接入栈
        stk.push(s[i]);
      } else if (isRight(s[i])) {
        // 右括号，如果匹配栈顶的左括号，则消除，否则失败
        if (!stk.empty() && canMatchLeft(stk.top(), s[i])) {
          stk.pop();
        } else {
          return false;
        }
      }
    }

    return stk.empty();
  }

 private:
  bool isValidChar(char c) {
    return c == '(' || c == ')'     //
           || c == '[' || c == ']'  //
           || c == '{' || c == '}';
  }

  bool isLeft(char c) { return c == '(' || c == '[' || c == '{'; }
  bool isRight(char c) { return c == ')' || c == ']' || c == '}'; }
  bool canMatchLeft(char left, char right) {
    if (left == '(')
      return right == ')';
    if (left == '[')
      return right == ']';
    if (left == '{')
      return right == '}';
    return false;
  }
};

int main() {
  Solution solution;
  std::string s("()[{}");

  cout << solution.isValid(s) << endl;
  return 0;
}
