#include "BaseHeader.h"


// 由于哈希查找的时间复杂度为 O(1)O(1)O(1)，所以可以利用哈希容器 map 降低时间复杂度
// 遍历数组 nums，i 为当前下标，每个值都判断map中是否存在 target-nums[i] 的 key 值
// 如果存在则找到了两个值，如果不存在则将当前的 (nums[i],i) 存入 map 中，继续遍历直到找到为止

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      if (map.count(target - nums[i]) != 0) {
        result.push_back(map[target - nums[i]]);
        result.push_back(i);
      } else {
        map[nums[i]] = i;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {7, 11, 15, 2};
  int target = 9;

  auto res = sol.twoSum(nums, target);
  cout << res[0] << " " << res[1] << endl;

  return 0;
}