// 将有序数组转换为二叉搜索树
// 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
// 示例:
// 给定有序数组: [-10,-3,0,5,9],
// 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
#include "BaseHeader.hpp"

class Solution
{
public:
  TreeNode* sortedArrayToBST(vector<int>& nums)
  {
    if(nums.empty())
    {
      return nullptr;
    }
    return CreateTreeByArray(nums, 0, nums.size() - 1);
  }
  TreeNode* CreateTreeByArray(vector<int>& nums, int begin, int end)
  {
    if(begin == end)
    {
      return new TreeNode(nums[begin]);
    }

    int mid = (begin + end) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    if(mid > begin)
    {
      node->left = CreateTreeByArray(nums, begin, mid - 1);
    }
    if(mid < end)
    {
      node->right = CreateTreeByArray(nums, mid + 1, end);
    }

    return node;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    vector<int> v = { -10, -3, 0, 5, 9};
    TreeNode* root = s.sortedArrayToBST(v);
    TraverseTreePreorder(root);
    TraverseTreeInorder(root);
  }

  {
    vector<int> v;
    TreeNode* root = s.sortedArrayToBST(v);
    TraverseTreePreorder(root);
    TraverseTreeInorder(root);
  }

  {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode* root = s.sortedArrayToBST(v);
    TraverseTreePreorder(root);
    TraverseTreeInorder(root);
  }

  return 0;
}