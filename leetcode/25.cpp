// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 25
// Title: Reverse Nodes in k-Group
// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Idea: Mostly implement the problem; pointers get really tricky when reversing
// the list.
// Difficulty: medium
// Tags: linked-list, implementation
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return head;

    ListNode* tail = new ListNode(0);
    tail->next = head;
    head = tail;

    int i = 0;
    for (ListNode* cur = tail->next; cur != NULL; cur = cur->next) {
      if (i % k == 0 && i != 0) {
        ListNode* reverse_itr = tail->next;
        ListNode* next = reverse_itr->next;
        for (;;) {
          if (next == cur) {
            tail->next->next = cur;
            ListNode* tmp = tail->next;
            tail->next = reverse_itr;
            tail = tmp;
            break;
          }
          ListNode* nextnext = next->next;
          next->next = reverse_itr;
          reverse_itr = next;
          next = nextnext;
        }
      }

      ++i;
    }

    // edge case at the end - do it one more time :p
    if (i % k == 0) {
      ListNode* reverse_itr = tail->next;
      ListNode* next = reverse_itr->next;
      for (;;) {
        if (next == NULL) {
          tail->next->next = NULL;
          ListNode* tmp = tail->next;
          tail->next = reverse_itr;
          tail = tmp;
          break;
        }
        ListNode* nextnext = next->next;
        next->next = reverse_itr;
        reverse_itr = next;
        next = nextnext;
      }
    }

    return head->next;
  }
};
