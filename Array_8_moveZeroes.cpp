// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
// 示例:
// 输入: [0,1,0,3,12]
// 输出: [1,3,12,0,0]
// 说明:
// 必须在原数组上操作，不能拷贝额外的数组。
// 尽量减少操作次数。
#include "BaseHeader.hpp"



class Solution
{
public:
  void moveZeroes(vector<int>& nums)
  {
    // last 记录遍历过程中，最后一个非0值的位置
    // 顺序遍历，只要发现非0的，就换到前面来
    int last = 0;
    for(int i = 0; i < nums.size(); i++)
    {
      if(nums[i] != 0)
      {
        // swap(nums[i],nums[last]);

        // last++;
        // int tmp = nums[i];
        // nums[i] = nums[last];
        // nums[last] = tmp;

        nums[last++] = nums[i];
      }
    }
    while(last < nums.size())
    {
      nums[last++] = 0;
    }
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    vector<int> v = { 0, 1, 0, 3, 12};
    DebugVector(v);
    s.moveZeroes(v);
    DebugVector(v);
  }
  {
    vector<int> v = { 1, 0, 3, 4, 5};
    DebugVector(v);
    s.moveZeroes(v);
    DebugVector(v);
  }
  {
    vector<int> v = { 0, 0, 0, 0, 0};
    DebugVector(v);
    s.moveZeroes(v);
    DebugVector(v);
  }
  {
    vector<int> v = { 1, 2, 3, 4, 5};
    DebugVector(v);
    s.moveZeroes(v);
    DebugVector(v);
  }
  {
    vector<int> v;
    DebugVector(v);
    s.moveZeroes(v);
    DebugVector(v);
  }
  return 0;
}







