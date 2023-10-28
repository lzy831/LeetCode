#include "BaseHeader.h"

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int len = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      if ( (s[i] >= 'a' && s[i] <= 'z') || s[i] >= 'A' && s[i] <= 'Z') {
        len++;
      }
      if (s[i] == ' ' && len > 0) {
        break;
      }
    }
    return len;
  }
};

int main() {
  Solution s;
  std::string input("luffy is still joyboy ");

  cout << s.lengthOfLastWord(input) << endl;
  return 0;
}