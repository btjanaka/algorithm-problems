// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 707
// Title: Design Linked List
// Link: https://leetcode.com/problems/design-linked-list
// Idea: Implement a linked list.
// Difficulty: medium
// Tags: implementation, linked-list
class MyLinkedList {
 public:
  /** Initialize your data structure here. */
  MyLinkedList() : head(new node(0, nullptr)) {}

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {
    node* cur = head->next;
    for (int i = 0;; ++i) {
      if (!cur) return -1;
      if (i == index) return cur->val;
      cur = cur->next;
    }
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) { head->next = new node(val, head->next); }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    for (node* cur = head;; cur = cur->next) {
      if (!cur->next) {
        cur->next = new node(val, nullptr);
        break;
      }
    }
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    node* prev = head;
    node* cur = head->next;
    for (int i = 0;; ++i) {
      if (cur == nullptr) {
        if (i == index) {
          prev->next = new node(val, nullptr);
        }
        break;
      }
      if (i == index) {
        prev->next = new node(val, cur);
        break;
      }

      prev = cur;
      cur = cur->next;
    }
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    node* prev = head;
    node* cur = head->next;
    for (int i = 0;; ++i) {
      if (!cur) return;
      if (i == index) {
        prev->next = cur->next;
        delete cur;
        break;
      }
      prev = cur;
      cur = cur->next;
    }
  }

 private:
  struct node {
    node* next;
    int val;
    node(int val, node* next) : val(val), next(next) {}
  };

  node* head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
