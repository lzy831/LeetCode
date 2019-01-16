// 回文链表
// 请判断一个链表是否为回文链表。
// 示例 1:
// 输入: 1->2
// 输出: false
// 示例 2:
// 输入: 1->2->2->1
// 输出: true
// 进阶：
// 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
#include "BaseHeader.hpp"

class Solution
{
public:
  bool isPalindrome(ListNode* head)
  {
    ListNode* pSlow = head;
    ListNode* pFast = head;

    if(head == nullptr)
    {
      return true;
    }

    while(pFast->next && pFast->next->next)
    {
      pFast = pFast->next->next;
      pSlow = pSlow->next;
    }

    pSlow = pSlow->next;
    ListNode* pre = nullptr;
    while(pSlow)
    {
      ListNode* tmp = pSlow->next;
      pSlow->next = pre;
      pre = pSlow;
      pSlow = tmp;
    }

    while(pre)
    {
      if(pre->val != head->val)
      {
        return false;
      }
      pre = pre->next;
      head = head->next;
    }

    return true;
  }
};

int main(int argc, char const* argv[])
{
  Solution s;


  {
    cout << s.isPalindrome(nullptr) << endl;
  }

  {
    vector<int> v = { 1};
    ListNode* head = CreateList(v);
    cout << s.isPalindrome(head) << endl;
  }


  {
    vector<int> v = { 1, 2, 2, 1};
    ListNode* head = CreateList(v);
    cout << s.isPalindrome(head) << endl;
  }

  {
    vector<int> v = { 1, 2, 2, 1, 1};
    ListNode* head = CreateList(v);
    cout << s.isPalindrome(head) << endl;
  }

  return 0;
}