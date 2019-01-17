
// 二叉树的最大深度
// 给定一个二叉树，找出其最大深度。

// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

// 说明: 叶子节点是指没有子节点的节点。

// 示例：
// 给定二叉树 [3,9,20,null,null,15,7]，

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最大深度 3 。

#include "BaseHeader.hpp"

class Solution
{
public:
  int maxDepth(TreeNode* root)
  {
    if(root == nullptr)
    {
      return 0;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    TreeNode* root;
    vector<int> v = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    CreateTree(&root, v);
    cout << s.maxDepth(root) << endl;
  }


  {
    TreeNode* root;
    vector<int> v = {3, 9, -1, -1, 20, 15, -1, -1, 7, 6, -1, -1, -1};
    CreateTree(&root, v);
    cout << s.maxDepth(root) << endl;
  }



  return 0;
}