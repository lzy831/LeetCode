#include "BaseHeader.h"

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    return findPeak(nums, 0, nums.size() - 1);
  }

  int findPeak(vector<int>& nums, int l, int r) {
    if (l == r) {
      return l;
    }

    if (r == l + 1) {
      if (nums[l] > nums[r]) {
        return l;
      } else {
        return r;
      }
    }

    int m = (l + r) / 2;
    if (GetInxValue(nums, m) > GetInxValue(nums, m - 1) &&
        GetInxValue(nums, m) > GetInxValue(nums, m + 1)) {
      return m;
    } else if (GetInxValue(nums, m) > GetInxValue(nums, m + 1)) {
      return findPeak(nums, l, m);
    } else {
      return findPeak(nums, m, r);
    }
  }

  int GetInxValue(vector<int>& nums, int idx) {
    if (idx < 0) {
      return -1;
    } else if (idx == nums.size()) {
      return -1;
    } else {
      return nums[idx];
    }
  }
};

int main() {
  Solution sol;

  vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

  cout << sol.findPeakElement(nums) << endl;

  return 0;
}