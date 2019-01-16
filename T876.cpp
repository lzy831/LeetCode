// 876. 链表的中间结点
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
  ListNode* middleNode(ListNode* head)
  {

    ListNode* p2 = head;
    ListNode* p1 = head;

    while(p1 && p2)
    {
      if(!p2->next)
      {
        // 如果p2走了1步就到结尾了，则返回当前p1
        return p1;
      }
      else
      {
        p2 = p2->next;
        if(!p2->next)
        {
          // 如果p2走了2步就到结尾了，则返回当前p1->next，因为2个中间节点需要返回第二个
          return p1->next;
        }
        p2 = p2->next;
      }
      p1 = p1->next;
    }

    return p1;
  }
};


int main()
{
  Solution s;
  vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> v2 = {1, 2, 3, 4, 5, 6, 7};

  ListNode* head1 = CreateList(v1);
  ListNode* head2 = CreateList(v2);

  cout << s.middleNode(head1)->val << endl;
  cout << s.middleNode(head2)->val << endl;
  return 0;
}