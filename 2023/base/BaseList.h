#ifndef __BASE_LIST_HPP__
#define __BASE_LIST_HPP__
#include <vector>
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* CreateList(vector<int>& v) {
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  for (auto& i : v) {
    if (!head) {
      head = new ListNode(i);
      tail = head;
    } else {
      ListNode* node = new ListNode(i);
      tail->next = node;
      tail = node;
    }
  }
  return head;
}

ListNode* FindFirstVal(ListNode* head, int val) {
  ListNode* p = head;
  while (p) {
    if (p->val == val) {
      return p;
    } else {
      p = p->next;
    }
  }
  return p;
}

ListNode* FindNodeAtPos(ListNode* head, int pos) {
  int cur = 0;
  ListNode* p = head;
  while (p) {
    if (cur == pos) {
      return p;
    }
    p = p->next;
    cur++;
  }
  return nullptr;
}

ListNode* FindListTail(ListNode* head) {
  if (!head) {
    return nullptr;
  }

  ListNode* p = head;
  while (p->next) {
    p = p->next;
  }
  return p;
}

void DebugList(ListNode* head) {
  ListNode* p = head;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

#endif