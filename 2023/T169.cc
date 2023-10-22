#include "BaseHeader.h"

// 思路1: 排序取 n/2 位置的值，但是排序必须时间复杂度足够低
// 思路2：同归于尽 大法，碰撞消除，最后的幸存者就是 众数

class Solution {
 public:
  int majorityElement(vector<int>& nums) {

    int winner;
    int count = 0;

    for (auto it : nums) {
      if (count == 0) {
        winner = it;
        count = 1;
        continue;
      }

      if (winner == it) {
        count++;
      } else {
        count--;
      }
    }
    return winner;
  }
};

int main() {
  vector<int> nums = {1, 2, 2, 2, 4, 3, 8, 2, 2};

  Solution s;
  int ret = s.majorityElement(nums);
  printf("ret: %d\n", ret);

  DebugVector(nums);
  return 0;
}