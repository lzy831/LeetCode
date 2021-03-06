// 位1的个数
// 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。
// 示例 1：
// 输入：00000000000000000000000000001011
// 输出：3
// 解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
// 示例 2：
// 输入：00000000000000000000000010000000
// 输出：1
// 解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
// 示例 3：
// 输入：11111111111111111111111111111101
// 输出：31
// 解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
// 提示：
// 请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
// 在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在上面的 示例 3 中，输入表示有符号整数 -3。
// 进阶:
// 如果多次调用这个函数，你将如何优化你的算法？

#include "BaseHeader.hpp"

class Solution
{
public:
  int hammingWeight(uint32_t n)
  {
    uint32_t f = 1;
    int res = 0;
    int bits = 32;
    for(int i = 0; i < 32; i++)
    {
      if(((f << i) & n) != 0)
      {
        res++;
      }
    }
    return res;
  }


  //  一个数 与 这个数-1 的数， 会把这个数2进制位中最后一个 1 清除掉
  // 比如 6 (0110)   0110b & 0101b = 0100  -> 可以发现最后一个 1 被清除掉了
  int hammingWeight1(uint32_t n)
  {
    int res = 0;
    while(n)
    {
      n = n & (n - 1);
      res++;
    }
    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    cout << s.hammingWeight(std::numeric_limits<unsigned int>::max()) << endl;
    cout << s.hammingWeight(std::numeric_limits<unsigned int>::min()) << endl;
    cout << s.hammingWeight(0) << endl;
    cout << s.hammingWeight(17) << endl;
  }

  {
    cout << s.hammingWeight1(std::numeric_limits<unsigned int>::max()) << endl;
    cout << s.hammingWeight1(std::numeric_limits<unsigned int>::min()) << endl;
    cout << s.hammingWeight1(0) << endl;
    cout << s.hammingWeight1(17) << endl;
  }

  return 0;
}