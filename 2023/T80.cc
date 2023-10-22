#include "BaseHeader.h"

// 思路： 2个指针，指针A 记录后续数值向前插入的问题，指针B 进行轮询

// 先找到第一个插入点，之后每次插入后，插入点后移一位

// 第一个插入点的条件：
// 首先从 nums[2] 开始找，因为如果只有2个数，怎么样都是满足的，直接返回
// 如果 nums[A] 和 nums[A-1]不同，A后移，继续判定
// 如果 nums[A] 和 nums[A-1]相同，则继续看  nums[A] 和 nums[A-2] (这里check下
// A-2 是否存在) 如果相同，停下（因为再后移，就会出现3个连续相同的数值）
// 如果不同，A继续后移，继续判定（因为2个连续相同的可以，要看后一个是什么值）

// 指针B的值，是否需要放入插入点的条件
// 插入判定，是使用 nums[B] 和 nums[A-1]比较，因为
// nums[A-1]位置是确定保留的数值，numsp[A]是可以插入的位置 如果 nums[B] 和
// nums[A-1] 不同，直接插入，A++，B++ 如果 nums[B] 和  nums[A-1] 相同，继续比较
// nums[B] 和  nums[A-2] (这里check下 A-2 是否存在)
// 如果相同，不能继续插入，A不动, B++
// 如果不同，插入 nums[A] = nums[B], A++, B++

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) {
      return nums.size();
    }

    auto it1 = nums.begin() + 2;
    while (it1 != nums.end()) {
      if (*it1 != *(it1 - 1)) {
        it1++;
      } else {
        if (it1 - nums.begin() > 1) {
          if (*it1 != *(it1 - 2)) {
            it1++;
          } else {
            break;
          }
        } else {
          it1++;
        }
      }
    }

    if (it1 != nums.end()) {
      auto it2 = it1 + 1;
      while (it2 != nums.end()) {
        if (*it2 != *(it1 - 1) || (*it2 == *(it1 - 1) && *it2 != *(it1 - 2))) {
          *it1 = *it2;
          it1++;
        }
        it2++;
      }
    }

    return it1 - nums.begin();
  }
};

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  Solution s;
  int ret = s.removeDuplicates(nums);
  printf("ret: %d\n", ret);
  DebugVector(nums);
  return 0;
}