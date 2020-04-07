// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 21
// Title: Merge Two Sorted Lists
// Link: https://leetcode.com/problems/merge-two-sorted-lists
// Idea: See code comments. We just keep selecting the next largest element.
// Difficulty: easy
// Tags: linked-list, sorting
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* tail = head;

    while (l1 != NULL || l2 != NULL) {
      // Use l1 if l2 is NULL (then we would know that l1 has to be non-null,
      // since the while loop would exit otherwise), or if l1 is != NULL and
      // l1 has a value less than l2 (we know l2 can be safely called because
      // it passed the first check and failed to short circuit).
      //
      // Otherwise, use l2.
      if (l2 == NULL || (l1 != NULL && l1->val < l2->val)) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    return head->next;
  }
};
