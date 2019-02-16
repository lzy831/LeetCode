// 48. 旋转图像
// 给定一个 n × n 的二维矩阵表示一个图像。
// 将图像顺时针旋转 90 度。
// 说明：
// 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

// 示例 1:
// 给定 matrix =
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],
// 原地旋转输入矩阵，使其变为:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]

// 示例 2:
// 给定 matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ],
// 原地旋转输入矩阵，使其变为:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]
#include "BaseHeader.hpp"

class Solution
{
public:
  void rotate(vector<vector<int>>& matrix)
  {
    if (matrix.size() < 2) {
      return ;
    }

    int len = matrix.size();

    // 沿着左上到右下的轴 对调一次位置
    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
      }
    }

    // 沿着 纵轴 对调一次
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len / 2; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[i][len - j - 1];
        matrix[i][len - j - 1] = tmp;
      }
    }
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  vector<vector<int>> v = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
  };

  for (auto& i : v) {
    DebugVector(i);
  }

  s.rotate(v);

  for (auto& i : v) {
    DebugVector(i);
  }

  return 0;
}