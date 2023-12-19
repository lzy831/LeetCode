#include "BaseHeader.h"
// #include <utility>


// 变长数组 与 哈希表 的结合使用
// 哈希表可以做到 O(1) 的查找
// 变长数组 用来做一个 O(1) 的增删 操作， 技巧就是删除的时候，把末尾的数值移动到被删除的位置，然后每次都统一删除末尾，这样才能做到O(1)

class RandomizedSet {
 public:
  RandomizedSet() { srand(time(NULL)); }

  bool insert(int val) {
    if (hash_map_.find(val) != hash_map_.end()) {
      return false;
    }
    nums_.push_back(val);
    hash_map_.insert(std::make_pair(val, nums_.size() - 1));
    return true;
  }

  bool remove(int val) {
    if (hash_map_.find(val) == hash_map_.end()) {
      return false;
    }

    int remove_index = hash_map_[val];
    nums_[remove_index] = nums_[nums_.size() - 1];
    hash_map_[nums_[nums_.size() - 1]] = remove_index;
    nums_.pop_back();
    hash_map_.erase(val);
    return true;
  }

  int getRandom() { return nums_[rand() % nums_.size()]; }

 private:
  std::vector<int> nums_;
  std::unordered_map<int, int> hash_map_;
};

int main() {
  return 0;
}