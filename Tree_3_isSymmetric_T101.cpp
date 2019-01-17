// 对称二叉树
// 给定一个二叉树，检查它是否是镜像对称的。

// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

//     1
//    / \
//   2   2
//    \   \
//    3    3
// 说明:

// 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
#include "BaseHeader.hpp"


class Solution
{
public:
  bool isSymmetric(TreeNode* root)
  {
    if(root == nullptr)
    {
      return true;
    }
    return isMirror(root->left, root->right);
  }
  bool isMirror(TreeNode* r1, TreeNode* r2)
  {
    if(r1 != nullptr && r2 != nullptr && r1->val == r2->val)
    {
      return isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
    }
    if(r1 == nullptr && r2 == nullptr)
    {
      return true;
    }
    return false;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    TreeNode* root;
    vector<int> v = {1, 2, 3, -1, -1, 4, -1, -1, 2, 4, -1, -1, 3, -1, -1};
    CreateTree(&root, v);
    TraverseTreePreorder(root);
    TraverseTreeInorder(root);

    cout << s.isSymmetric(root) << endl;
  }

  {
    TreeNode* root;
    vector<int> v = {1, 2, -1, 3, -1, -1, 2, -1, 3, -1, -1};
    CreateTree(&root, v);
    cout << s.isSymmetric(root) << endl;
  }
  return 0;
}