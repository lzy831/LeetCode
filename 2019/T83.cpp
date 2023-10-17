// 83. 删除排序链表中的重复元素
#include "BaseHeader.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  ListNode* deleteDuplicates(ListNode* head)
  {
    unordered_set<int> hset;
    ListNode* pdel = head;
    ListNode* prev = nullptr;
    while(pdel)
    {
      if(hset.count(pdel->val))
      {
        // 存在，删除
        prev->next = pdel->next;
      }
      else{
        // 不存在，存入set，不删除
        hset.insert(pdel->val);
        prev = pdel;
      }
      pdel = pdel->next;
    }
    return head;
  }
};


int main()
{
  Solution s;
  vector<int> v1 = {1, 1, 2, 3, 4, 5, 5, 6, 7, 8, 8};

  ListNode* list1 = CreateList(v1);
  DebugList(list1);
  ListNode* res = s.deleteDuplicates(list1);
  DebugList(res);
  return 0;
}