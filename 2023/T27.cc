#include "BaseHeader.h"




// 思路： 2个指针，前后各一个，向中间检索，把符合要求的（!=val）的值替换到前面的位置中，并记录个数
// 从前向后检索的指针，发现符合的，计数+1，指针后移，发现不符合的，停下，让后端指针向前找符合的，找到的话，替换一下，然后前向指针继续，一直到2个指针汇合
// 注意： 临界情况： 
// - 数组为空，
// - 数组不为空，全部符合，或者全部符合

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty())
      return 0;

    auto iter_begin = nums.begin();
    auto iter_end = nums.end() - 1;

    int count = 0;
    int tmp;
    while (iter_begin <= iter_end) {
      if (*iter_begin != val) {
        count++;
        iter_begin++;
        continue;
      }

      if (iter_end > iter_begin && *iter_end != val) {
        tmp = *iter_begin;
        *iter_begin = *iter_end;
        *iter_end = tmp;
        continue;
      } else {
        iter_end--;
        continue;
      }
    }

    return count;
  }
};

int main() {
  Solution solution;

  // vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  // int ret = solution.removeElement(nums, 2);

  vector<int> nums = {3, 2, 2, 3};
  int ret = solution.removeElement(nums, 3);

  printf("ret:%d\n", ret);


  DebugVector(nums);
  return 0;
}