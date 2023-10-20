#include "BaseHeader.h"

// 合并2个有序数组

// 基础思路： 插入之后的数组大小是确定的，所以就可以从后向前处理
class Solution1 {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p3 = m + n - 1;
    while (p3 >= 0) {
      if (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] >= nums2[p2]) {
          nums1[p3] = nums1[p1];
          p1--;
        } else {
          nums1[p3] = nums2[p2];
          p2--;
        }
      } else if (p1 >= 0) {
        nums1[p3] = nums1[p1];
        p1--;
      } else if (p2 >= 0) {
        nums1[p3] = nums2[p2];
        p2--;
      }
      p3--;
    }
  }
};

// 优化：因为第一个本来是有序的，所以第二数组元素插入完，就可以结束了，第一个数组前面部分不需要动了
class Solution2 {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p3 = m + n - 1;
    while (p3 >= 0) {
      if (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] >= nums2[p2]) {
          nums1[p3] = nums1[p1];
          p1--;
        } else {
          nums1[p3] = nums2[p2];
          p2--;
        }
      } else if (p1 >= 0) {
        nums1[p3] = nums1[p1];
        p1--;
      } else if (p2 >= 0) {
        nums1[p3] = nums2[p2];
        p2--;
      }
      if (p2 < 0) {
        // 第二个插入玩，直接结束
        break;
      }
      p3--;
    }
  }
};

int main() {
  Solution1 solution;

  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};

  solution.merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
  DebugVector(nums1);
  return 0;
}