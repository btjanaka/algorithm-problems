// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 700
// Title: Search in a Binary Search Tree
// Link: https://leetcode.com/problems/search-in-a-binary-search-tree
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
  TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr) return root;
    if (root->val == val) return root;
    if (val > root->val) return searchBST(root->right, val);
    return searchBST(root->left, val);
  }
};
