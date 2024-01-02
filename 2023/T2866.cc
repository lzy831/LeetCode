#include "BaseHeader.h"

#if 0
// 基础方法 O(n2) 会超时
class Solution {
 public:
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    long long max = 0;
    //
    for (int i = 0; i < maxHeights.size(); i++) {
      long long m = maximumOfHeightsAtIndexAsTop(maxHeights, i);
      max = max > m ? max : m;
    }
    //
    //
    return max;
  }

  long long maximumOfHeightsAtIndexAsTop(vector<int>& maxHeights, int cur) {
    long long total = 0;

    // 当前点作为塔顶，记录总数值，并标记为最高值
    total += maxHeights[cur];

    int left_max = maxHeights[cur];
    for (int i = cur - 1; i >= 0; i--) {
      // 当前点的塔高度，不能高于之前的最高值
      int use_height = maxHeights[i] > left_max ? left_max : maxHeights[i];
      // 选取好高度，计入总数
      total += use_height;
      // 更新左侧后续塔可用的最高值
      left_max = use_height;
    }

    int right_max = maxHeights[cur];
    for (int i = cur + 1; i < maxHeights.size(); i++) {
      int use_height = maxHeights[i] > right_max ? right_max : maxHeights[i];
      total += use_height;
      right_max = use_height;
    }

    return total;
  }
};
#else
class Solution {
 public:
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    long long max = 0;

    vector<long long> prefix(maxHeights.size());
    vector<long long> suffix(maxHeights.size());

    for (int i = 0; i < maxHeights.size(); i++) {
      if (i == 0) {
        prefix[i] = maxHeights[i];
      } else {
        int j = i - 1;
        while (j >= 0 && maxHeights[j] >= maxHeights[i]) {
          j--;
        }
        if (j >= 0) {
          prefix[i] = (long long)maxHeights[i] * (i - j) + prefix[j];
        } else {
          //
          //  我擦，这里一定要注意 如果不先转型为 long long
          //  在做乘法，如果数值过大会直接越界， 按照 int 去乘的话，
          // 结果会临时保存在int类型空间里，之后再赋值给 long long
          //
          //
          prefix[i] = (long long)maxHeights[i] * (i + 1);
        }
      }
    }

    for (int i = maxHeights.size() - 1; i >= 0; i--) {
      if (i == maxHeights.size() - 1) {
        suffix[i] = maxHeights[i];
      } else {
        int j = i + 1;
        while (j < maxHeights.size() && maxHeights[j] >= maxHeights[i]) {
          j++;
        }
        if (j < maxHeights.size()) {
          suffix[i] = (long long)maxHeights[i] * (j - i) + suffix[j];
        } else {
          suffix[i] = (long long)maxHeights[i] * (maxHeights.size() - i);
        }
      }

      long long m = (prefix[i] + suffix[i] - maxHeights[i]);
      max = m > max ? m : max;
    }

    return max;
  }
};
#endif

int main() {
  Solution sol;

  vector<int> maxHeights0 = {1000000000, 1000000000, 1000000000};
  cout << sol.maximumSumOfHeights(maxHeights0) << endl;

  vector<int> maxHeights1 = {6, 5, 3, 9, 2, 7};
  cout << sol.maximumSumOfHeights(maxHeights1) << endl;

  vector<int> maxHeights2 = {5, 3, 4, 1, 1};
  cout << sol.maximumSumOfHeights(maxHeights2) << endl;

  vector<int> maxHeights3 = {3, 2, 5, 5, 2, 3};
  cout << sol.maximumSumOfHeights(maxHeights3) << endl;
  return 0;
}