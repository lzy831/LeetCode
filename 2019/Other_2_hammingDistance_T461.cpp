// 汉明距离
// 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
// 给出两个整数 x 和 y，计算它们之间的汉明距离。
// 注意：
// 0 ≤ x, y < 231.
// 示例:
// 输入: x = 1, y = 4
// 输出: 2
// 解释:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// 上面的箭头指出了对应二进制位不同的位置。
#include "BaseHeader.hpp"

class Solution
{
public:
  int hammingDistance(int x, int y)
  {
    int n = x ^ y;
    int res = 0;
    while(n)
    {
      n = n & (n - 1);
      res ++;
    }
    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  cout << s.hammingDistance(1, 4) << endl;
  cout << s.hammingDistance(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) << endl;
  cout << s.hammingDistance(0, std::numeric_limits<int>::max()) << endl;
  return 0;
}