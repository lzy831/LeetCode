// 141. 环形链表
// 给定一个链表，判断链表中是否有环。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
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
  bool hasCycle(ListNode* head)
  {
    // 两个指针，一个一次走1步，一个一次走2步，如果可以相遇则表明有环
    if(!head)
    {
      return false;
    }

    ListNode* p1 = head;
    ListNode* p2 = p1->next;

    while(1)
    {
      if(p1 == p2)
      {
        return true;
      }

      if(p1->next)
      {
        p1 = p1->next;
      }
      else
      {
        return false;
      }

      if(p2->next && p2->next->next)
      {
        p2 = p2->next->next;
      }
      else
      {
        return false;
      }
    }
  }
};

int main()
{
  Solution s;
  vector<int> v = {3, 2, 0, 4, 6, 5, 8};

  ListNode* head = CreateList(v);

  // 把list尾部链接到首部
  ListNode* p = head;
  while(p->next)
  {
    p = p->next;
  }
  p->next = head;

  // DebugList(CreateList(v));

  cout << s.hasCycle(head) << endl;
  return 0;
}