// 打家劫舍
// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

// 示例 1:

// 输入: [1,2,3,1]
// 输出: 4
// 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//      偷窃到的最高金额 = 1 + 3 = 4 。
// 示例 2:

// 输入: [2,7,9,3,1]
// 输出: 12
// 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//      偷窃到的最高金额 = 2 + 9 + 1 = 12 。
#include "BaseHeader.hpp"


// dp(0) = nums[0];
// dp(1) = max ( nums[0], nums[1] )
// dp(2) = max ( dp(0)+nums[2] , dp(1) )
// ...
// dp(n) = max ( dp(n-2) + nums[n], dp(n-1) )

// dp(n) 表示抢劫到第N户人家时，可以抢到的最大价值。
// 如何理解： 当抢到第n户人家时，分两种情况考虑，

// 第一种，抢这户。那么可以拿到价值 nums[n]， 然后 第 n-1 户是抢不了的。0 ~ n-2户 之间可以拿到的最大价值是 dp(n-2)， 所以抢这一户的话，可以拿到最大价值为 dp(n-2) + nums[n]
// 第二种，不抢这户。那么这户的价值拿不到，那前面的 0 ~ n-1 户可以拿到的最大价值是 dp(n-1)

class Solution
{
public:
  int rob(vector<int>& nums)
  {
    if(nums.size() < 1)
    {
      return 0;
    }
    if(nums.size() == 1)
    {
      return nums[0];
    }
    if(nums.size() == 2)
    {
      return max(nums[0], nums[1]);
    }

    int dp_minus2 = nums[0];
    int dp_minus1 = std::max(nums[0], nums[1]);
    int i = 3;
    int max  = 0;
    while(i <= nums.size())
    {
      max = std::max((dp_minus2 + nums[i - 1]) , dp_minus1);
      dp_minus2 = dp_minus1;
      dp_minus1 = max;
      i++;
    }
    return max;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;
  {
    vector<int> v = {2, 1, 1, 2};
    cout << s.rob(v) << endl;
  }

  {
    vector<int> v ;
    cout << s.rob(v) << endl;
  }

  {
    vector<int> v = {2};
    cout << s.rob(v) << endl;
  }

  {
    vector<int> v = {2, 7};
    cout << s.rob(v) << endl;
  }

  {
    vector<int> v = {1, 2, 3, 1};
    cout << s.rob(v) << endl;
  }

  {
    vector<int> v = {2, 7, 9, 3, 1};
    cout << s.rob(v) << endl;
  }
  return 0;
}