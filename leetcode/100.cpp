// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 100
// Title: Same Tree
// Link: https://leetcode.com/problems/same-tree
// Idea: Use recursion.
// Difficulty: easy
// Tags: binary-tree
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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr ^ q == nullptr) return false;
    if (p == nullptr & q == nullptr) return true;
    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }
};
