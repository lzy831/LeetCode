// 387. 字符串中的第一个唯一字符
// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
// 案例:
// s = "leetcode"
// 返回 0.
// s = "loveleetcode",
// 返回 2.
#include "BaseHeader.hpp"

class Solution
{
public:
  // 思路:
  // ASCII码简易hash表统计
  int firstUniqChar(string s)
  {
    if (s.empty()) {
      return -1;
    }

    int a[26];
    for (int i = 0; i < 26; i++) {
      a[i] = 0;
    }

    for (int i = 0; i < s.size(); i++) {
      a[s[i] - 'a']++;
    }

    for (int i = 0; i < s.size(); i++) {
      if (a[s[i] - 'a'] == 1) {
        return i;
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    string str("loveleetcode");
    cout << s.firstUniqChar(str) << endl;
  }

  return 0;
}