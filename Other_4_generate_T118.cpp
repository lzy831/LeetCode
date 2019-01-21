// 帕斯卡三角形
// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
// 在杨辉三角中，每个数是它左上方和右上方的数的和。
// 示例:
// 输入: 5
// 输出:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
#include "BaseHeader.hpp"

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> res;

    if(numRows==0)
    {
      return res;
    }
    
    for(int i = 0; i < numRows; i++)
    {
      vector<int> row;
      res.push_back(row);
    }

    res[0].push_back(1);
    if(numRows == 1)
    {
      return res;
    }

    for(int i = 1; i < numRows; i++)
    {
      for(int j = 0; j < res[i - 1].size(); j++)
      {
        if(j == 0)
        {
          res[i].push_back(1);
        }

        if(j > 0)
        {
          res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
        }

        if(j == res[i - 1].size() - 1)
        {
          res[i].push_back(1);
        }
      }
    }

    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  vector<vector<int>> res = s.generate(5);
  for(auto & i : res)
  {
    DebugVector(i);
  }
  return 0;
}