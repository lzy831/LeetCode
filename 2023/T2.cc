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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1;
    ListNode* p2 = l2;

    ListNode* p3_head = nullptr;
    ListNode* p3_tail = nullptr;
    int aac = 0;

    while (p1 && p2) {
      //
      //
      int val = (aac + p1->val + p2->val) % 10;
      aac = (aac + p1->val + p2->val) / 10;
      ListNode* new_node = new ListNode(val);

      if (p3_head == nullptr) {
        p3_head = p3_tail = new_node;
      } else {
        p3_tail->next = new_node;
        p3_tail = new_node;
      }

      p1 = p1->next;
      p2 = p2->next;
    }

    while (p1) {
      int val = (aac + p1->val) % 10;
      aac = (aac + p1->val) / 10;
      ListNode* new_node = new ListNode(val);

      if (p3_head == nullptr) {
        p3_head = p3_tail = new_node;
      } else {
        p3_tail->next = new_node;
        p3_tail = new_node;
      }

      p1 = p1->next;
    }

    while (p2) {
      int val = (aac + p2->val) % 10;
      aac = (aac + p2->val) / 10;
      ListNode* new_node = new ListNode(val);

      if (p3_head == nullptr) {
        p3_head = p3_tail = new_node;
      } else {
        p3_tail->next = new_node;
        p3_tail = new_node;
      }

      p2 = p2->next;
    }

    if (aac > 0) {
      ListNode* new_node = new ListNode(1);
      if (p3_head == nullptr) {
        p3_head = p3_tail = new_node;
      } else {
        p3_tail->next = new_node;
        p3_tail = new_node;
      }
    }

    return p3_head;
  }
};

int main() {
  Solution sol;

  vector<int> v1 = {3, 5, 7};
  vector<int> v2 = {8, 4, 6, 9};

  ListNode* l1 = CreateList(v1);
  ListNode* l2 = CreateList(v2);

  DebugList(sol.addTwoNumbers(l1, l2));

  return 0;
}