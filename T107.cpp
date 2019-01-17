// 107. 二叉树的层次遍历 II
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
  vector<vector<int>> levelOrderBottom(TreeNode* root)
  {
    vector<vector<int>> res;
    queue<TreeNode*> q1;

    if(!root)
    {
      return res;
    }
    q1.push(root);

    while(!q1.empty())
    {
      queue<TreeNode*> q2;
      vector<int> sub;
      while(!q1.empty())
      {
        TreeNode* node = q1.front();
        q1.pop();

        sub.push_back(node->val);
        q2.push(node);
      }

      while(!q2.empty())
      {
        TreeNode* node = q2.front();
        q2.pop();

        if(node->left)
        {
          q1.push(node->left);
        }
        if(node->right)
        {
          q1.push(node->right);
        }
      }
      res.push_back(sub);
    }
    std::reverse(std::begin(res),std::end(res));
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

  vector<vector<int>> res = s.levelOrderBottom(root);
  for(auto& i:res)
  {
    for(auto& j:i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}