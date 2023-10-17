// 66. 加一
// 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
// 你可以假设除了整数 0 之外，这个整数不会以零开头。
// 示例 1:
// 输入: [1,2,3]
// 输出: [1,2,4]
// 解释: 输入数组表示数字 123。
// 示例 2:
// 输入: [4,3,2,1]
// 输出: [4,3,2,2]
// 解释: 输入数组表示数字 4321。
#include "BaseHeader.hpp"

class Solution
{
public:
  vector<int> plusOne(vector<int>& digits)
  {
    vector<int> res;
    stack<int> s;
    int of = 0;

    for (int i = digits.size() - 1; i >= 0; i--) {
      int tmp = digits[i];
      if (i == digits.size() - 1) {
        tmp++;
      }

      if (tmp + of > 9) {
        s.push((tmp + of) % 10);
        of = 1;
      } else {
        s.push(tmp + of);
        of = 0;
      }
    }

    if (of) {
      res.push_back(1);
    }

    while (!s.empty()) {
      res.push_back(s.top());
      s.pop();
    }

    return res;
  }
};


int main(int argc, char const* argv[])
{
  Solution s;

  {
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> res;
    DebugVector(v);
    res = s.plusOne(v);
    DebugVector(res);
  }

  {
    vector<int> v = {1, 2, 3, 4, 9};
    vector<int> res;
    DebugVector(v);
    res = s.plusOne(v);
    DebugVector(res);
  }

  {
    vector<int> v = {9, 9, 9, 9, 9};
    vector<int> res;
    DebugVector(v);
    res = s.plusOne(v);
    DebugVector(res);
  }

  // DebugVector(v);
  // v.resize(v.size() + 1);
  // move(v.begin(), v.end(), v.begin() + 1);
  // DebugVector(v);
  return 0;
}

