// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 141
// Title: Linked List Cycle
// Link: https://leetcode.com/problems/linked-list-cycle
// Idea: Have two nodes run around the linked list; one that is fast and one
// that is slow. If the fast one catches up to the slow one, there is a cycle.
// Difficulty: medium
// Tags: linked-list
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
    if (head == NULL) return false;  // edge cases :(

    // Have one node move faster than the other; if there
    // is a cycle it will catch up to the slower one.
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next != NULL && fast->next->next != NULL &&
           fast->next != slow && fast->next->next != slow) {
      fast = fast->next->next;
      slow = slow->next;
    }
    if (fast->next == NULL || fast->next->next == NULL) return false;
    if (fast->next == slow || fast->next->next == slow) return true;
  }
};
