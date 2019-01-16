
// 删除链表的倒数第N个节点
// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
// 示例：
// 给定一个链表: 1->2->3->4->5, 和 n = 2.
// 当删除了倒数第二个节点后，链表变为 1->2->3->5.
// 说明：
// 给定的 n 保证是有效的。
// 进阶：
// 你能尝试使用一趟扫描实现吗？
#include "BaseHeader.hpp"

class Solution
{
public:
  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    if(!head || n < 1)
    {
      return head;
    }

    ListNode* preN = nullptr;
    ListNode* prepreN = nullptr;
    ListNode* pNode = head;

    n--;
    while(n && pNode->next)
    {
      pNode = pNode->next;
      n--;
    }

    if(n)
    {
      return head;
    }


    preN = head;
    while(pNode->next)
    {
      pNode = pNode->next;
      prepreN = preN;
      preN = preN->next;
    }

    if(prepreN == nullptr)
    {
      return preN->next;
    }
    prepreN->next = preN->next;

    return head;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;

  {
    vector<int>  v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* head = CreateList(v);
    DebugList(head);
    ListNode* res = s.removeNthFromEnd(head, 1);
    DebugList(res);
  }

  {
    vector<int>  v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* head = CreateList(v);
    DebugList(head);
    ListNode* res = s.removeNthFromEnd(head, 2);
    DebugList(res);
  }

  {
    vector<int>  v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* head = CreateList(v);
    DebugList(head);
    ListNode* res = s.removeNthFromEnd(head, 3);
    DebugList(res);
  }

  {
    vector<int>  v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* head = CreateList(v);
    DebugList(head);
    ListNode* res = s.removeNthFromEnd(head, 9);
    DebugList(res);
  }

  {
    vector<int>  v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* head = CreateList(v);
    DebugList(head);
    ListNode* res = s.removeNthFromEnd(head, 10);
    DebugList(res);
  }

  return 0;
}