// 有效的字母异位词
// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

// 示例 1:

// 输入: s = "anagram", t = "nagaram"
// 输出: true
// 示例 2:

// 输入: s = "rat", t = "car"
// 输出: false
// 说明:
// 你可以假设字符串只包含小写字母。

// 进阶:
// 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

#include "BaseHeader.hpp"

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    int a[26];
    int b[26];
    for(int i = 0; i < 26; i++)
    {
      a[i] = 0;
      b[i] = 0;
    }

    for(auto & i : s)
    {
      a[i - 'a']++;
    }
    for(auto & i : t)
    {
      b[i - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
      if(a[i] != b[i])
      {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    string s1 = "anagram";
    string s2 = "nagaram";
    cout << s.isAnagram(s1, s2) << endl;
  }
  {
    string s1 = "anagbam";
    string s2 = "nagaram";
    cout << s.isAnagram(s1, s2) << endl;
  }
  {
    string s1;
    string s2 = "nagaram";
    cout << s.isAnagram(s1, s2) << endl;
  }
  return 0;
}