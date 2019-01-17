// 94. 二叉树的中序遍历
#include "BaseHeader.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  vector<int> inorderTraversal(TreeNode* root)
  {
    vector<int> res;
    stack<TreeNode*> s;

    if(!root)
    {
      return res;
    }
    s.push(root);

    while(!s.empty())
    {
      TreeNode* node = s.top();

      if(node->left)
      {
        // 左节点存在，压入stack
        s.push(node->left);
      }
      else
      {
        // 左节点不存在，遍历这个节点
        // visit this node
        res.push_back(node->val);
        s.pop();

        // 右节点存在，压入stack
        if(node->right)
        {
          s.push(node->right);
        }
      }
    }
    return res;
  }
};


int main()
{
  Solution s;
  vector<int> v = {1, 2, -1, -1, 3, 5, -1, -1, 6, -1, -1};
  queue<int> q;
  for(auto & i : v)
  {
    q.push(i);
  }

  TreeNode* root;
  CreateTree(&root, q);

  vector<int> res = s.inorderTraversal(root);
  for(auto & j : res)
  {
    cout << j << " ";
  }
  cout << endl;

  return 0;
}