#include "BaseHeader.h"

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // first:  nums 中的一个数值
    // second: 所有等于这个数值的下标中最大的一个 下标值
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      if (map.count(nums[i]) == 0) {
        // 插入该数值，当前下标即为最大下标
        map[nums[i]] = i;
      } else {
        // 找到一个相同的数值
        if (i - map[nums[i]] <= k) {
          // 位置插值小于k，满足条件
          return true;
        }
        // 不满足，则更新该数值的最大下标
        if (map[nums[i]] < i) {
          map[nums[i]] = i;
        }
      }
    }

    return false;
  }
};

int main() {
  Solution sol;

  vector<int> nums = {1, 2, 3, 4, 1};
  int k = 4;

  cout << sol.containsNearbyDuplicate(nums, k) << endl;
  return 0;
}
