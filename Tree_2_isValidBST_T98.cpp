// 验证二叉搜索树
// 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

// 假设一个二叉搜索树具有如下特征：

// 节点的左子树只包含小于当前节点的数。
// 节点的右子树只包含大于当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。
// 示例 1:

// 输入:
//     2
//    / \
//   1   3
// 输出: true
// 示例 2:

// 输入:
//     5
//    / \
//   1   4
//      / \
//     3   6
// 输出: false
// 解释: 输入为: [5,1,4,null,null,3,6]。
//      根节点的值为 5 ，但是其右子节点值为 4 。
#include "BaseHeader.hpp"

class Solution
{
public:
  bool isValidBST(TreeNode* root)
  {
    // return isValidBST(root, LONG_MIN, LONG_MAX);
    return isValidBST(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
  }

  bool isValidBST(TreeNode* root, long min, long max)
  {
    if(root == nullptr)
    {
      return true;
    }
    if(root->val >= min && root->val <= max)
    {
      return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
    else
    {
      return false;
    }
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    TreeNode* root;
    vector<int> v = {2, 1, -1, -1, 3, -1, -1};
    CreateTree(&root, v);
    cout << s.isValidBST(root) << endl;
  }

  {
    TreeNode* root;
    vector<int> v = {5, 1, -1, -1, 4, 3, -1, -1, 6, -1, -1};
    CreateTree(&root, v);
    cout << s.isValidBST(root) << endl;
  }


  // cout << sizeof(int) << " " << std::numeric_limits<int>::max() << endl;
  // cout << sizeof(long) << " " << std::numeric_limits<long>::max() << endl;
  // cout << sizeof(long long) << " " << std::numeric_limits<long long>::max() << endl;
  return 0;
}