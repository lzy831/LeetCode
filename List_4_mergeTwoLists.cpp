//  合并两个有序链表
// 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
// 示例：
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4
#include "BaseHeader.hpp"

class Solution
{
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
  {
    ListNode* res = nullptr;
    ListNode* res_tail = nullptr;

    if(l1 == nullptr && l2 == nullptr)
    {
      return res;
    }

    ListNode* p1 = l1;
    ListNode* p2 = l2;

    while(p1 && p2)
    {
      if(p1->val < p2->val)
      {

        if(res == nullptr)
        {
          res = res_tail = p1;
        }
        else
        {
          res_tail->next = p1;
          res_tail = res_tail->next;
        }
        p1 = p1->next;
      }
      else
      {
        if(res == nullptr)
        {
          res = res_tail = p2;
        }
        else
        {
          res_tail->next = p2;
          res_tail = res_tail->next;
        }
        p2 = p2->next;
      }
    }

    if(p1)
    {
      if(res == nullptr)
      {
        res = p1;
      }
      else
      {
        res_tail->next = p1;
      }

    }
    else
    {
      if(res == nullptr)
      {
        res = p2;
      }
      else
      {
        res_tail->next = p2;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {2, 4, 6, 8};
    ListNode* head1 = CreateList(v1);
    ListNode* head2 = CreateList(v2);
    ListNode* res = s.mergeTwoLists(head1, head2);
    DebugList(res);
  }


  {
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {2, 4, 6, 8};
    ListNode* head1 = CreateList(v1);
    ListNode* head2 = nullptr;
    ListNode* res = s.mergeTwoLists(head1, head2);
    DebugList(res);
  }






  return 0;
}