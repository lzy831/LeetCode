#include "BaseHeader.h"

/*
思路： 就是 设置h初始值为0

然后 循环尝试 h+1 是否满足， (h个数的值 大于等于 h )， 成功就更新h=h+1,
否者返回h

核心在于如何 快速的判断是否 有 h 个数 >= h

我这边的方法比较慢，就是循环比较 同时记录满足的个数 是否大于h个

比较好一些的方法是先 排序，例如从小到大排序

排序之后，判断就比较方便了。
假设排序之后还在原数组中， 那么只需要判断  citations[size-h] >= h

含义就是, 假设h=3， c[s-3] >= h 则

 c[s-3] c[s-2] c[s-1]  这后3个数都 大于等于 h  因为是从小到大排序的

*/

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    if (citations.empty())
      return 0;

    int result = 0;
    for (int h = 1; h <= citations.size(); h++) {
      if (!test_h(citations, h)) {
        result = h - 1;
        break;
      } else {
        result = h;
      }
    }

    return result;
  }

  bool test_h(vector<int>& citations, int h) {
    int count = 0;
    for (auto i : citations) {
      if (i >= h) {
        count++;
        if (count >= h) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  // vector<int> citations = {1, 3, 1};
  // Solution s;
  // cout << s.hIndex(citations) << endl;

  vector<int> test = {4, 7, 9, 3, 2, 0, 8, 1, 7};
  DebugVector(test);
  sort(test.begin(), test.end());
  DebugVector(test);
  return 0;
}