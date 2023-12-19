#include "BaseHeader.h"

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
      /* ！！！！ 这里一定要注意 & 运算符的优先级 没有 != 优先级高 ！！！！
       * 需要加括号*/
      if ((n & (1 << i)) != 0) {
        result++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  uint32_t n = 0b00000000000000000000000000001011;
  cout << sol.hammingWeight(n) << endl;
  return 0;
}