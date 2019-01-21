// 缺失数字
// 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

// 示例 1:

// 输入: [3,0,1]
// 输出: 2
// 示例 2:

// 输入: [9,6,4,2,3,5,7,0,1]
// 输出: 8
// 说明:
// 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

#include "BaseHeader.hpp"


// 如果是 0~n 的数组中存放了 0~n 的数字，那个把 所有的下标和数组元素全部 异或 一次结果应该是0
// 因为 每个下标 和其 对应的数一样， 最终异或的结果就是0
// 那现在少了一个 元素， 就还按这个方式搞一遍， 最后结果就是缺的那个元素

class Solution
{
public:
  int missingNumber(vector<int>& nums)
  {
    int res = 0;
    int i = 0;
    for(; i < nums.size(); i++)
    {
      res ^= i ^ nums[i];
    }
    res  ^= i;
    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    vector<int> v = {3, 5, 6, 7, 8, 0, 1, 2};
    cout << s.missingNumber(v) << endl;
  }

  {
    vector<int> v = {3, 5, 6, 7, 8, 0, 1, 2, 4, 10};
    cout << s.missingNumber(v) << endl;
  }

  return 0;
}