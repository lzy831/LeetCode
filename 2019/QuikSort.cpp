#include "BaseHeader.hpp"


class Solution
{
public:
  void QuikSort(vector<int>& v, int begin, int end)
  {
    if(v.empty())
    {
      return ;
    }
    if(begin == end)
    {
      return ;
    }

    int mid = Partion(v, begin, end);
    if(mid > begin)
    {
      QuikSort(v, begin, mid);
    }
    if(mid < end)
    {
      QuikSort(v, mid + 1, end);
    }
  }

  void Swap(vector<int>& v, int a, int b)
  {
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
  }

  int Partion(vector<int>& v, int begin, int end)
  {
    if(begin == end)
    {
      return begin;
    }

    // int r = rand() % (end - begin) + begin;
    // Swap(v, r, end);

    int small = begin - 1;
    for(int i = begin; i < end; i++)
    {

      if(v[i] < v[end])
      {
        if(i > small + 1)
        {
          Swap(v, small + 1, i);
        }
        small++;
      }
    }

    // 注意不能把中间数包含在 下次Partion 的前一半中，因为中间数之前的数都是已经排序的比中间数小的数了
    
    Swap(v, small+1, end);
    return small;
  }
};


int main()
{
  Solution s;

  vector<int> v = {7, 6, 9, 3, 1, 8, 4, 5};

  s.QuikSort(v, 0, v.size() - 1);

  // s.Partion(v, 0, v.size() - 1);

  DebugVector(v);

  return 0;
}