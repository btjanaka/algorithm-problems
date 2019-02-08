// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 24
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
  ListNode* swapPairs(ListNode* head) {
    ListNode* pre_head = new ListNode(-1);
    pre_head->next = head;

    ListNode* prev = pre_head;
    ListNode* one = head;
    ListNode* two = head ? head->next : NULL;

    while (one && two) {
      // Swap
      prev->next = two;
      one->next = two->next;
      two->next = one;

      // Advance
      prev = prev->next->next;
      one = prev->next;
      if (one) two = prev->next->next;
    }

    return pre_head->next;
  }
};
