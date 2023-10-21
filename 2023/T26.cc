#include "BaseHeader.h"

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