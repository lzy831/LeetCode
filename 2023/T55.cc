#include "BaseHeader.h"

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {

    if (nums.size() < 2)
      return true;

    return canJumpTo(nums, nums.size() - 1);
  }

  // return whether 'pos 0' can jump to 'pos target'
  bool canJumpTo(vector<int> &nums, int target)
  {
    for (int i = target - 1; i >= 0; i--)
    {
      if (nums[i] >= target - i)
      {
        if (i == 0)
          return true;
        else
          return canJumpTo(nums, i);
      }
    }
    return false;
  }
};

int main()
{
  // vector<int> nums = {2, 3, 1, 1, 4};
  vector<int> nums = {3, 2, 1, 0, 4};

  Solution s;
  int ret = s.canJump(nums);
  printf("ret: %d\n", ret);
  return 0;
}