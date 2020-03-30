// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) is-binary-search-tree
// Title: Is this a Binar Search Tree?
// Link: https://www.hackerrank.com/challenges/is-binary-search-tree/problem
// Idea: Recursively check each node.
// Difficulty: easy
// Tags: binary-search-tree
#include <climits>

bool f(Node* cur, int mn, int mx) {
  if (cur == nullptr) return true;
  if (cur->data < mx && cur->data > mn) {
    return f(cur->left, mn, cur->data) && f(cur->right, cur->data, mx);
  }
  return false;
}
bool checkBST(Node* root) { return f(root, INT_MIN, INT_MAX); }
