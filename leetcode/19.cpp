// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 19
// Solution 1: slow way - two passes over the list
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Find length of list
    int len = 0;
    ListNode* itr = head;
    while (itr) {
      ++len;
      itr = itr->next;
    }

    // Check if removing the head itself
    if (len == n) return head->next;

    // Otherwise go to the (len - n)th node and remove the one at len - n + 1
    itr = head;
    int i;
    for (i = 2; i <= len - n; ++i) {
      itr = itr->next;
    }
    itr->next = itr->next->next;
    return head;
  }
};

// Solution 2: fast - < 2 passes
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* lead = head;
    ListNode* follow = head;

    // Advance lead to be at the (n+2)th node. This way,
    // follow is (n + 1) behind lead. As lead moves along, follow
    // will be still (n + 1) behind it. When lead reaches the end,
    // follow will then be at the (n + 1)th node from the end, and the nth node
    // can then be removed. Note that this for loop only advances lead to the (n
    // + 1)th node; if n is the length of the list, trying to go to the (n +
    // 2)th will cause an error.
    for (int i = 0; i < n; ++i) {
      lead = lead->next;
    }

    // Check if n is equal to the length of the list (in which case lead
    // would be null here). In this case, the head needs to be removed.
    if (!lead) return head->next;

    // Move to (n + 2)th node.
    lead = lead->next;

    while (lead) {
      lead = lead->next;
      follow = follow->next;
    }

    // Remove the necessary node.
    follow->next = follow->next->next;

    return head;
  }
};
