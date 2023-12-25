#include "BaseHeader.h"

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    // 注意需要验证2个方向的映射
    return isIsomorphicOneDirection(s, t) && isIsomorphicOneDirection(t, s);
  }

  bool isIsomorphicOneDirection(string s, string t) {
    unordered_map<char, char> dict;
    for (int i = 0; i < s.size(); i++) {
      if (dict.find(s[i]) == dict.end()) {
        dict[s[i]] = t[i];
      } else {
        if (dict[s[i]] != t[i]) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution sol;

  string s = "foob";
  string t = "baad";

  cout << sol.isIsomorphic(s, t) << endl;

  return 0;
}