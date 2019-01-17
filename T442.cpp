#include "BaseHeader.hpp"

class Solution
{
public:
  vector<int> findDuplicates(vector<int>& nums)
  {
    vector<int> res;

    if(nums.size() == 0)
    {
      return res;
    }
    // 注意该算法无法处理输入数组中存在重复3次的数值的情况
    for(int i = 0; i < nums.size(); i++)
    {
      // 该位置上的数值和下标不对应，并且和以该数值为下标的数值 不相等，则交换
      // 直到该位置上的数值和下标对应，或者 以该数值为下标的数值 相当（发现重复数）
      while(nums[i] != i + 1 &&  nums[i] != nums[nums[i] - 1])
      {
        int temp = nums[nums[i] - 1];
        nums[nums[i] - 1] = nums[i];
        nums[i] = temp;
      }
    }
    // DebugVector(nums);

    for(int i = 0; i < nums.size(); i++)
    {
      if( nums[i] != i+1)
      {
        res.push_back(nums[i]);
      }
    }
    // DebugVector(res);
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> v;
  v.push_back(4);
  v.push_back(3);
  v.push_back(2);
  v.push_back(7);
  v.push_back(8);
  v.push_back(2);
  v.push_back(3);
  v.push_back(1);

  DebugVector(v);
  vector<int> res = s.findDuplicates(v);
  DebugVector(res);
  return 0;
}