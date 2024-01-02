#include "BaseHeader.h"

class Solution {
 public:
  bool isAcronym(vector<string>& words, string s) {
    if (words.size() != s.size()) {
      return false;
    }

    for (int i = 0; i < words.size(); i++) {
      if (words[i][0] != s[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;

  string s = "ngiuoy";
  vector<string> words = {"never", "gonna", "give", "up", "on", "you"};

  cout << sol.isAcronym(words, s) << endl;
  return 0;
}