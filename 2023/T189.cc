#include "BaseHeader.h"

// 直接搞，空间复杂度O(1),但是会超时
// class Solution {
//  public:
//   void rotate(vector<int>& nums, int k) {
//     k = k % nums.size();

//     while (--k >= 0)
//       rotate_one(nums);

//     return;
//   }

//   void rotate_one(vector<int>& nums) {
//     int tmp = nums[0];
//     int j = 0;

//     for (int i = nums.size() - 1; i > 0; i--) {
//       nums[(i + 1) % nums.size()] = nums[i];
//     }
//     nums[1] = tmp;
//   }
// };

// 使用额外的空间
// class Solution {
//  public:
//   void rotate(vector<int>& nums, int k) {
//     k = k % nums.size();

//     vector<int> tmp(nums.size());

//     for (int i = 0; i < nums.size(); i++) {
//       int p = (i + k) % (nums.size());
//       tmp[p] = nums[i];
//     }

//     for (int i = 0; i < nums.size(); i++) {
//       nums[i] = tmp[i];
//     }

//     return;
//   }
// };

//
//   --------------- 比较难想， 翻转 再 翻转
// 稍微理解一下，
// 右移动k次，就会导致后k个数到前面，前面n-k个数到后面，位置上是这样，但是顺序是翻转的
// 0 1 2 3 4 5 6 7    k=3
//
// 7 6 5    4 3 2 1 0
// 5 6 7    0 1 2 3 4
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();

    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);

    return;
  }

  void reverse(vector<int>& nums, int start, int end) {
    if (end - start < 1) {
      return;
    }

    int tmp;
    while (start < end) {
      tmp = nums[start];
      nums[start] = nums[end];
      nums[end] = tmp;
      start++;
      end--;
    }
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

  Solution s;

  s.rotate(nums, 3);

  DebugVector(nums);
  return 0;
}