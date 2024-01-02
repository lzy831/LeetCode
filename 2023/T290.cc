#include "BaseHeader.h"

class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    vector<string> str_array;
    splitString(s, str_array);

    if (str_array.size() != pattern.size()) {
      return false;
    }

    unordered_map<char, string> map1;
    for (int i = 0; i < pattern.size(); i++) {
      if (map1.find(pattern[i]) == map1.end()) {
        map1[pattern[i]] = str_array[i];
      } else {
        if (map1[pattern[i]] != str_array[i]) {
          return false;
        }
      }
    }

    unordered_map<string, char> map2;
    for (int i = 0; i < str_array.size(); i++) {
      if (map2.find(str_array[i]) == map2.end()) {
        map2[str_array[i]] = pattern[i];
      } else {
        if (map2[str_array[i]] != pattern[i]) {
          return false;
        }
      }
    }

    return true;
  }

  void splitString(string s, vector<string>& result) {
    if (s.empty()) {
      return;
    }

    int begin = 0;
    int end = 0;
    while (end != s.size()) {
      while (end != s.size() && s[end] != ' ') {
        end++;
      }
      if (begin != end) {
        result.push_back(s.substr(begin, end - begin));
      }
      if (end == s.size()) {
        return;
      }
      begin = end + 1;
      end = begin;
    }
  }
};

int main() {
  Solution sol;

  string pattern = "a";
  string s = "a";

  cout << sol.wordPattern(pattern, s) << endl;
  return 0;
}