#include "BaseHeader.h"
class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty() || haystack.empty()) {
      return -1;
    }

    int i;
    for (int cur = 0; cur + needle.size() <= haystack.size(); cur++) {
      for (i = 0; i < needle.size(); i++) {
        if (haystack[cur + i] != needle[i]) {
          break;
        }
      }
      if (i == needle.size()) {
        return cur;
      }
    }
    return -1;
  }
};

int main() {
  string haystack = "1111s1adbuts1ad";
  string needle = "sad";

  Solution s;
  cout << s.strStr(haystack, needle) << endl;

  return 0;
}