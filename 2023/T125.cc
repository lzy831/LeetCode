#include "BaseHeader.h"

class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.empty()) {
      return true;
    }

    if (s.size() == 1 && isValidChar(s[0])) {
      return true;
    }

    int begin = 0;
    int end = s.size() - 1;

    while (end > begin) { // 这里判断条件是否可以优化？
      if (!isValidChar(s[end])) {
        end--;
        continue;
      }
      if (!isValidChar(s[begin])) {
        begin++;
        continue;
      }

      if (!isSame(s[begin], s[end])) {
        return false;
      } else {
        begin++;
        end--;
      }
    }
    return true;
  }

  bool isSame(char a, char b) {
    char la = toLittle(a);
    char lb = toLittle(b);
    return la == lb;
  }

  char toLittle(char c) {
    if ((c >= 'A' && c <= 'Z')) {
      return c + ('a' - 'A') /*这个数值是32，并不是26，而且是小写字母数值大，可以记一下*/;
    }
    return c;
  }

  // 这里要注意，数字和字母 都是有效字符
  bool isValidChar(char c) {
    if ((c >= 'A' && c <= 'Z') ||  //
        (c >= 'a' && c <= 'z') ||  //
        (c >= '0' && c <= '9')) {
      return true;
    }
    return false;
  }
};

int main() {
  Solution sol;

  // string s = "A man, a plan, a canal: Panama";
  //   cout << sol.isPalindrome(s) << endl;

  string s1 = "0P";
  cout << sol.isPalindrome(s1) << endl;

  return 0;
}