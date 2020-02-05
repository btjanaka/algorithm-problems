// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 572
// Title: Subtree of Another Tree
// Link: https://leetcode.com/problems/subtree-of-another-tree/
// Idea: Recursively check all subtrees of s to see if they match t.
// Difficulty: easy
// Tags: tree, binary-tree, recursion
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  // Checks if two trees are equal.
  bool equal(TreeNode* s, TreeNode* t) {
    if (s == NULL) return t == NULL;
    if (t == NULL) return false;
    return s->val == t->val && equal(s->left, t->left) &&
           equal(s->right, t->right);
  }

  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (s == NULL) return t == NULL;
    if (t == NULL) return true;
    return equal(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};
