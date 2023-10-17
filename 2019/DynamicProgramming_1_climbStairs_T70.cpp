// 爬楼梯
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 注意：给定 n 是一个正整数。

// 示例 1：

// 输入： 2
// 输出： 2
// 解释： 有两种方法可以爬到楼顶。
// 1.  1 阶 + 1 阶
// 2.  2 阶
// 示例 2：

// 输入： 3
// 输出： 3
// 解释： 有三种方法可以爬到楼顶。
// 1.  1 阶 + 1 阶 + 1 阶
// 2.  1 阶 + 2 阶
// 3.  2 阶 + 1 阶

#include "BaseHeader.hpp"

class Solution
{
public:
  int climbStairs(int n)
  {
    if( n < 1)
    {
      return 0;
    }
    if( n == 1)
    {
      return 1;
    }
    if( n== 2)
    {
      return 2;
    }

    int minus2 = 1;
    int minus1 = 2;
    int i = 3;
    int res = 0;
    while(i<=n)
    {
      res = minus2 + minus1;
      minus2 = minus1;
      minus1 = res;
      i++;
    }
    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;
  cout << s.climbStairs(0) << endl;
  cout << s.climbStairs(1) << endl;
  cout << s.climbStairs(2) << endl;
  cout << s.climbStairs(3) << endl;
  cout << s.climbStairs(4) << endl;
  cout << s.climbStairs(5) << endl;
  cout << s.climbStairs(6) << endl;
  cout << s.climbStairs(7) << endl;
  return 0;
}