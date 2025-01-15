// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 82
// Title: Remove Duplicates from Sorted List II
// Link:
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
// Idea:
// Difficulty: Medium
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
  // Maintain the head of the list. Then, iterate through the list using the
  // head pointer and maintaining a previous pointer. If the next and previous
  // node's vals are not the same as the current one, then we can add this one
  // to the end of the list.
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = new ListNode();
    ListNode* tail = res;
    ListNode* prev = nullptr;

    while (head != nullptr) {
      if ((prev == nullptr || prev->val != head->val) &&
          (head->next == nullptr || head->val != head->next->val)) {
        tail->next = head;
        tail = tail->next;
      }

      prev = head;
      head = head->next;
    }

    // Finish the list.
    tail->next = nullptr;

    // Edge case: If there is nothing in the list, this will return nullptr.
    return res->next;
  }
};
