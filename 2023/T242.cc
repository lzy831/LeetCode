#include "BaseHeader.h"

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++) {
      if (map.count(s[i]) == 0) {
        map[s[i]] = 1;
      } else {
        map[s[i]]++;
      }
    }

    for (int i = 0; i < t.size(); i++) {
      if (map.count(t[i]) != 0) {
        if (map[t[i]] > 0) {
          map[t[i]]--;
        }
        if (map[t[i]] == 0) {
          map.erase(t[i]);
        }
      } else {
        return false;
      }
    }

    return map.empty();
  }
};

int main() {
  Solution sol;

  string s = "anagram";
  string t = "nagaram";

  cout << sol.isAnagram(s, t) << endl;
  return 0;
}