// 234. 回文链表
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
  // 思路：
  // 2个指针，pFast每次2步，pSlow每次1步，pFast走完，pSlow在中间位置。
  // 把pSlow开头位置的链表进行逆置
  // 然后2个指针，从原先的头，和被逆置部分的头开始遍历比较
  bool isPalindrome(ListNode* head)
  {
    ListNode* pSlow = head;
    ListNode* pFast = head;

    if (head == nullptr) {
      return true;
    }

    while (pFast->next && pFast->next->next) {
      pFast = pFast->next->next;
      pSlow = pSlow->next;
    }

    pSlow = pSlow->next;
    ListNode* pre = nullptr;
    while (pSlow) {
      ListNode* tmp = pSlow->next;
      pSlow->next = pre;
      pre = pSlow;
      pSlow = tmp;
    }

    while (pre) {
      if (pre->val != head->val) {
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