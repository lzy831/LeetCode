#include "BaseHeader.h"

/*
思路: 
正常来说 左边的标记值 都是大于右侧的，比如 V > I , X > V  也就是 5>1  10>5
当出现 1在5前面，或者5在10前面的时候，说明这个在前面的值，是需要减去的

这题编码简单，主要问题是能分析出上面的这个逻辑 !!!   难点在分析规律
*/

class Solution {
  unordered_map<char, int> symbol = {
      {'I', 1},     //
      {'V', 5},     //
      {'X', 10},    //
      {'L', 50},    //
      {'C', 100},   //
      {'D', 500},   //
      {'M', 1000},  //
  };

 public:
  int romanToInt(string s) {
    int acc = 0;
    for (int i = 0; i < s.length(); i++) {
      if (i == s.length() - 1 || symbol[s[i]] >= symbol[s[i + 1]]) {
        acc += symbol[s[i]];
      } else {
        acc -= symbol[s[i]];
      }
    }
    return acc;
  }
};

int main() {
  Solution sol;
  std::string s("LVIII");
  cout << sol.romanToInt(s) << endl;
  return 0;
}