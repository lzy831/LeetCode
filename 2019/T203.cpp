// 203. 移除链表元素
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
  ListNode* removeElements(ListNode* head, int val)
  {
    ListNode* pdel = head;
    ListNode* prev = nullptr;

    while(pdel)
    {
      if(pdel->val == val)
      {
        if(!prev)
        {
          head = pdel->next;
        }
        else
        {
          prev->next = pdel->next;
        }
      }
      else
      {
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
  vector<int> v = {4, 1, 2, 3, 4, 5, 6, 7, 4};
  ListNode* head = CreateList(v);
  DebugList(head);
  DebugList(s.removeElements(head, 4));
  return 0;
}