// 206. 反转链表
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
  ListNode* reverseList(ListNode* head)
  {
    ListNode* p1 = head;
    if(!p1)
    {
      return nullptr;
    }
    ListNode* p2 = p1->next;
    if(!p2)
    {
      return p1;
    }

    // p1 p2 都已经存在，此时可以将原先 head->next 设置为nullptr
    p1->next = nullptr;

    ListNode* p3 = p2->next;
    while(p3)
    {
      p2->next = p1;
      p1 = p2;
      p2 = p3;
      p3 = p3->next;
    }
    p2->next = p1;
    return p2;
  }



  ListNode* reverseList1(ListNode* head)
  {
    ListNode* p = head;
    ListNode* pre = nullptr;

    while(p)
    {
      ListNode* tmp = p->next;
      p->next = pre;
      pre = p;
      p = tmp;
    }
    return pre;
  }




};

int main()
{
  Solution s;

  {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = CreateList(v);
    DebugList(head);
    DebugList(s.reverseList(head));
  }
  {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = CreateList(v);
    DebugList(head);
    DebugList(s.reverseList1(head));
  }
  return 0;
}