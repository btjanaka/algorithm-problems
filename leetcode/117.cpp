// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 117
// Title: Populating Next Right Pointers in Each Node II
// Link:
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Idea: Traverse each layer of the tree using the `next` pointers built by
// traversing the previous layer. As we traverse each layer, we check each
// node's children and build up the next layer.
// Difficulty: medium
// Tags: tree, binary-tree, linked-list
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
 public:
  Node *connect(Node *root) {
    Node *leftmost = root;  // Leftmost node on current layer.
    Node *next_layer_prev;  // Last visited node on the next layer.
    Node *cur;              // Iterator over the current layer.

    // Iterate through each layer. A layer with no nodes will have leftmost =
    // NULL.
    while (leftmost != NULL) {
      next_layer_prev = NULL;
      cur = leftmost;
      while (cur != NULL) {
        // Check each child.
        if (cur->left) {
          if (next_layer_prev == NULL) {
            leftmost = cur->left;
          } else {
            // Make the child part of the next layer.
            next_layer_prev->next = cur->left;
          }
          // Advance the next layer iterator.
          next_layer_prev = cur->left;
        }
        if (cur->right) {
          if (next_layer_prev == NULL) {
            leftmost = cur->right;
          } else {
            next_layer_prev->next = cur->right;
          }
          next_layer_prev = cur->right;
        }

        // Advance along this layer.
        cur = cur->next;
      }

      // Next level must be empty.
      if (!next_layer_prev) leftmost = NULL;
    }

    return root;
  }
};
