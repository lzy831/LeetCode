// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

// 示例 1:

// 输入: [1,2,3,4,5,6,7] 和 k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右旋转 1 步: [7,1,2,3,4,5,6]
// 向右旋转 2 步: [6,7,1,2,3,4,5]
// 向右旋转 3 步: [5,6,7,1,2,3,4]
// 示例 2:

// 输入: [-1,-100,3,99] 和 k = 2
// 输出: [3,99,-1,-100]
// 解释:
// 向右旋转 1 步: [99,-1,-100,3]
// 向右旋转 2 步: [3,99,-1,-100]
// 说明:

// 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
// 要求使用空间复杂度为 O(1) 的原地算法。
#include "BaseHeader.hpp"

class Solution
{
public:
  void rotate(vector<int>& nums, int k)
  {
    if(nums.size() < 1)
    {
      return ;
    }
    k = k % nums.size();

    if(k != 0)
    {
      reverse(nums, 0, nums.size() - k -1);
      reverse(nums, nums.size() - k , nums.size()-1);
      reverse(nums, 0, nums.size()-1);
    }
  }

  void reverse(vector<int>& nums, int begin, int end)
  {
    if(begin == end)
    {
      return ;
    }

    while(begin < end)
    {
      int tmp = nums[begin];
      nums[begin] = nums[end];
      nums[end] = tmp;
      begin++;
      end--;
    }
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(v, 0);
    DebugVector(v);
  }
  {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(v, 7);
    DebugVector(v);
  }
  {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(v, 1);
    DebugVector(v);
  }
  {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(v, 2);
    DebugVector(v);
  }
  {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(v, 10);
    DebugVector(v);
  }
  return 0;
}