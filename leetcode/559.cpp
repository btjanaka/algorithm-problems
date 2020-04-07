// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 559
// Title: Maximum Depth of N-aray Tree
// Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Idea: Use recursion to find the depth.
// Difficulty: easy
// Tags: trees, recursion
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
  int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    int max_child = 0;
    for (int i = 0; i < root->children.size(); ++i) {
      max_child = max(max_child, maxDepth(root->children[i]));
    }
    return 1 + max_child;
  }
};
