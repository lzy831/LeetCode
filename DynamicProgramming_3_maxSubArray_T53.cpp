// 最大子序和
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 示例:

// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 进阶:

// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
#include "BaseHeader.hpp"

class Solution
{
public:
  int maxSubArray(vector<int>& nums)
  {
    int max = std::numeric_limits<int>::min();
    int sum = 0;

    for(int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      if(sum < nums[i])
      {
        sum = nums[i];
      }
      max = std::max(sum, max);
    }

    return max;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    vector<int> v = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(v) << endl;
  }
  {
    vector<int> v = { -1};
    cout << s.maxSubArray(v) << endl;
  }
  return 0;
}