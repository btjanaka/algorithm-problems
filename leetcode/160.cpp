// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 160
// Title: Intersection of Two Linked Lists
// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Idea: After the two lists intersect, they will share their remaining x nodes.
// Therefore, we know we can throw out the beginning nodes of the longer list,
// as the intersection cannot happen there.
// Difficulty: easy
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
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // Determine the lengths.
    int lenA = 0, lenB = 0;
    for (ListNode* itr = headA; itr != NULL; itr = itr->next) ++lenA;
    for (ListNode* itr = headB; itr != NULL; itr = itr->next) ++lenB;

    // Throw away the first few nodes of the longer list.
    ListNode *itrA = headA, *itrB = headB;
    if (lenA > lenB) {
      for (int i = 0; i < lenA - lenB; ++i) itrA = itrA->next;
    } else if (lenB > lenA) {
      for (int i = 0; i < lenB - lenA; ++i) itrB = itrB->next;
    }

    // Go through the two lists together.
    while (itrA != NULL) {
      if (itrA == itrB) return itrA;
      itrA = itrA->next;
      itrB = itrB->next;
    }
    return NULL;
  }
};
