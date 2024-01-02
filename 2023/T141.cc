#include "BaseHeader.h"
#include "BaseList.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  bool hasCycle(ListNode* head) {
    ListNode* p1 = head;
    ListNode* p2 = p1;

    while (p1 && p2) {
      if (p1 && p1->next && p2 && p2->next && p2->next->next) {
        p1 = p1->next;
        p2 = p2->next->next;
      } else {
        return false;
      }

      if (p1 == p2) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;

  vector<int> v = {3, 2, 0, 4, 6, 5, 8};
  ListNode* head = CreateList(v);

  DebugList(head);

  // 找到指定的node
  ListNode* pos_node = FindNodeAtPos(head, 2);
  if (pos_node) {
    // 把list尾部链接到指定的note上
    ListNode* p = head;
    while (p->next) {
      p = p->next;
    }
    p->next = pos_node;
  }

  cout << sol.hasCycle(head) << endl;
  return 0;
}