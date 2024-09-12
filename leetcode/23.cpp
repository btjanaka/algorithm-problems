// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 23
// Title: Merge k Sorted Lists
// Link: https://leetcode.com/problems/merge-k-sorted-lists/
// Idea: Toss the heads of each list into a priority queue and keep selecting
// the best at each step.
// Difficulty: medium
// Tags: priority-queue
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Complexity: O(n log k), where n is total number of nodes and k is number of
// lists, because we push and pop n times a PQ of size k
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    std::priority_queue<std::pair<int, ListNode*>> next;
    for (ListNode* origin : lists) {
      if (origin != NULL) {
        // Negative because priority queue selects greatest value by default.
        next.push({-origin->val, origin});
      }
    }

    while (!next.empty()) {
      ListNode* cur = next.top().second;
      next.pop();
      if (cur->next != NULL) {
        next.push({-cur->next->val, cur->next});
      }
      tail->next = cur;
      tail = cur;
    }

    return head->next;
  }
};

// Solution from 9/2024; pretty much the same.

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
typedef pair<int, int> ii;
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = new ListNode();
    ListNode* front = head;
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    // Initialize pq with the front of each list.
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i] != nullptr) {
        pq.push({lists[i]->val, i});
      }
    }

    while (!pq.empty()) {
      ii top = pq.top();
      pq.pop();
      int i = top.second;
      head->next = lists[i];
      lists[i] = lists[i]->next;
      if (lists[i] != nullptr) {
        pq.push({lists[i]->val, i});
      }
      head = head->next;
    }
    return front->next;
  }
};
