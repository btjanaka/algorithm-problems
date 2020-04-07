// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 101
// Title: Symmetric Tree
// Link: https://leetcode.com/problems/symmetric-tree
// Idea: The recursion is a bit tricky, as you have to recur over two nodes at
// a time. But when you have two nodes, one on the left, and one on the right,
// check that left->left mirrors right->right, and left->right mirrors
// right->left.
// Difficulty: medium
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
  bool mirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr ^ right == nullptr) return false;
    if (left == nullptr & right == nullptr) return true;
    return left->val == right->val && mirror(left->left, right->right) &&
           mirror(left->right, right->left);
  }

  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return mirror(root->left, root->right);
  }
};
