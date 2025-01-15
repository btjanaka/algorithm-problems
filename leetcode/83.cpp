// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 83
// Title: Remove Duplicates from Sorted List
// Link:
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
// Idea: Maintain a separate list where you append the results. Then iterate
// through the original list. On every node, check if the next one has the same
// val. If it does, do not add it.
// Difficulty:
// Tags:
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = new ListNode();
    ListNode* tail = res;
    while (head != nullptr) {
      if (head->next == nullptr || head->val != head->next->val) {
        tail->next = head;
        tail = tail->next;
      }
      head = head->next;
    }
    tail->next = nullptr;
    return res->next;
  }
};
