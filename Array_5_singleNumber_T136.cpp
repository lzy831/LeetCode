// 136. 只出现一次的数字
// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
// 示例 1:
// 输入: [2,2,1]
// 输出: 1
// 示例 2:
// 输入: [4,1,2,1,2]
// 输出: 4
#include "BaseHeader.hpp"

class Solution
{
public:
  // 思路：
  // 因为只有1个元素是出现1次，其他都是出现2次，所以把所有的数字异或运算一下，结果就是只出现一次的那个数字
  int singleNumber(vector<int>& nums)
  {
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      res = res ^ nums[i];
    }
    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    vector<int> v = { 1 };
    DebugVector(v);
    cout << s.singleNumber(v) << endl;
  }

  {
    vector<int> v = { 1, 2, 2, 5, 5 };
    DebugVector(v);
    cout << s.singleNumber(v) << endl;
  }

  return 0;
}