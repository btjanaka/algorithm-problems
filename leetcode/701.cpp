// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 701
// Title: Insert into a Binary Search Tree
// Link: https://leetcode.com/problems/insert-into-a-binary-search-tree
// Idea:
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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (val < root->val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }
    return root;
  }
};
