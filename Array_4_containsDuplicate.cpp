// 存在重复
// 给定一个整数数组，判断是否存在重复元素。
// 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

// 示例 1:
// 输入: [1,2,3,1]
// 输出: true
// 示例 2:

// 输入: [1,2,3,4]
// 输出: false
// 示例 3:
// 输入: [1,1,1,3,3,4,3,2,4,2]
// 输出: true



#include "BaseHeader.hpp"

class Solution
{
public:
  bool containsDuplicate2(vector<int>& nums)
  {
    unordered_set<int> s;
    for(auto & i : nums)
    {
      if(s.count(i) > 0)
      {
        return true;
      }
      else
      {
        s.insert(i);
      }
    }
    return false;
  }
  bool containsDuplicate(vector<int>& nums)
  {
    if(nums.size() < 1)
    {
      return false;
    }
    sort(nums);


    for(int i = 0; i < nums.size() - 1; i++)
    {
      if(nums[i] == nums[i + 1])
      {
        return true;
      }
    }

    return false;
  }

  void sort(vector<int>& nums)
  {
    for(int i = 0; i < nums.size() - 1; i++)
    {
      int min = i;
      for(int j = i; j < nums.size(); j++)
      {
        if(nums[j] < nums[min])
        {
          min = j;
        }
      }
      if(min != i)
      {
        int tmp = nums[i];
        nums[i] = nums[min];
        nums[min] = tmp;
      }
    }
  }
};

int main(int argc, char const* argv[])
{
  Solution s;


  {
    vector<int> v = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
    DebugVector(v);
    s.sort(v);
    DebugVector(v);
    cout << s.containsDuplicate2(v) << endl;
  }
  {
    vector<int> v = { 5, 4, 3, 2, 1 };
    DebugVector(v);
    s.sort(v);
    DebugVector(v);
    cout << s.containsDuplicate2(v) << endl;
  }

  {
    vector<int> v = {  1, 2, 3, 1};
    DebugVector(v);
    s.sort(v);
    DebugVector(v);
    cout << s.containsDuplicate2(v) << endl;
  }

  return 0;
}