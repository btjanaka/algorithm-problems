// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 141
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
