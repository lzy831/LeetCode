#include "BaseHeader.h"

class SolutionOld {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> map;

    int max = 0;  // 输入可能位空

    for (int i = 0; i < nums.size(); i++) {
      // 取出当前位置前一个位置的数值的 最长连续前缀数值
      int pre_max = 0;
      if (map.count(nums[i] - 1) > 0) {
        pre_max = map[nums[i] - 1];
      }

      // 更新当前位置数值自己的 最长连续前缀数值
      map[nums[i]] = pre_max + 1;

      // 更新当前位置向后的 连续的数值key 上的 最长连续前缀数值
      int k = 1;
      while (map.find(nums[i] + k) != map.end()) {
        map[nums[i] + k] = pre_max + k + 1;
        k++;
      }

      int m = pre_max + k;
      max = m > max ? m : max;
    }

    return max;
  }
};

class Solution {


  // 这个算法的思路，其实是以找到 集合中这些连续序列的第一个值 作为核心
  // 找到这个值之后，开始向后推算最大的连续长度
  // 怎么找到每一个连续序列的头呢？ 就是用 set， 把所以元素都加进去，然后再循环一次
  // 每次迭代时，如果发现 当前值-1 的值已经在集合中，就跳过，说明当前值肯定不是一个连续序列的头
  // 如果当前值-1 不在，则是一个头，然后计算当前这个序列的最大长度
  // 通过记录MAX的办法，把所有连续序列的最大长度 算出来
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set;

    int max = 0;  // 输入可能位空

    for (int i = 0; i < nums.size(); i++) {
      set.insert(nums[i]);
    }

    for (int i = 0; i < nums.size(); i++) {
      int m = 1;

      if (set.find(nums[i] - 1) != set.end()) {
        continue;
      }

      while (set.find(nums[i] + m) != set.end()) {
        m++;
      }

      max = m > max ? m : max;
    }

    return max;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {5, 6, 3, 2, 1, 4};
  cout << sol.longestConsecutive(nums) << endl;
  return 0;
}