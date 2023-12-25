#include "BaseHeader.h"

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    if (s.empty())
      return true;
    if (t.empty()) {
      return false;
    }

    int cp = 0;

    for (int i = 0; i < t.size(); i++) {
      if (t[i] == s[cp]) {
        cp++;
        if (cp == s.size()) {
          return true;
        }
        continue;
      }
    }
    return false;
  }

};

int main() {
  Solution sol;

  string t = "ahbgdc";
  string s = "axc";

  cout << sol.isSubsequence(s, t) << endl;
  return 0;
}