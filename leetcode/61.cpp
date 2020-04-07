// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 61
// Title: Rotate List
// Link: https://leetcode.com/problems/rotate-list
// Idea: Find the location to rotate, then modify the connections as
// appropriate.
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
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return head;

    // Find length of list - also find the tail
    int len;
    ListNode* itr = head;
    ListNode* tail = head;
    for (len = 0; itr; ++len) {
      tail = itr;
      itr = itr->next;
    }

    // Minimize rotations
    k = k % len;

    // Return if no rotation to make
    if (k == 0) return head;

    // Go to (len - k)th node in the list
    // and perform rotation.
    itr = head;
    for (int i = 1; i < (len - k); ++i) {
      itr = itr->next;
    }
    tail->next = head;
    head = itr->next;
    itr->next = NULL;

    return head;
  }
};
