#include "BaseHeader.h"

// 思路： 2个指针，指针A 记录正向第一个不重复的最大值位置， 指针B为主遍历指针，轮询时如果发现有比当前指针A值大的，就把A+1赋值为这个大的值
// 主要是注意指针移动和处理的细节步骤上

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty())
      return 0;

    auto it1 = nums.begin();
    auto it2 = it1 + 1;

    while (it2 != nums.end()) {
      if (*it2 > *it1) {
        it1++;
        if (it1 < it2) {
          *it1 = *it2;
        }
      }
      it2++;
    }
    return (it1 - nums.begin()) + 1;
  }
};

int main() {
  vector<int> nums = {1, 2, 2, 3};
  Solution s;
  int ret = s.removeDuplicates(nums);
  printf("ret: %d\n", ret);
  DebugVector(nums);
  return 0;
}