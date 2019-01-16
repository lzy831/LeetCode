// 9. 回文数
#include "BaseHeader.hpp"


class Solution
{
public:
  bool isPalindrome(int x)
  {
    int a = 0;
    int b = x;
    int reverse = 0;

    if(x < 0) {
      return false;
    }

    while(b) {
      a = b % 10;
      b = b / 10;
      reverse = reverse * 10 + a;
    }

    // cout << reverse << endl;

    return reverse == x;
  }
};

int main()
{
  Solution s;
  cout << s.isPalindrome(0) << endl;
  return 0;
}