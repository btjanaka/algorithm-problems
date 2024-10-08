// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 589
// Title: N-ary Tree Preorder Traversal
// Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal
// Idea: Implement an iterative depth-first traversal.
// Difficulty: easy
// Tags: tree, depth-first-traversal
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
 public:
  vector<int> preorder(Node* root) {
    vector<int> res;
    stack<Node*> s;
    if (root) s.push(root);
    while (!s.empty()) {
      Node* cur = s.top();
      s.pop();
      res.push_back(cur->val);
      for (int i = cur->children.size() - 1; i >= 0; --i) {
        Node* child = cur->children[i];
        if (child) s.push(child);
      }
    }
    return res;
  }
};
