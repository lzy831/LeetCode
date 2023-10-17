// Fizz Buzz
// 写一个程序，输出从 1 到 n 数字的字符串表示。

// 1. 如果 n 是3的倍数，输出“Fizz”；

// 2. 如果 n 是5的倍数，输出“Buzz”；

// 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

// 示例：

// n = 15,

// 返回:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]
#include "BaseHeader.hpp"

class Solution
{
public:
  vector<string> fizzBuzz(int n)
  {
    vector<string> res;
    for(int i = 1; i <= n; i++)
    {
      if(i % 3 == 0 && i % 5 != 0)
      {
        res.push_back("Fizz");
      }
      else if(i % 3 != 0 && i % 5 == 0)
      {
        res.push_back("Buzz");
      }
      else if(i % 3 == 0 && i % 5 == 0)
      {
        res.push_back("FizzBuzz");
      }
      else
      {
        res.push_back(std::to_string(i));
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;
  vector<string> res = s.fizzBuzz(50);
  for(auto & i : res)
  {
    cout << i.c_str() << endl;
  }
  return 0;
}