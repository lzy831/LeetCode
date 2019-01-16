// 合并两个有序数组
// 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
// 说明:
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
// 示例:
// 输入:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3
// 输出: [1,2,2,3,5,6]
#include "BaseHeader.hpp"

class Solution
{
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
  {

    int i = m - 1;
    int j = n - 1;
    int p = n + m - 1;

    while(i >= 0 && j >= 0)
    {
      if(nums1[i] > nums2[j])
      {
        nums1[p] = nums1[i];
        i--;
      }
      else
      {
        nums1[p] = nums2[j];
        j--;
      }
      p--;
    }
    while(j >= 0)
    {
      nums1[p] = nums2[j];
      j--;
      p--;
    }
  }
};

int main(int argc, char const* argv[])
{
  Solution s;


  {
    vector<int> v1 = {1, 2, 3, 0, 0, 0};
    vector<int> v2 = {2, 5, 6};

    s.merge(v1, 3, v2, 3);
    DebugVector(v1);
  }


  {
    vector<int> v1 = {4, 5, 6, 0, 0, 0};
    vector<int> v2 = {1, 2, 3};

    s.merge(v1, 3, v2, 3);
    DebugVector(v1);
  }

  {
    vector<int> v1 = {2, 4, 6, 0, 0, 0};
    vector<int> v2 = {1, 3, 5};

    s.merge(v1, 3, v2, 3);
    DebugVector(v1);
  }
  return 0;
}