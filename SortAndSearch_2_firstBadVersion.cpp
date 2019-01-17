// 第一个错误的版本
// 你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。
// 假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
// 你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
// 示例:
// 给定 n = 5，并且 version = 4 是第一个错误的版本。
// 调用 isBadVersion(3) -> false
// 调用 isBadVersion(5) -> true
// 调用 isBadVersion(4) -> true
// 所以，4 是第一个错误的版本。
#include "BaseHeader.hpp"


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);


bool isBadVersion(int version)
{
  return version > 1702766719;
}

class Solution
{
public :
  int firstBadVersion(int n)
  {
    if(n < 2)
    {
      return n;
    }

    int lastGood = 0;
    int firstBad = n+1;

    while(lastGood < firstBad - 1)
    {
      int checkVersion = ( (long long)lastGood + (long long)firstBad) / 2;

      if(isBadVersion(checkVersion))
      {
        // checkVersion 是一个出错版本
        firstBad = checkVersion;
      }
      else
      {
        lastGood = checkVersion;
      }
    }
    return firstBad;
  }

};

int main(int argc, char const* argv[])
{
  Solution s;


  cout << s.firstBadVersion(2126753390) << endl;


  return 0;
}