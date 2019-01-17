// 160. 相交链表
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
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
  {
    ListNode* pA = headA;
    int lenA = 0;
    ListNode* pB = headB;
    int lenB = 0;

    if(!pA || !pB)
    {
      return nullptr;
    }
    lenA = 1;
    lenB = 1;

    while(pA->next)
    {
      lenA++;
      pA = pA->next;
    }
    while(pB->next)
    {
      lenB++;
      pB = pB->next;
    }

    // 最后一个节点不一致，则没有相交
    if(pA != pB)
    {
      return nullptr;
    }

    // 重新开始走
    pA = headA;
    pB = headB;

    // 长的链表先走 diff 个节点
    if(lenA > lenB)
    {
      int diff = lenA - lenB;
      while(diff--)
      {
        pA = pA->next;
      }
    }
    else
    {
      int diff = lenB - lenA;
      while(diff--)
      {
        pB = pB->next;
      }
    }

    // 然后一起走到相同的节点
    while(pA && pB)
    {
      if(pA == pB)
      {
        return pA;
      }
      pA = pA->next;
      pB = pB->next;
    }
    return nullptr;
  }
};


int main()
{
  Solution s;
  vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> v2 = {1, 2, 3, 4};

  ListNode* list1 = CreateList(v1);
  ListNode* list2 = CreateList(v2);
  DebugList(list1);
  DebugList(list2);

  // 设置相交点
  FindListTail(list2)->next = FindFirstVal(list1, 5);
  DebugList(list1);
  DebugList(list2);

  ListNode* res = s.getIntersectionNode(list1, list2);
  DebugList(res);
  return 0;
}