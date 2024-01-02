#include "BaseHeader.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  void AppendNode(ListNode** p_new_head, ListNode** p_new_tail, ListNode* node) {
    if (*p_new_head == nullptr) {
      *p_new_head = *p_new_tail = node;
      return;
    }
    (*p_new_tail)->next = node;
    (*p_new_tail) = node;
  }

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* p1 = list1;
    ListNode* p2 = list2;
    ListNode* p_new_head = nullptr;
    ListNode* p_new_tail = nullptr;

    while (p1 && p2) {
      if (p1->val <= p2->val) {
        AppendNode(&p_new_head, &p_new_tail, p1);
        p1 = p1->next;
      } else {
        AppendNode(&p_new_head, &p_new_tail, p2);
        p2 = p2->next;
      }
    }

    while (p1) {
      AppendNode(&p_new_head, &p_new_tail, p1);
      p1 = p1->next;
    }

    while (p2) {
      AppendNode(&p_new_head, &p_new_tail, p2);
      p2 = p2->next;
    }

    return p_new_head;
  }
};

int main() {
  Solution sol;
  vector<int> v1 = {1, 2, 4};
  vector<int> v2 = {1, 3, 4};
  ListNode* h1 = CreateList(v1);
  ListNode* h2 = CreateList(v2);

  DebugList(h1);
  DebugList(h2);

  ListNode* h_new = sol.mergeTwoLists(h1, h2);
  DebugList(h_new);

  return 0;
}