#ifndef __BASE_TREE_HPP__
#define __BASE_TREE_HPP__
#include <queue>
#include <iostream>

using namespace std;

#define IVAILED_NODE_VAL (-1)


// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};





void CreateTree(TreeNode** root, queue<int>& nodelist)
{
  if(nodelist.size())
  {
    int val = nodelist.front();
    nodelist.pop();

    if(val != IVAILED_NODE_VAL)
    {
      *root = new TreeNode(val);
      CreateTree(&((*root)->left), nodelist);
      CreateTree(&((*root)->right), nodelist);
    }
  }
}


// 递归前序
void TraverseTreePreorder(TreeNode* root, queue<int>& travlist)
{
  if(root)
  {
    travlist.push(root->val);
    TraverseTreePreorder(root->left, travlist);
    TraverseTreePreorder(root->right, travlist);
  }
  else
  {
    travlist.push(-1);
  }

}

// 递归中序
void TraverseTreeInorder(TreeNode* root, queue<int>& travlist)
{
  if(root)
  {
    TraverseTreeInorder(root->left, travlist);
    travlist.push(root->val);
    TraverseTreeInorder(root->right, travlist);
  }
  else
  {
    travlist.push(-1);
  }
}




void TestTreeFunction()
{
  vector<int> v = {1, 2, -1, -1, 3, 5, -1, -1, 6, -1, -1};
  queue<int> q;
  for(auto & i : v)
  {
    q.push(i);
  }

  TreeNode* root;
  CreateTree(&root, q);

  {
    queue<int> travlist;
    TraverseTreePreorder(root, travlist);
    while(travlist.size())
    {
      cout << travlist.front() << " ";
      travlist.pop();
    }
    cout << endl;
  }

  {
    queue<int> travlist;
    TraverseTreeInorder(root, travlist);
    while(travlist.size())
    {
      cout << travlist.front() << " ";
      travlist.pop();
    }
    cout << endl;
  }
}






// void TraverseTreeInLevel(TreeNode* root)
// {
//   queue<TreeNode*> helper;

//   if(!root)
//   {
//     return;
//   }
//   helper.push(root);

//   while(!helper.empty())
//   {
//     TreeNode* cur = helper.front();
//     helper.pop();
//     cout


//     if(cur->left){
//       helper.push(root->left->val);
//     }
//   }
// }


#endif