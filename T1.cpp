#include "BaseHeader.hpp"


class Solution
{
public:

  // hashmap方式
  // 执行耗时 8ms
  vector<int> twoSum_hashmap(vector<int>& nums, int target)
  {
    vector<int> res;
    unordered_map<int, int> hashmap;

    // 以元素值为key，以元素下标为value简历hashmap
    for(int i = 0; i < nums.size(); i++)
    {
      hashmap[nums[i]] = i;
    }

    for(int i = 0; i < nums.size(); i++)
    {
      // 遍历数组，对于每一个元素，在hashmap中找target与该元素的差是否存在
      // 如果存在，并且这个差不是该元素本身，则视为找到
      auto search = hashmap.find(target - nums[i]);
      if(search != hashmap.end() && search->second != i)
      {
        res.push_back(i);
        res.push_back(search->second);
        break;
      }
    }
    return res;
  }





  // 暴利求解
  // 时间复杂度O(n^2)
  // 空间复杂度O(1)
  // 执行耗时 188ms
  vector<int> twoSum(vector<int>& nums, int target)
  {
    vector<int> res;
    for(int i = 0; i < nums.size(); i++)
    {
      for(int j = i + 1; j < nums.size(); j++)
      {
        if(nums[i] + nums[j] == target)
        {
          res.push_back(i);
          res.push_back(j);
          break;
        }
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> v;
  v.push_back(2);
  v.push_back(7);
  v.push_back(11);
  v.push_back(5);

  // vector<int> res = s.twoSum(v, 9);

  vector<int> res = s.twoSum_hashmap(v, 9);
  
  DebugVector(res);
  return 0;
}