#include "BaseHeader.h"



// 从初始价格开始看，min=max=n[0]，然后有几种情况
// 1. 一直涨，min不变，max一直增加，到结束日，maxP = max-min
// 2. 一直跌，max和min一起减，因为max记录的是从之前某个低点开始算起的当前高点，要么是标识盈利区间，要么就和min一样，标识不盈利
// 3. 先跌后涨，min，max下降后，max增加，到下次下降或者结束，需要还止盈，maxP += max-min， 如果还未结束则，min=max=cur 重新开始
// 4. 先张后跌，min不表，max涨，再到跌的时间止盈， maxP += max-min，之后继续
//  总之，2个标记min 和 max 就用来记录 盈利区间， 找个实例数组，画一画几种情况，理一下就懂了
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
      return 0;
    }
    int maxP = 0;

    int curMin;  // 之前低点
    int curMax;  // 之前高点
    curMin = curMax = prices[0];
    int cur;

    for (int i = 1; i < prices.size(); i++) {
      cur = prices[i];

      if (cur > curMax) {  // 价格继续拉升
        curMax = cur;      // min不动，max更新，此时已经有盈利
      } else {
        // 价格下降了，
        if (curMax > curMin) {        // 已经有盈利，需要止盈
          maxP += (curMax - curMin);  // 止盈
          curMin = curMax = cur;      // 止盈后 重新标记低点
        } else {                      // 没有盈利
          curMin = curMax = cur;
        }
      }
    }
    if (curMax > curMin) {
      maxP += (curMax - curMin);
    }
    return maxP;
  }
};

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  Solution s;
  int ret = s.maxProfit(prices);
  printf("ret: %d\n");
  return 0;
}