// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 116
// Title: Populating Next Right Pointers in Each Node
// Link:
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Idea: Do a BFS on the tree, while keeping track of the level of each node.
// By adding left and then right children, you are able to traverse the tree
// from left to right, so after popping each node, make it point to the next
// node on the queue (assuming they are at the same level).
// Difficulty: medium
// Tags: binary-tree, bfs
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
  Node* connect(Node* root) {
    queue<pair<Node*, int>> q;
    if (root != NULL) q.push({root, 0});

    while (!q.empty()) {
      Node* cur;
      int lvl;
      tie(cur, lvl) = q.front();
      q.pop();

      if (q.empty() || q.front().second != lvl) {
        // If the level is not the same.
        cur->next = NULL;
      } else {
        // If the level is the same, point to the node on the front of the
        // queue.
        cur->next = q.front().first;
      }

      // Add left and then right child.
      if (cur->left) q.push({cur->left, lvl + 1});
      if (cur->right) q.push({cur->right, lvl + 1});
    }
    return root;
  }
};
