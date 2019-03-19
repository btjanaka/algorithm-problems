// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 206
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
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* res = nullptr;
    while (head) {
      ListNode* next = head->next;
      head->next = res;
      res = head;
      head = next;
    }
    return res;
  }
};
