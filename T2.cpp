// 2. 两数相加
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* p1 = l1;
    ListNode* p2 = l2;

    int carry = 0;
    while(p1 || p2) {
      int sum = carry;
      if(p1) {
        sum += p1->val;
        p1 = p1->next;
      }
      if(p2) {
        sum += p2->val;
        p2 = p2->next;
      }
      carry = sum / 10;
      sum = sum % 10;
      ListNode* node = new ListNode(sum);
      if(!head) {
        head = tail = node;
      } else {
        tail->next = node;
        tail = node;
      }
    }
    if(carry) {
      ListNode* node = new ListNode(carry);
      tail->next = node;
      tail = node;
    }
    return head;
  }
};

int main()
{
  Solution s;
  vector<int> v1 = {2, 4, 3};
  vector<int> v2 = {5, 6, 4};
  ListNode* list1 = CreateList(v1);
  ListNode* list2 = CreateList(v2);

  DebugList(list1);
  DebugList(list2);

  ListNode* res = s.addTwoNumbers(list1, list2);
  DebugList(res);
  return 0;
}















