#include "BaseHeader.h"

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
      return 0;
    }

    int min = prices[0];
    int maxP = 0;

    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] - min > maxP) {
        maxP = prices[i] - min;
      }
      if (prices[i] < min) {
        min = prices[i];
      }
    }
    return maxP;
  }
};

int main() {
  vector<int> p = {1, 2};

  Solution s;
  s.maxProfit(p);
  printf("maxP: %d\n", s.maxProfit(p));
  return 0;
}