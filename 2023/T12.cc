#include "BaseHeader.h"

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
  string intToRoman(int num) {
    string result("");

    int n = num / 1000;  // N 个 千
    while (n-- > 0) {
      result.append("M");
    }

    n = num / 100 % 10;  // 百位 数值

    if (n == 9) {
      result.append("CM");
    } else if (n >= 5) {
      result.append("D");
      int m = n - 5;
      while (m-- > 0) {
        result.append("C");
      }
    } else if (n == 4) {
      result.append("CD");
    } else {
      while (n-- > 0) {
        result.append("C");
      }
    }

    n = num / 10 % 10;  //  十位 数值
    if (n == 9) {
      result.append("XC");
    } else if (n >= 5) {
      result.append("L");
      int m = n - 5;
      while (m-- > 0) {
        result.append("X");
      }
    } else if (n == 4) {
      result.append("XL");
    } else {
      while (n-- > 0) {
        result.append("X");
      }
    }

    n = num % 10;  //  个位 数值
    if (n == 9) {
      result.append("IX");
    } else if (n >= 5) {
      result.append("V");
      int m = n - 5;
      while (m-- > 0) {
        result.append("I");
      }
    } else if (n == 4) {
      result.append("IV");
    } else {
      while (n-- > 0) {
        result.append("I");
      }
    }

    return result;
  }
};

int main() {
  Solution sol;
  cout << sol.intToRoman(1994) << endl;

  return 0;
}