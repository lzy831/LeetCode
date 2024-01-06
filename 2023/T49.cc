#include "BaseHeader.h"

// 把小写字母组成的单词分组，依据是单词中是否包含相同个数的字母
// 分组之类的功能，一般想到用哈希表
// 不同的异位词就需要可以 形成一个统一的 哈希值 作为 key
// 这题 可以把 字串排序， 因为异位词排序后，会变成相同的字串，这个就可以作为 key
// 之后把 key 相同的 字串（单词）放在一个 key 下面，就完成了分组

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;

    unordered_map<string, vector<string>> map;

    for (int i = 0; i < strs.size(); i++) {
      string s = orderString(strs[i]);

      if (map.count(s) == 0) {
        auto v = new vector<string>;
        map[s] = *v;
      }
      map[s].push_back(strs[i]);
    }

    for (auto item : map) {
      result.push_back(item.second);
    }
    return result;
  }

  string orderString(string& str) {
    string ostr = str;
    std::sort(ostr.begin(), ostr.end());
    return ostr;
  }
};

int main() {
  Solution sol;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto result = sol.groupAnagrams(strs);
  // cout << __FILE__ << endl;
  return 0;
}