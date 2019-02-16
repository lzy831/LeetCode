// 59. 螺旋矩阵 II
// 题目描述
// 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

// 示例:
// 输入: 3
// 输出:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]


#include "BaseHeader.hpp"

class Solution
{
public:
  typedef enum {
    GO_RIGHT = 0,
    GO_DOWN = 1,
    GO_LEFT = 2,
    GO_UP = 3,
    GO_TOTAL,
  } Direction;

#define DEFAULT_VAL (-1)

  vector<vector<int>> generateMatrix(int n)
  {
    vector<vector<int>> res;
    for (size_t i = 0; i < n; i++) {
      vector<int> v;
      for (int j = 0; j < n; j++) {
        v.push_back(DEFAULT_VAL);
      }
      res.push_back(v);
    }

    int direction = GO_RIGHT;
    int val = 1;
    int x = 0;
    int y = 0;
    while (val <= n * n) {
      if (x < n && x >= 0 && y < n && y >= 0 && res[x][y] == DEFAULT_VAL) {
        res[x][y] = val++;
        switch (direction) {
        case GO_RIGHT:
          y++;
          break;
        case GO_DOWN:
          x++;
          break;
        case GO_LEFT:
          y--;
          break;
        case GO_UP:
          x--;
          break;
        default:
          break;
        }
      } else {
        switch (direction) {
        case GO_RIGHT:
          y--;
          x++;
          break;
        case GO_DOWN:
          x--;
          y--;
          break;
        case GO_LEFT:
          y++;
          x--;
          break;
        case GO_UP:
          x++;
          y++;
          break;
        default:
          break;
        }
        direction = (direction + 1) % GO_TOTAL;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    int n = 3;
    Solution s;
    vector<vector<int>> res = s.generateMatrix(n);
    for (size_t i = 0; i < n; i++) {
      DebugVector(res[i]);
    }
  }
  {
    int n = 4;
    Solution s;
    vector<vector<int>> res = s.generateMatrix(n);
    for (size_t i = 0; i < n; i++) {
      DebugVector(res[i]);
    }
  }
  {
    int n = 5;
    Solution s;
    vector<vector<int>> res = s.generateMatrix(n);
    for (size_t i = 0; i < n; i++) {
      DebugVector(res[i]);
    }
  }
  return 0;
}