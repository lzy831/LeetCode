#include "BaseHeader.h"

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return string("");
    }
    if (strs.size() == 1) {
      return strs[0];
    }
    if (strs[0].empty()) {
      return string("");
    }

    for (int i = 0; i < strs[0].size(); i++) {
      for (int j = 1; j < strs.size(); j++) {
        if (strs[j].size() < (i + 1) || strs[j][i] != strs[0][i]) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0];
  }
};

int main() {
  // vector<string> strs = {"flower", "flow", "flight"};
  vector<string> strs = {};
  Solution s;
  cout << s.longestCommonPrefix(strs) << endl;
  return 0;
}