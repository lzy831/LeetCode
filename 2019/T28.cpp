// 实现 strStr() 函数。
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
// 示例 1:
// 输入: haystack = "hello", needle = "ll"
// 输出: 2
// 示例 2:
// 输入: haystack = "aaaaa", needle = "bba"
// 输出: -1
// 说明:
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
#include "BaseHeader.hpp"

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    if(!haystack.size() && !needle.size())
    {
      return 0;
    }

    if(haystack.size() && !needle.size())
    {
      return 0;
    }

    if(!haystack.size() && needle.size())
    {
      return -1;
    }

    if(needle.size() > haystack.size())
    {
      return -1;
    }

    const char* mainstr = haystack.c_str();
    const char* substr = needle.c_str();

    int size = needle.size();
    int* next = new int[size];
    getNext(substr, next, size);

    int i = 0;
    int j = 0;
    int ihead = 0;
    while(i < haystack.size())
    {
      if(mainstr[i] == substr[j])
      {
        // 如果当前位置元素相等，则继续往后比较
        i++;
        j++;

        // j 已经处理到substr中最后一个元素，返回结果
        if(j == needle.size())
        {
          return i - j;
        }
      }
      else
      {
        // 如果发现不相等，则使用next数组进行回溯
        if(next[j] == -1)
        {
          // 为-1的话，则表示i需要在mainstr中向后移动一位，同时j要归零
          ihead++;
          i = ihead;
          j = 0;
        }
        else
        {
          // 否者j回溯到next[j]的位置
          j = next[j];
        }
      }
    }
    return -1;
  }
  void getNext(const char* substr, int* next, int len)
  {
    int j = 0;
    int k = -1;
    next[0] = -1;
    
    // next[0] = -1 和 next[1] = 0 是固定的
    // 

    while(j < len - 1)
    {
      if(k == -1 || substr[j] == substr[k])
      {
        //  next[++j] = ++k;   // 强记吧,不是很容易理解

        j++;
        k++;
        next[j] = k;
      }
      else
      {
        k = next[k];
      }
    }
  }
};


int main()
{
  Solution s;
  // string haystack = "abcdeaaabcdefdaasd";
  // string needle = "abcdefda";

  // string haystack = "bbbbaaaaaaaabbbaaaabbaaaaaaaaaaa";
  // string needle = "aaaaaaaaaa";

  {
    string haystack = "he111111111111llo";
    string needle = "a";
    printf("-1  %d\n", s.strStr(haystack, needle));
  }
  {
    string haystack = "he111111111111llo";
    string needle = "111";
    printf("2  %d\n", s.strStr(haystack, needle));
  }
  {
    string haystack = "he111111111111llo";
    string needle = "";
    printf("0  %d\n", s.strStr(haystack, needle));
  }
  {
    string haystack = "";
    string needle = "";
    printf("0  %d\n", s.strStr(haystack, needle));
  }
  {
    string haystack = "";
    string needle = "111";
    printf("-1  %d\n", s.strStr(haystack, needle));
  }
  // cout << s.strStr(haystack, needle) << endl;
}

