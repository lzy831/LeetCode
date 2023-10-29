#include "BaseHeader.h"

/*
应该属于动态规划类

依次求解到达当前位置所需要跳跃的最小次数，并记录在一个数组中 如 minTo[]

minTo[0] = 0 // 这个是初始值

之后依次求解， 例如求到达 n 位置的最小跳跃次数
minTo[n] = min( minTo( M) ) +1

其中，M 是一个集合，里面的元素是，n位置之前可以通过一次跳跃 到达n位置的 位置下标

也就是说，我们找到所有能一次跳到当前位置的位置集合，然后在里面找到，从开始到达那个位置所需次数最少的位置，记录位m
（这个很找，因为这个就是 minTo[] 记录的值）

然后这个值 加1，表示从那个位置到n位置，还要再跳一次
*/

class Solution {
 public:
  int jump(vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    }

    vector<int> minTo(nums.size());
    minTo[0] = 0;

    int min;
    int i;
    for (i = 1; i < nums.size(); i++) {
      min = findMinStepTo(nums, minTo, i);
      if (min > 0) {
        minTo[i] = min;
      }
    }
    return minTo[i - 1];
  }

  int findMinStepTo(vector<int>& nums, vector<int>& minTo, int pos) {
    int minToPrev = nums.size();
    for (int i = pos - 1; i >= 0; i--) {
      if (canJumoTo(nums, i, pos) && minTo[i] < minToPrev) {
        minToPrev = minTo[i];
      }
    }
    return minToPrev + 1;
  }

  bool canJumoTo(vector<int>& nums, int i, int pos) {
    return nums[i] >= (pos - i);
  }
};

int main() {
  Solution s;
  vector<int> nums = {2,3,1,1,4};
  cout << s.jump(nums) << endl;
  return 0;
}