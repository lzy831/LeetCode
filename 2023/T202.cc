#include "BaseHeader.h"

// 归类在 哈希表 中，但是其实仅使用一个 哈希集合 来做查重，查重的目的是看是否在计算中产生循环了

// 看官方题解，可以知道这个计算方式循环下去，不会无限循环，因为 9999 下一个是 81*4 = 324  会回到3位数，具体可以看题解

// 基础方法要会， 把给定的整数 取出每一位数字的方法， 先取 模10运算结果，再除以10 消除已经取过的位数值

class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> set;
    set.insert(n);

    while (1) {
      int m = 0;
      while (n > 0) {
        int bit = n % 10;
        m = m + (bit * bit);
        n = n / 10;
      }

      if (m == 1) {
        // 满足快乐数条件了
        return true;
      }

      if (set.find(m) != set.end()) {
        // 重复了
        return false;
      }
      set.insert(m);

      n = m;
    }

    return false;
  }
};

int main() {
  Solution sol;

  cout << sol.isHappy(19) << endl;
  return 0;
}