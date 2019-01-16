// 189. 旋转数组
#include "BaseHeader.hpp"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int real_k = k % nums.size();
    }
};

int main()
{
  Solution s;
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  v.push_back(7);

  s.rotate(v, 20);
  
  DebugVector(v);
  return 0;
}