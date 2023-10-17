// 计数质数
// 统计所有小于非负整数 n 的质数的数量。

// 示例:

// 输入: 10
// 输出: 4
// 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
#include "BaseHeader.hpp"

class Solution
{
public:
  int countPrimes(int n)
  {
    int res = 0;
    vector<bool> p(n, true);

    // 0,1 都不是质数，从2开始循环
    for(int i = 2; i < n; i++)
    {
      if(p[i])
      {
        res ++;
        for(int j = 2 ; i * j < n; j++)
        {
          p[i * j] = false;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;
  cout << s.countPrimes(10) << endl;
  cout << s.countPrimes(120) << endl;
  return 0;
}