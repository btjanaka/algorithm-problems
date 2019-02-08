// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 2
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    int val;

    ListNode* head = new ListNode(-1);
    ListNode* itr = head;

    // Add up digits that l1 and l2 have - i.e. until one runs out
    while (l1 != NULL && l2 != NULL) {
      val = l1->val + l2->val + carry;
      carry = val / 10;
      val = val % 10;
      itr->next = new ListNode(val);

      itr = itr->next;
      l1 = l1->next;
      l2 = l2->next;
    }

    // Add up remaining in either l1 or l2
    if (l1 == NULL) {
      while (l2 != NULL) {
        val = l2->val + carry;
        carry = val / 10;
        val = val % 10;
        itr->next = new ListNode(val);

        itr = itr->next;
        l2 = l2->next;
      }
    } else {
      while (l1 != NULL) {
        val = l1->val + carry;
        carry = val / 10;
        val = val % 10;
        itr->next = new ListNode(val);

        itr = itr->next;
        l1 = l1->next;
      }
    }

    // Add on last carry
    if (carry > 0) {
      itr->next = new ListNode(carry);
    }

    return head->next;
  }
};
