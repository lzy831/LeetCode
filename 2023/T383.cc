#include "BaseHeader.h"

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> dict;

    for (char item : ransomNote) {
      if (dict.find(item) != dict.end()) {
        dict[item]++;
      } else {
        dict[item] = 1;
      }
    }

    for (char item : magazine) {
      if (dict.find(item) != dict.end()) {
        if (dict[item] > 1) {
          dict[item]--;
        } else {
          dict.erase(item);
        }
      }
    }

    return dict.empty();
  }
};

int main() {
  Solution sol;

  string ransomNote = "aac";
  string magazine = "baccbdbd";

  cout << sol.canConstruct(ransomNote, magazine) << endl;

  return 0;
}