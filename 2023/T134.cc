#include "BaseHeader.h"

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = gas.size();

    for (int i = 0; i < total;) {
      int pos = canGotoMax(gas, cost, i);
      if (pos >= 0 && pos == i) {
        // 走了一圈
        return i;
      }
      if (pos >= 0 && pos > i) {
        // 前向走了，但是没走到头回到 0 的位置的情况
        //  说明从i开始走， 走到pos，到达不了下一站 pos+1 了，此时直接从 pos +1
        //  开始走 因为 i 到 pos 之间的站点，走到 pos 之后，肯定也是走不到 pos+1
        //  的，这需要想明白！
        i = pos + 1;
        continue;
      }
      if (pos == -1) {
        // 当前点一次都走不动，直接从下一个点尝试
        i++;
        continue;
      }
      if (pos >= 0 && pos < i) {
        // 走到头，回来0开始再走，但是又没走到起点pos，
        // 说明 pos 之后的点 (pos+n)，都不可能走一圈回到pos，更别说回到 (pos+n)
        // 了，这里也需要想明白
        return -1;
      }
    }
    return -1;
  }

  int canGotoMax(vector<int>& gas, vector<int>& cost, int index) {
    int pos = index;
    int left_gas = 0;

    while (1) {
      if (left_gas + gas[pos] > 0 && left_gas + gas[pos] >= cost[pos]) {
        left_gas = left_gas + gas[pos] - cost[pos];
        pos = (pos + 1) % gas.size();

        // 已经走动过，pos等于index，表明走了一圈
        if (pos == index) {
          // 走了一圈，则返回这个点的位置
          return pos;
        }
      } else {
        if (pos == index) {
          // 一次都没走动，pos还在原地，则返回-1来表示这种情况
          return -1;
        }
        // 走动过，但是没跑完一圈
        return pos;
      }
    }
  }
};

int main() {
  Solution sol;

  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};

  cout << sol.canCompleteCircuit(gas, cost) << endl;
  return 0;
}
